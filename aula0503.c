/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Programa de testes para a função MultiplicarMatrizes
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

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <float.h>
#include "cores.h"
#include "aula0501.h"

#define SUCESSO                                 0
#define NUMERO_ARGUMENTOS_INVALIDO              1
#define ARGUMENTO_INVALIDO                      2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO     3
#define VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO    4
#define BASE_INVALIDA                           5

#define NUMERO_ARGUMENTOS_MINIMOS               5
#define EOS                                     '\0'

int
main (int argc, char *argv[]) 
{
  if (argc < NUMERO_ARGUMENTOS_MINIMOS)
  {
    printf("\n%s%sNumero de argumentos invalido, forneca pelo menos 6 argumentos.%s\n\n", RED, WHITE_BACKGROUND, RESET);
    exit(NUMERO_ARGUMENTOS_INVALIDO);
  }

  char *verificacao;
  us numeroLinhas1, numeroColunas1, numeroLinhas2, numeroColunas2;

  errno = 0;
  numeroLinhas1 = (us) strtoul(argv[1], &verificacao, 10);

  if (errno == EINVAL || *verificacao != EOS)
	{
		printf ("\n%s%sBase invalida%s\n\n", RED, WHITE_BACKGROUND, RESET);
		exit (BASE_INVALIDA);
	}
	
	if (errno == ERANGE)
	{	
		printf ("%s%s\nValor fornecido ultrapassa o valor maximo permitido (%lu)%s\n\n", RED, WHITE_BACKGROUND, ULONG_MAX, RESET);
		exit (VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO);
	}

  errno = 0;
  numeroLinhas2 = (us) strtoul(argv[3], &verificacao, 10);

  if (errno == EINVAL || *verificacao != EOS)
	{
		printf ("\n%s%sBase invalida%s\n\n", RED, WHITE_BACKGROUND, RESET);
		exit (BASE_INVALIDA);
	}
	
	if (errno == ERANGE)
	{	
		printf ("%s%s\nValor fornecido ultrapassa o valor maximo permitido (%lu)%s\n\n", RED, WHITE_BACKGROUND, ULONG_MAX, RESET);
		exit (VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO);
	}

  errno = 0;
  numeroColunas1 = (us) strtoul(argv[2], &verificacao, 10);

  if (errno == EINVAL || *verificacao != EOS)
  {
    printf ("\n%s%sBase invalida%s\n\n", RED, WHITE_BACKGROUND, RESET);
    exit (BASE_INVALIDA);
  }

  if (errno == ERANGE)
  {	
    printf ("%s%s\nValor fornecido ultrapassa o valor maximo permitido (%lu)%s\n\n", RED, WHITE_BACKGROUND, ULONG_MAX, RESET);
    exit (VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO);
  }

  errno = 0;
  numeroColunas2 = (us) strtoul(argv[4], &verificacao, 10);

  if (errno == EINVAL || *verificacao != EOS)
  {
    printf ("\n%s%sBase invalida%s\n\n", RED, WHITE_BACKGROUND, RESET);
    exit (BASE_INVALIDA);
  }

  if (errno == ERANGE)
  {	
    printf ("%s%s\nValor fornecido ultrapassa o valor maximo permitido (%lu)%s\n\n", RED, WHITE_BACKGROUND, ULONG_MAX, RESET);
    exit (VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO);
  }

  if (numeroLinhas1 <= 0 || numeroLinhas1 > NUMERO_MAXIMO_LINHAS || numeroLinhas2 <= 0 || numeroLinhas2 > NUMERO_MAXIMO_LINHAS)
  {
    printf("\n%s%sNumero de linhas invalido.%s\n\n", RED, WHITE_BACKGROUND, RESET);
    exit(ARGUMENTO_INVALIDO);
  }

  if (numeroColunas1 <= 0 || numeroColunas1 > NUMERO_MAXIMO_COLUNAS || numeroColunas2 <= 0 || numeroColunas2 > NUMERO_MAXIMO_COLUNAS)
  {
    printf("\n%s%sNumero de colunas invalido.%s\n\n", RED, WHITE_BACKGROUND, RESET);
    exit(ARGUMENTO_INVALIDO);
  }
  
  if (argc != NUMERO_ARGUMENTOS_MINIMOS + numeroLinhas1 * numeroColunas1 + numeroLinhas2 * numeroColunas2)
  {
    printf("\n%s%sNumero de argumentos invalido, forneca %d valores para a matriz.%s\n\n", RED, WHITE_BACKGROUND, numeroLinhas1 * numeroColunas1 + numeroLinhas2 * numeroColunas2, RESET);
    exit(NUMERO_ARGUMENTOS_INVALIDO);
  }

  long double matriz1[numeroLinhas1][numeroColunas1];
  long double matriz2[numeroLinhas2][numeroColunas2];
  long double matrizProduto[numeroLinhas1][numeroColunas2];

  us linha, coluna;
  int index = NUMERO_ARGUMENTOS_MINIMOS;

  for (linha = 0; linha < numeroLinhas1; linha++)
  {
    for (coluna = 0; coluna < numeroColunas1; coluna++)
    {
      matriz1[linha][coluna] = strtold(argv[index++], &verificacao);
    }
  }
  for (linha = 0; linha < numeroLinhas2; linha++)
  {
    for (coluna = 0; coluna < numeroColunas2; coluna++)
    {
      matriz2[linha][coluna] = strtold(argv[index++], &verificacao);
    }
  }
  
  ExibirMatriz(numeroLinhas1, numeroColunas1, matriz1);
  printf("\n    x   \n");
  ExibirMatriz(numeroLinhas2, numeroColunas2, matriz2);
  printf("\n    =   \n");

  tipoErros resultado = MultiplicarMatrizes(numeroLinhas1, numeroColunas1, numeroLinhas2, numeroColunas2, matriz1, matriz2, matrizProduto);

  if (resultado != ok)
  {
    printf("\n%s%sErro ao multiplicar as matrizes.%s\n\n", RED, WHITE_BACKGROUND, RESET);
    exit(ARGUMENTO_INVALIDO);
  }

  return SUCESSO;
}

/* $RCSfile$ */
