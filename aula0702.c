/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Programa de testes para a função MostrarMonitor, GerarDistribuicao
 * Inicial e ObterCodigoAnsiCor
 * 
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
#include <errno.h>
#include <limits.h>
#include <float.h>

#include "aula0701.h"
#include "cores.h"

#define SUCESSO                                                               0
#define NUMERO_ARGUMENTOS_INVALIDO                                            1
#define BASE_INVALIDA                                                         2
#define VALOR_MAXIMO_INT_EXCEDIDO                                             3
#define VALOR_MAXIMO_DOUBLE_EXCEDIDO                                          4
#define NUMERO_MAXIMO_LINHAS_EXCEDIDO                                         5
#define NUMERO_MAXIMO_COLUNAS_EXCEDIDO                                        6
#define ERRO_EXIBICAO                                                         7

#define NUMERO_ARGUMENTOS                                                    10
#define EOS                                                                '\0'

int
main(int argc, char *argv[])
{
  if (argc != NUMERO_ARGUMENTOS)
  {
    printf("%s%sErro: Numero de argumentos invalido.%s\n", RED, WHITE_BACKGROUND, RESET);
    printf("%s%sUso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados> <cor-fundo> <cor-apagado> <cor-aceso> <cor-defeituoso>%s\n", RED, WHITE_BACKGROUND, argv[0], RESET);
    exit(NUMERO_ARGUMENTOS_INVALIDO);
  }

  char *verificacao, *corFundo, *corApagado, *corAceso, *corDefeituoso;
  unsigned tempoCongelamento, qtdLinhas, qtdColunas, argumentoInt;
  unsigned short index;
  float percentDefeituosos, percentApagados, argumentoFloat;
  tipoPixel monitor[NUMERO_MAXIMO_LINHAS_MONITOR][NUMERO_MAXIMO_COLUNAS_MONITOR];
  tipoErros resultado, resultadoDistribuicaoInicial;

  for (index = 1; index < NUMERO_ARGUMENTOS; index++)
  {
    errno = 0;

    if (index < 4)
    {
      argumentoInt = strtoul(argv[index], &verificacao, 10);

      if (errno == EINVAL || *verificacao != EOS)
      {
        printf ("\n%s%sBase invalida no argumento (%hu)%s\n\n", RED, WHITE_BACKGROUND, index + 1, RESET);
        exit (BASE_INVALIDA);
      }
      if (errno == ERANGE)
      {	
        printf ("%s%s\nValor fornecido ultrapassa o valor maximo permitido para int (%i) no argumento (%hu)%s\n\n", RED, WHITE_BACKGROUND, INT_MAX, index + 1, RESET);
        exit (VALOR_MAXIMO_INT_EXCEDIDO);
      }
      
      if (index == 1)
				tempoCongelamento = argumentoInt;
			else if (index == 2)
				qtdLinhas = argumentoInt;
			else if (index == 3)
				qtdColunas = argumentoInt;

    } 
    else if (index < 6)
    {
      argumentoFloat = strtod(argv[index], &verificacao);

      if (errno == EINVAL || *verificacao != EOS)
      {
        printf ("\n%s%sBase invalida no argumento (%hu)%s\n\n", RED, WHITE_BACKGROUND, index + 1, RESET);
        exit (BASE_INVALIDA);
      }
      if (errno == ERANGE)
      {	
        printf ("%s%s\nValor fornecido ultrapassa o valor maximo permitido para double (%f) no argumento (%hu)%s\n\n", RED, WHITE_BACKGROUND, DBL_MAX, index + 1, RESET);
        exit (VALOR_MAXIMO_DOUBLE_EXCEDIDO);
      }

      if (index == 4)
      {
        percentDefeituosos = argumentoFloat;
      }
      else
      {
        percentApagados = argumentoFloat;
      }
    }
    else
    {
      if (index == 6){
        corFundo = ObterCodigoAnsiCor(argv[6], fundo);
      }
      
      if (index == 7){
        corApagado = ObterCodigoAnsiCor(argv[7], texto);
      }

      if (index == 8){
        corAceso = ObterCodigoAnsiCor(argv[8], texto);
      }

      if (index == 9){
        corDefeituoso = ObterCodigoAnsiCor(argv[9], texto);  
      }
    }
  }

  resultadoDistribuicaoInicial = GerarDistribuicaoInicial(monitor, qtdLinhas, qtdColunas, percentDefeituosos, percentApagados);
  
  if (resultadoDistribuicaoInicial != ok)
  {
    printf("%s%sErro ao gerar distribuicao inicial de pixels do monitor:%s\n", RED, WHITE_BACKGROUND, RESET);
    printf("%s%scod.%d%s\n", RED, WHITE_BACKGROUND, resultadoDistribuicaoInicial, RESET);
    return resultadoDistribuicaoInicial;
  }

  resultado = MostrarMonitor(tempoCongelamento, monitor, qtdLinhas, qtdColunas, corFundo, corApagado, corAceso, corDefeituoso);

  if (resultado != ok)
  {
    printf("%s%sErro ao mostrar monitor:%s\n", RED, WHITE_BACKGROUND, RESET);
    printf("%s%scod.%d%s\n", RED, WHITE_BACKGROUND, resultado, RESET);
    return resultado;
  }

  return SUCESSO;
  
}

/* $RCSfile$ */