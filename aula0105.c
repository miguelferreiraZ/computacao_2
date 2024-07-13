/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Recebe uma, ou varias, strings do usuario e retorna ela 
 * centralizada no terminal.
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cores.h"
#include "aula0101.h"

#define MAXIMO_CARACTERES_EXCEDIDO          1 
#define LARGURA_TERMINAL                  100

int
main(int argc, char *argv[]) {

  us larguraTexto = 0;
  us args;
  us caract;

  for (args = 1; args < argc; args++)
  {
    for (caract = 0; caract < strlen(argv[args]); caract++)
    {
      if (argv[args][caract] != ' ')
      {
        larguraTexto++;
      }
    }
  }

  if (larguraTexto > 50) 
  {
    printf("Erro: O comprimento total dos argumentos excede 50 caracteres.\n");
    return MAXIMO_CARACTERES_EXCEDIDO; 
  }

  printf("\n");
  ExibirCabecalho(LARGURA_TERMINAL);
  printf("\n");

  us iteraArgumento;
  us iteraCaractere;
  us espacosVazios = (LARGURA_TERMINAL - larguraTexto) / 2;
  us centraliza;

  for (centraliza = 0; centraliza < espacosVazios; centraliza++)
  {
    printf(" ");
  }
  printf("%s\"%s", UNDERLINE_RED, RESET);

  // Itera sobre todos os argumentos passados ao programa
  for (iteraArgumento = 1; iteraArgumento < argc; iteraArgumento++) 
  {
    char *arg = argv[iteraArgumento]; // Pega o próximo argumento
        // Itera sobre cada caractere do argumento
    for (iteraCaractere = 0; arg[iteraCaractere] != '\0'; iteraCaractere++) 
    {
            // Se o caractere não for um dígito ou um espaco, imprime-o
      if (!isdigit(arg[iteraCaractere]) && !isspace(arg[iteraCaractere]) && arg[iteraCaractere] != '\'' && arg[iteraCaractere] != '"') 
      {
        printf("%s%c", UNDERLINE_RED, arg[iteraCaractere]);
      }
    }
        // Imprime um espaço após cada argumento, exceto o último
    if (iteraArgumento < argc - 1) 
    {
      printf(" ");
    } else{
      printf("%s\"%s", UNDERLINE_RED, RESET);
    }
  }

  printf("\n\n");
  ExibirHifens(LARGURA_TERMINAL);
  printf("\n\n");
  return 0;
}


/* $RCSfiles$ */