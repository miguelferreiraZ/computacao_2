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

tipoErros 
DesenharReta(tipoPixel monitor[NUMERO_MAXIMO_LINHAS_MONITOR][NUMERO_MAXIMO_COLUNAS_MONITOR], unsigned numeroLinhas, unsigned numeroColunas, unsigned linhaA, unsigned colunaA, unsigned linhaB, unsigned colunaB, char *corFundo, char *corPixelApagado, char *corPixelAceso, char *corPixelDefeituoso)
{
  if (numeroLinhas > NUMERO_MAXIMO_LINHAS_MONITOR || numeroLinhas <= 0)
    return erroNumeroLinhas;

  if (numeroColunas > NUMERO_MAXIMO_COLUNAS_MONITOR || numeroColunas <= 0)
    return erroNumeroColunas;

  if (linhaA >= numeroLinhas || linhaB >= numeroLinhas)
    return linhaUltrapassaLimites;

  if (colunaA >= numeroColunas || colunaB >= numeroColunas)
    return colunaUltrapassaLimites;

  int deltaX = abs(colunaB - colunaA), direcaoX = colunaA < colunaB ? 1 : -1;
  int deltaY = -abs(linhaB - linhaA), direcaoY = linhaA < linhaB ? 1 : -1; 
  int err = deltaX + deltaY, errDobro;
    
  while (1) 
  {
    if (linhaA >= 0 && linhaA < numeroLinhas && colunaA >= 0 && colunaA < numeroColunas) 
    {
      if (monitor[linhaA][colunaA] == defeituoso)
        return erroPixelDefeituosoNoCaminho;
      else
        monitor[linhaA][colunaA] = aceso;
    }

    if (linhaA == linhaB && colunaA == colunaB) 
      break;

    errDobro = 2 * err;

    if (errDobro >= deltaY) 
    {
      if (colunaA == colunaB) break;
        err += deltaY;
        colunaA += direcaoX;
    }

    if (errDobro <= deltaX) 
    {
      if (linhaA == linhaB) 
        break;
      err += deltaX;
      linhaA += direcaoY;
    }
  }

  return ok;
}

tipoErros
DesenharPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS_MONITOR][NUMERO_MAXIMO_COLUNAS_MONITOR], unsigned numeroLinhas, unsigned numeroColunas, unsigned numeroVertices, unsigned linhasVertices [NUMERO_MAXIMO_VERTICES], unsigned colunasVertices [NUMERO_MAXIMO_VERTICES], char *corFundo, char *corPixelApagado, char *corPixelAceso, char *corPixelDefeituoso)
{
  if (numeroLinhas > NUMERO_MAXIMO_LINHAS_MONITOR || numeroLinhas <= 0)
    return erroNumeroLinhas;

  if (numeroColunas > NUMERO_MAXIMO_COLUNAS_MONITOR || numeroColunas <= 0)
    return erroNumeroColunas;

  if (numeroVertices < 3 || numeroVertices > NUMERO_MAXIMO_VERTICES)
    return erroNumeroVertices;

  unsigned short indice;
  tipoErros resultado;

  for (indice = 0; indice < numeroVertices - 1; indice++)
  {
    resultado = DesenharReta(monitor, numeroLinhas, numeroColunas, linhasVertices[indice], colunasVertices[indice], linhasVertices[indice + 1], colunasVertices[indice + 1], corFundo, corPixelApagado, corPixelAceso, corPixelDefeituoso);
    if (resultado != ok)
      return resultado;
  }

  resultado = DesenharReta(monitor, numeroLinhas, numeroColunas, linhasVertices[numeroVertices - 1], colunasVertices[numeroVertices - 1], linhasVertices[0], colunasVertices[0], corFundo, corPixelApagado, corPixelAceso, corPixelDefeituoso);
  if (resultado != ok)
    return resultado;

  return ok;
}

/* $RCSfile$ */