/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Funcao para ObterCodigoAnsiCor, Gerar pixels e mostrar monitor.
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
ObterCodigoAnsiCor(char *nomeCor, tipoFundoTexto fundoTexto)
{
  if (nomeCor == NULL)
  {
    if (fundoTexto == fundo)
    {
      return BLACK_BACKGROUND;
    }
    else
    {
      return WHITE;
    }
  }

  if (fundoTexto == fundo)
  {
    if (strcmp(nomeCor, "preto") == 0)
    {
      return BLACK_BACKGROUND;
    }
    else if (strcmp(nomeCor, "vermelho") == 0)
    {
      return RED_BACKGROUND;
    }
    else if (strcmp(nomeCor, "verde") == 0)
    {
      return GREEN_BACKGROUND;
    }
    else if (strcmp(nomeCor, "amarelo") == 0)
    {
      return YELLOW_BACKGROUND;
    }
    else if (strcmp(nomeCor, "azul") == 0)
    {
      return BLUE_BACKGROUND;
    }
    else if (strcmp(nomeCor, "magenta") == 0)
    {
      return MAGENTA_BACKGROUND;
    }
    else if (strcmp(nomeCor, "ciano") == 0)
    {
      return CYAN_BACKGROUND;
    }
    else if (strcmp(nomeCor, "branco") == 0)
    {
      return WHITE_BACKGROUND;
    }
    else
    {
      return BLACK_BACKGROUND;
    }
  }
  else
  {
    if (strcmp(nomeCor, "preto") == 0)
    {
      return BLACK;
    }
    else if (strcmp(nomeCor, "vermelho") == 0)
    {
      return RED;
    }
    else if (strcmp(nomeCor, "verde") == 0)
    {
      return GREEN;
    }
    else if (strcmp(nomeCor, "amarelo") == 0)
    {
      return YELLOW;
    }
    else if (strcmp(nomeCor, "azul") == 0)
    {
      return BLUE;
    }
    else if (strcmp(nomeCor, "magenta") == 0)
    {
      return MAGENTA;
    }
    else if (strcmp(nomeCor, "ciano") == 0)
    {
      return CYAN;
    }
    else if (strcmp(nomeCor, "branco") == 0)
    {
      return WHITE;
    }
    else
    {
      return WHITE;
    }
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

  if (tempoEspera < 0)
  {
    return erroTempoCongelamento;
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
    printf("%s", ObterCodigoAnsiCor(corFundo, fundo)); /* COR FUNDO */
    for (coluna = 0; coluna < numeroColunas; coluna++)
    {
      if (monitor[linha][coluna] == apagado)
      {
        printf("%s%c", ObterCodigoAnsiCor(corPixelApagado, fundo), APAGADO);
      }
      else if (monitor[linha][coluna] == aceso)
      {
        printf("%s%c", ObterCodigoAnsiCor(corPixelAceso, fundo), ACESO);
      }
      else if (monitor[linha][coluna] == defeituoso)
      {
        printf("%s%s%c", ObterCodigoAnsiCor(corPixelDefeituoso, texto), ObterCodigoAnsiCor(corFundo, fundo), DEFEITUOSO);
      }
      else
      {
        return erroNumeroVertices;
      }
    }
    printf("%s", RESET); /* RESETA COR FUNDO */
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
  
  unsigned linha, coluna;
  unsigned short numeroDefeituosos = (unsigned short)(numeroLinhas * numeroColunas * (percentualDefeituosos / 100));
  unsigned short numeroApagados = (unsigned short)(numeroLinhas * numeroColunas * (percentualApagados / 100));
  srand(time(NULL));

  if (numeroApagados + numeroDefeituosos > numeroLinhas * numeroColunas)
  {
    return erroNumeroPercentual;
  }
  
  /* Inicializando o monitor com pixels acesos */
  for (linha = 0; linha < numeroLinhas; linha++)
  {
    for (coluna = 0; coluna < numeroColunas; coluna++)
    {
      monitor[linha][coluna] = aceso;
    }
  }

  /* Colocando pixels defeituosos aleatorios */
  while (numeroDefeituosos > 0)
  {
    unsigned linhaAleatoria = (rand() % numeroLinhas); /* de 1 ate numeroLinhas */
    unsigned colunaAleatoria = (rand() % numeroColunas);

    if (monitor[linhaAleatoria][colunaAleatoria] != defeituoso)
    {
      monitor[linhaAleatoria][colunaAleatoria] = defeituoso;
      numeroDefeituosos--;
    }
  }

  /* Colocando pixels apagados aleatorios */
  while (numeroApagados > 0)
  {
    unsigned linhaAleatoria = (rand() % numeroLinhas); /* de 1 ate numeroLinhas */
    unsigned colunaAleatoria = (rand() % numeroColunas);

    if (monitor[linhaAleatoria][colunaAleatoria] != defeituoso && monitor[linhaAleatoria][colunaAleatoria] != apagado)
    {
      monitor[linhaAleatoria][colunaAleatoria] = apagado;
      numeroApagados--;
    }
  }
  
  return ok;
  
}

tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS_MONITOR][NUMERO_MAXIMO_COLUNAS_MONITOR], unsigned numeroLinhas, unsigned numeroColunas, char *corFundo, char *corPixelApagado, char *corPixelAceso, char *corPixelDefeituoso)
{
  if (numeroLinhas > NUMERO_MAXIMO_LINHAS_MONITOR || numeroLinhas <= 0)
  {
    return erroNumeroLinhas;
  }

  if (numeroColunas > NUMERO_MAXIMO_COLUNAS_MONITOR || numeroColunas <= 0)
  {
    return erroNumeroColunas;
  }

  unsigned linha, coluna;

  for (linha = 0; linha < numeroLinhas; linha++)
  {
    for (coluna = 0; coluna < numeroColunas; coluna++)
    {
      if (monitor[linha][coluna] == aceso)
      {
        monitor[linha][coluna] = apagado;
      }
    }
  }

  return ok;
}

/* $RCSfile$ */