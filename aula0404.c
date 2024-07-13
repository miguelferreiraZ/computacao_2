/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Programa de testes para as funcoes de serie harmonica alternada
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
#define VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO			5
#define VALOR_MAXIMO_FLOAT_EXCEDIDO								6

#define NUMERO_ARGUMENTOS													2
#define EOS																				'\0'

int
main (int argc, char *argv []) 
{

	char *verificacao;
	
	float percentual;
	float resultadoAtual;
	float resultadoAnterior;
	us numero;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\n%s%sNumero de argumentos invalido, forneca apenas 2.%s\n\n", RED, WHITE_BACKGROUND, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	errno = 0;
	percentual = strtof (argv [1], &verificacao);

	if (errno == EINVAL || *verificacao != EOS)
	{
		printf ("\n%s%sBase invalida%s\n\n", RED, WHITE_BACKGROUND, RESET);
		exit (BASE_INVALIDA);
	}
	
	if (errno == ERANGE)
	{	
		printf ("%s%s\nValor fornecido ultrapassa o valor maximo permitido para unsigned short (%i)%s\n\n", RED, WHITE_BACKGROUND, USHRT_MAX, RESET);
		exit (VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO);
	}

	if (percentual < 0.0 || percentual > 1.0)
	{
		printf ("\n%s%sO numero fornecido deve ser um float entre 0 e 1.%s\n\n", RED, WHITE_BACKGROUND, RESET);
		exit (ARGUMENTO_INVALIDO);
	}

	printf ("\n");

	numero = 0;
	resultadoAtual = 0.0;
	resultadoAnterior = 0.0;

	do
	{
		resultadoAnterior = resultadoAtual;
		resultadoAtual = CalcularSerieHarmonicaAlternada(numero);
		if (numero % 2 == 0)
		{
			printf ("%s%sS(%d): %.10f%s\n", BLACK, WHITE_BACKGROUND, numero, resultadoAtual, RESET);
		}
		else
		{
			printf ("%s%sS(%d): %.10f%s\n", WHITE, BLACK_BACKGROUND, numero, resultadoAtual, RESET);
		}
		numero++;
	} while ((float)fabs((double)(resultadoAtual - resultadoAnterior)) >= percentual * (float)fabs((double)resultadoAnterior));

	printf ("\n");

	return SUCESSO;

}


/* $RCSfile$ */