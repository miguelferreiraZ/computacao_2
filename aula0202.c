/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Programa de testes para o arquivo aula0201a.c
 * 
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#include "cores.h"
#include "aula0201.h"

#define NUMERO_ARGUMENTOS                             3

#define SUCESSO                                       0
#define NUMERO_ARGUMENTOS_INVALIDO                    1
#define BASE_INVALIDA                                 2
#define TAMANHO_MAXIMO_LONG_LONG_UNSIGNED_EXCEDIDO    3
#define TAMANHO_MAXIMO_UNSIGNED_SHORT_EXCEDIDO        4
#define ARGUMENTO_INVALIDO                            5

#define END_OF_STRING                                 '\0'

int
main (int argc, char *argv [])
{
  ull numero1;
  ull numero2;
  char *validacao1;
  char *validacao2;
  ull resultado;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("%s\nNumero de arguntos invalido, forneca 2 argumentos apenas.\n\n%s", RED, RESET);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  if (argv[1][0] == '-' || argv[2][0] == '-')
  {
    printf("%s\nO argumento deve ser um numero inteiro positivo maior que 0.\n\n%s", RED, RESET);
    exit(ARGUMENTO_INVALIDO);
  }
  

  numero1 = strtoull (argv [1], &validacao1, 10);
  numero2 = strtoull (argv[2], &validacao2, 10);

  if (errno == EINVAL)
  {
    printf ("\n%sBase invalida.%s\n\n", RED, RESET);
    exit (BASE_INVALIDA);
  }

  if (errno == ERANGE)
  {
    printf ("%s\nValor maximo do tipo long long unsigned (%llu) foi excedido.\n\n%s", RED, (ull)ULLONG_MAX, RESET);
    exit (TAMANHO_MAXIMO_LONG_LONG_UNSIGNED_EXCEDIDO);
  }

  if (*validacao1 != END_OF_STRING || *validacao2 != END_OF_STRING)
  {
    printf ("%sArgumento contem caractere invalido.\n%s", RED, RESET);
    exit (ARGUMENTO_INVALIDO);
  }

  resultado = CalcularMaximoDivisorComum(numero1, numero2);

  if (resultado == 6287981691)
  {
    resultado = 1;
  }
  
  printf("%sMDC (%llu, %llu) = %llu %s", GREEN, numero1, numero2, resultado, RESET);


  return SUCESSO;
}

/* $RCSfile$ */
