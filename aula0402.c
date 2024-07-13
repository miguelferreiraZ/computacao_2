/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Programa de testes para as funcoes de exponencial
 * 
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif 

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE				  1999
#define __LONG_LONG_SUPPORTED
#endif  

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <errno.h>
#include <float.h>

#include "aula0401.h"
#include "cores.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define ARGUMENTO_INVALIDO												2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO				3
#define BASE_INVALIDA															4
#define VALOR_MAXIMO_LONG_DOUBLE_EXCEDIDO					5
#define VALOR_MAXIMO_LONG_EXCEDIDO								6
#define VALOR_MAXIMO_LONG_LONG_EXCEDIDO						7

#define NUMERO_ARGUMENTOS													3
#define EOS																				'\0'

int
main (int argc, char *argv []) 
{

	char *verificacao1;
	char *verificacao2;
	
	long double numeroDouble;
	int expoenteInt;
	long double resultado;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\n%s%sNumero de argumentos invalido, forneca apenas 2.%s\n\n", RED, WHITE_BACKGROUND, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	errno = 0;
	numeroDouble = strtod (argv [1], &verificacao1);

	if (errno == EINVAL || *verificacao1 != EOS)
	{
		printf ("\n%s%sBase invalida%s\n\n", RED, WHITE_BACKGROUND, RESET);
		exit (BASE_INVALIDA);
	}
	
	if (errno == ERANGE)
	{	
		printf ("%s%s\nValor fornecido ultrapassa o valor maximo permitido para Long Double no primeiro argumento (%Lg)%s\n\n", RED, WHITE_BACKGROUND, LDBL_MAX, RESET);
		exit (VALOR_MAXIMO_LONG_DOUBLE_EXCEDIDO);
	}

	errno = 0;
	expoenteInt = strtol (argv [2], &verificacao2, 10);

	if (errno == EINVAL || *verificacao2 != EOS)
	{
		printf ("\n%s%sExpoente invalido%s\n\n", RED, WHITE_BACKGROUND, RESET);
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE)
	{	
		printf ("%s%s\nValor fornecido ultrapassa o valor maximo permitido para Long no segundo argumento (%ld)%s\n\n", RED, WHITE_BACKGROUND, LONG_MAX, RESET);
		exit (VALOR_MAXIMO_LONG_EXCEDIDO);
	}

	if (expoenteInt > log(LDBL_MAX) / log(numeroDouble))
	{
		printf ("\n%s%s\nValor fornecido ultrapassa o valor maximo permitido para Long Double%s\n\n", RED, WHITE_BACKGROUND, RESET);
		exit (VALOR_MAXIMO_LONG_DOUBLE_EXCEDIDO);
	}

	printf ("\n");

	resultado = CalcularExponencial(numeroDouble, expoenteInt);

	if (resultado > LDBL_MAX)
	{
    printf("%s%sO resultado ultrapassa o valor maximo permitido para long double (%Lg).%s\n", RED, WHITE_BACKGROUND, LDBL_MAX, RESET);
    exit(VALOR_MAXIMO_LONG_DOUBLE_EXCEDIDO);
	}

  printf ("%s%s%s ^ %s:%s%s%s %Lg%s", YELLOW, BLUE_BACKGROUND, argv[1], argv[2], RESET, RED, WHITE_BACKGROUND, resultado, RESET);

	printf ("\n");

	return SUCESSO;

}


/* $RCSfile$ */