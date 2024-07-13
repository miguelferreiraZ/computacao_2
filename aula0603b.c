/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Programa de testes para a função ValidarRg que utiliza agora 
 * uma string em formato: XX.XXX.XXX como entrada
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
#include <string.h>
#include <limits.h>
#include "aula0601.h"
#include "cores.h"

#define SUCESSO                                                               0
#define NUMERO_ARGUMENTOS_INVALIDO                                            1
#define BASE_INVALIDA                                                         2
#define VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO                                   3
#define NUMERO_ARGUMENTOS                                                     2
#define EOS                                                                 '\0'

int
main(int argc, char *argv[])
{
  us index = 0, digitosIndex = 0;
  char *verificacao;
  long numero;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf("%s%sErro: Numero de argumentos invalido.%s\n", RED, WHITE_BACKGROUND, RESET);
    printf("%s%sUso: %s <1 argumento (9 caracteres): XX.XXX.XXX-X>%s\n", RED, WHITE_BACKGROUND, argv[0], RESET);
    exit(NUMERO_ARGUMENTOS_INVALIDO);
  }

  if (strlen(argv[1]) != 12)
  {
    printf("%s%sErro: Apenas 9 caracteres (sem contar os pontos e traco) sao permitidos.%s\n", RED, WHITE_BACKGROUND, RESET);
    exit(NUMERO_ARGUMENTOS_INVALIDO);
  }

  byte digitos[NUMERO_MAXIMO_ENTRADA + 2];

  while (argv[1][index] != EOS)
  {
    if (argv[1][index] == '.' || argv[1][index] == '-')
    {
      index++;
      continue;
    }

    errno = 0;
    char str[2] = { argv[1][index], '\0' };   /* cria uma string de um unico caractere, para poder manipular no strtol  */
    numero = strtol(str, &verificacao, 10);

    if (errno == EINVAL || *verificacao != EOS)
	  {
		  printf ("\n%s%sBase invalida no caracter (%hu) da string%s\n\n", RED, WHITE_BACKGROUND, digitosIndex + 1, RESET);
		  exit (BASE_INVALIDA);
	  }

    digitos[digitosIndex] = (byte) numero;
    digitosIndex++;
    index++;
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