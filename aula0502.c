/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Programa de testes para a função ExibirMatriz
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

#define NUMERO_ARGUMENTOS_MINIMOS               3
#define EOS                                     '\0'

int
main (int argc, char *argv[]) 
{
  if (argc < NUMERO_ARGUMENTOS_MINIMOS)
  {
    printf("\n%s%sNumero de argumentos invalido, forneca pelo menos 3 argumentos.%s\n\n", RED, WHITE_BACKGROUND, RESET);
    exit(NUMERO_ARGUMENTOS_INVALIDO);
  }

  char *verificacao;
  us numeroLinhas, numeroColunas, nLinhas, nColunas;

  numeroLinhas = strtoul(argv[1], &verificacao, 10);

  errno = 0;
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

  if (numeroLinhas <= 0 || numeroLinhas > NUMERO_MAXIMO_LINHAS)
  {
    printf("\n%s%sNumero de linhas invalido.%s\n\n", RED, WHITE_BACKGROUND, RESET);
    exit(ARGUMENTO_INVALIDO);
  }


  numeroColunas = (unsigned short) strtoul(argv[2], &verificacao, 10);

  errno = 0;
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

  if (numeroColunas <= 0 || numeroColunas > NUMERO_MAXIMO_COLUNAS)
  {
    printf("\n%s%sNumero de colunas invalido.%s\n\n", RED, WHITE_BACKGROUND, RESET);
    exit(ARGUMENTO_INVALIDO);
  }

  if (argc != NUMERO_ARGUMENTOS_MINIMOS + numeroLinhas * numeroColunas)
  {
    printf("\n%s%sNumero de argumentos invalido, forneca %d valores para a matriz.%s\n\n", RED, WHITE_BACKGROUND, numeroLinhas * numeroColunas, RESET);
    exit(NUMERO_ARGUMENTOS_INVALIDO);
  }

  nLinhas = (unsigned short) numeroLinhas;
  nColunas = (unsigned short) numeroColunas;

  long double matriz[nLinhas][nColunas];

  unsigned linha, coluna;

  for (linha = 0; linha < nLinhas; linha++)
  {
    for (coluna = 0; coluna < nColunas; coluna++)
    {
      matriz[linha][coluna] = strtof(argv[linha * nColunas + coluna + NUMERO_ARGUMENTOS_MINIMOS], &verificacao);
    }
  }

  ExibirMatriz(nLinhas, nColunas, matriz);

  return SUCESSO;
}

/* $RCSfile$ */
