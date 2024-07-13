/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Programa de testes para as funcoes de fibonacci
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

#include "aula0301.h"
#include "cores.h"

#define SUCESSO																		0

#define NUMERO_ARGUMENTOS_INVALIDO								1
#define ARGUMENTO_INVALIDO												2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO				3
#define BASE_INVALIDA															4
#define VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO				5
#define VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO			6
#define VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO  7

#define NUMERO_ARGUMENTOS													2
#define EOS																				'\0'

int
main (int argc, char *argv []) 
{

	char *verificacao;

	us numero;	
	ull numeroLongo;

	ull resultado = 0;
	ull resultadoAnterior = 0;
	
	us indice;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\n%s%sUso: %s <inteiro-nao-negativo>\n\n%s", WHITE_BACKGROUND, RED, argv [0], RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (argv [1][0] == '-')
	{
		printf ("\n%s%sEste programa nao aceita numeros negativos.\n\n%s", WHITE_BACKGROUND, RED, RESET);
		exit (ARGUMENTO_INVALIDO);
	}

	numeroLongo = strtoul (argv [1], &verificacao, 10);

	if (errno == EINVAL)
	{
		printf ("\n%s%sBase invalida\n\n%s", WHITE_BACKGROUND, RED, RESET);
		exit (BASE_INVALIDA);
	}
	
	if (errno == ERANGE)
	{	
		printf ("%s%s\nValor fornecido ultrapassa o valor maximo permitido para unsigned long (%lu)\n\n%s", WHITE_BACKGROUND, RED, ULONG_MAX, RESET);
		exit (VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO);
	}

	if (*verificacao != EOS)
	{
		printf ("\n%s%sArgumento contem caractere invalido.\n", WHITE_BACKGROUND, RED);
		printf ("Primeiro caractere invalido: \'%c\'\n\n%s", *verificacao, RESET);
		exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
	}
  
	if (numeroLongo > USHRT_MAX)
	{	
		printf ("\n%s%sValor fornecido ultrapassa o valor maximo permitido para unsigned short (%i)\n\n%s", WHITE_BACKGROUND, RED, USHRT_MAX, RESET);
		exit (VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO);
	}

	numero = (unsigned short) numeroLongo;

	printf ("\n");

	for (indice = 0; indice <= numero; indice++)
	{

		resultado = CalcularTermoSerieFibonacci (indice);		

		if (resultado < resultadoAnterior)
		{
			printf ("\n%s%sValor maximo do tipo long long unsigned foi excedido\n\n%s", WHITE_BACKGROUND, RED, RESET);
			exit (VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);	
		}

		printf ("F(%d) = %llu\n%s", indice, resultado, RESET);

		resultadoAnterior = resultado;
	
	}

	printf ("\n");

	return SUCESSO;

}

/* $RCSfile$ */