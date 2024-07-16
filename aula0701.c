/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Funcao para ObterCodigoAnsiCor
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#ifdef __linux__
#define _XOPEN_SOURCE 500
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "aula0701.h"
#include "cores.h"

char *
ObterCodigoAnsiCor(char * nomeCor, tipoFundoTexto fundoTexto)
{
  if (nomeCor == NULL)
  {
    return fundoTexto == fundo ? BLACK_BACKGROUND : WHITE;
  }

  if (fundoTexto == fundo) {
    return strcmp(nomeCor, "preto") == 0 ? BLACK_BACKGROUND :
           strcmp(nomeCor, "vermelho") == 0 ? RED_BACKGROUND :
           strcmp(nomeCor, "verde") == 0 ? GREEN_BACKGROUND :
           strcmp(nomeCor, "amarelo") == 0 ? YELLOW_BACKGROUND :
           strcmp(nomeCor, "azul") == 0 ? BLUE_BACKGROUND :
           strcmp(nomeCor, "magenta") == 0 ? MAGENTA_BACKGROUND :
           strcmp(nomeCor, "ciano") == 0 ? CYAN_BACKGROUND :
           strcmp(nomeCor, "branco") == 0 ? WHITE_BACKGROUND :
           BLACK_BACKGROUND; 
  } else {
    return strcmp(nomeCor, "preto") == 0 ? BLACK :
           strcmp(nomeCor, "vermelho") == 0 ? RED :
           strcmp(nomeCor, "verde") == 0 ? GREEN :
           strcmp(nomeCor, "amarelo") == 0 ? YELLOW :
           strcmp(nomeCor, "azul") == 0 ? BLUE :
           strcmp(nomeCor, "magenta") == 0 ? MAGENTA :
           strcmp(nomeCor, "ciano") == 0 ? CYAN :
           strcmp(nomeCor, "branco") == 0 ? WHITE :
           WHITE;
  }
}

tipoErros
MostrarMonitor(useconds_t tempoEspera, tipoPixel monitor[NUMERO_MAXIMO_LINHAS_MONITOR][NUMERO_MAXIMO_COLUNAS_MONITOR], unsigned numeroLinhas, unsigned numeroColunas, char *corFundo, char *corPixelApagado, char *corPixelAceso, char *corPixelDefeituoso)
{
  unsigned short linha, coluna, indice;
  unsigned nHifens = numeroColunas + 4;
  

  if (numeroLinhas > NUMERO_MAXIMO_LINHAS_MONITOR || numeroLinhas <= 0)
  {
    return erroNumeroLinhas;
  }

  if (numeroColunas > NUMERO_MAXIMO_COLUNAS_MONITOR || numeroColunas <= 0)
  {
    return erroNumeroColunas;
  }

  system("clear");
  printf("\n");

  for (indice = 0; indice < nHifens; indice++)
  {
    printf("-");
  }

  printf("\n");

  for (linha = 0; linha < numeroLinhas; linha++)
  {
    printf("| ");
    for (coluna = 0; coluna < numeroColunas; coluna++)
    {
      if (monitor[linha][coluna] == apagado)
      {
        printf("%s%c%s", corPixelApagado, APAGADO, RESET);
      }
      else if (monitor[linha][coluna] == aceso)
      {
        printf("%s%c%s", corPixelAceso, ACESO, RESET);
      }
      else if (monitor[linha][coluna] == defeituoso)
      {
        printf("%s%c%s", corPixelDefeituoso, DEFEITUOSO, RESET);
      }
      else
      {
        return erroNumeroVertices;
      }
    }
    printf(" |\n");
  }

  for (indice = 0; indice < nHifens; indice++)
  {
    printf("-");
  }

  printf("\n\n");
  usleep(tempoEspera);
  return ok;
}

tipoErros
GerarDistribuicaoInicial(tipoPixel monitor[NUMERO_MAXIMO_LINHAS_MONITOR][NUMERO_MAXIMO_COLUNAS_MONITOR], unsigned numeroLinhas, unsigned numeroColunas, float percentualDefeituosos, float percentualApagados)
{
  if (percentualApagados > 100 || percentualDefeituosos > 100 || percentualApagados < 0 || percentualDefeituosos < 0)
  {
    return erroNumeroPercentual;
  }

  if (numeroLinhas > NUMERO_MAXIMO_LINHAS_MONITOR || numeroLinhas <= 0)
  {
    return erroNumeroLinhas;
  }

  if (numeroColunas > NUMERO_MAXIMO_COLUNAS_MONITOR || numeroColunas <= 0)
  {
    return erroNumeroColunas;
  }
  
  unsigned linha, coluna, indice;
  unsigned short numeroDefeituosos = (unsigned short)(numeroLinhas * numeroColunas * (percentualDefeituosos / 100));
  unsigned short numeroApagados = (unsigned short)(numeroLinhas * numeroColunas * (percentualApagados / 100));
  srand(time(NULL));

  if (numeroApagados + numeroDefeituosos > numeroLinhas * numeroColunas)
  {
    return erroNumeroPercentual;
  }
  
  /* Inicializando o monitor com pixels acesos */
  for (linha = 1; linha < numeroLinhas + 1; linha++)
  {
    for (coluna = 1; coluna < numeroColunas + 1; coluna++)
    {
      monitor[linha][coluna] = aceso;
    }
  }

  /* Colocando pixels defeituosos aleatorios */
  while (numeroDefeituosos > 0)
  {
    unsigned linhaAleatoria = (rand() % numeroLinhas) + 1; /* de 1 ate numeroLinhas */
    unsigned colunaAleatoria = (rand() % numeroColunas) + 1;

    if (monitor[linhaAleatoria][colunaAleatoria] != defeituoso)
    {
      monitor[linhaAleatoria][colunaAleatoria] = defeituoso;
      numeroDefeituosos--;
    }
  }

  /* Colocando pixels apagados aleatorios */
  while (numeroApagados > 0)
  {
    unsigned linhaAleatoria = (rand() % numeroLinhas) + 1; /* de 1 ate numeroLinhas */
    unsigned colunaAleatoria = (rand() % numeroColunas) + 1;

    if (monitor[linhaAleatoria][colunaAleatoria] != defeituoso && monitor[linhaAleatoria][colunaAleatoria] != apagado)
    {
      monitor[linhaAleatoria][colunaAleatoria] = apagado;
      numeroApagados--;
    }
  }
  
  return ok;
  
}

/* $RCSfile$ */