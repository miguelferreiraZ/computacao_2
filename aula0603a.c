/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Programa de testes para a função ValidarRg
 * 
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "aula0601.h"
#include "cores.h"

#define SUCESSO                                                               0
#define NUMERO_ARGUMENTOS_INVALIDO                                            1
#define BASE_INVALIDA                                                         2
#define VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO                                   3
#define NUMERO_ARGUMENTOS                                                     10
#define EOS                                                                   '\0'

int
main(int argc, char *argv[])
{
  us index;
  char *verificacao;
  long caracter;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf("%s%sErro: Numero de argumentos invalido.%s\n", RED, WHITE_BACKGROUND, RESET);
    printf("%s%sUso: %s <9 digitos do RG>%s\n", RED, WHITE_BACKGROUND, argv[0], RESET);
    exit(NUMERO_ARGUMENTOS_INVALIDO);
  }

  byte digitos[NUMERO_ARGUMENTOS];

  for (index = 0; index < NUMERO_MAXIMO_ENTRADA + 1; index++)
  {
    errno = 0;
    caracter = strtol(argv[index + 1], &verificacao, 10);

    if (errno == EINVAL || *verificacao != EOS)
	  {
		  printf ("\n%s%sBase invalida no argumento (%hu)%s\n\n", RED, WHITE_BACKGROUND, index + 1, RESET);
		  exit (BASE_INVALIDA);
	  }
    if (errno == ERANGE)
	  {	
		  printf ("%s%s\nValor fornecido ultrapassa o valor maximo permitido para Long (%lu) no argumento (%hu)%s\n\n", RED, WHITE_BACKGROUND, LONG_MAX, index + 1, RESET);
		  exit (VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO);
	  }

    digitos[index] = (byte)caracter;
  }

  tipoErros resultadoValidacao = ValidarRg(digitos);

  if (resultadoValidacao == 3)
  {
    printf("RG: ");
    if (digitos[NUMERO_ARGUMENTOS-1] == 'X')
    {
      printf("%d%d.%d%d%d.%d%d%d-%c - invalido.\n", digitos[0], digitos[1], digitos[2], digitos[3], digitos[4], digitos[5], digitos[6], digitos[7], digitos[8]);
      return SUCESSO;
    }
    else
    {
      printf("%d%d.%d%d%d.%d%d%d-%d - invalido.\n", digitos[0], digitos[1], digitos[2], digitos[3], digitos[4], digitos[5], digitos[6], digitos[7], digitos[8]);
      return SUCESSO;
    }
  } 
  else if (resultadoValidacao == ok) 
  {
    printf("RG: ");
    if (digitos[NUMERO_ARGUMENTOS-1] == 'X')
    {
      printf("%d%d.%d%d%d.%d%d%d-%c - valido.\n", digitos[0], digitos[1], digitos[2], digitos[3], digitos[4], digitos[5], digitos[6], digitos[7], digitos[8]);
    }
    else
    {
      printf("%d%d.%d%d%d.%d%d%d-%d - valido.\n", digitos[0], digitos[1], digitos[2], digitos[3], digitos[4], digitos[5], digitos[6], digitos[7], digitos[8]);
    }
  }
  else
  {
    printf("%s%sErro ao gerar digito verificador:%s\n", RED, WHITE_BACKGROUND, RESET);
    printf("%s%scod.%d%s\n", RED, WHITE_BACKGROUND, resultadoValidacao, RESET);
    return resultadoValidacao;
  }

  return SUCESSO;
}

/* $RCSfile$ */