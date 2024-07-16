/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Prototipo das funcoes da aula07 (MONITOR)
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#ifndef _AULA0701_
#define _AULA0701_							                  "@(#)aula0701.h $Revision$"

typedef enum {fundo, texto} tipoFundoTexto;
typedef enum {apagado, aceso, defeituoso = -1} tipoPixel;
typedef enum {ok, erroNumeroLinhas, erroNumeroColunas, erroNumeroVertices, erroNumeroPercentual, erroDigitoInvalido, erroDesconhecido} tipoErros;

#define NUMERO_MAXIMO_LINHAS_MONITOR                                        250
#define NUMERO_MAXIMO_COLUNAS_MONITOR                                       800
#define APAGADO                                                             ' '
#define ACESO                                                               ' '
#define DEFEITUOSO                                                          '.'
#define NUMERO_MAXIMO_VERTICES                                              50

#include <unistd.h>

char *
ObterCodigoAnsiCor(char * nomeCor, /* E */
                  tipoFundoTexto fundoTexto);

tipoErros
MostrarMonitor(useconds_t tempoEspera,
               tipoPixel monitor[NUMERO_MAXIMO_LINHAS_MONITOR][NUMERO_MAXIMO_COLUNAS_MONITOR],
               unsigned numeroLinhas,
               unsigned numeroColunas,
               char *corFundo,
               char *corPixelApagado,
               char *corPixelAceso,
               char *corPixelDefeituoso);

tipoErros
GerarDistribuicaoInicial(tipoPixel monitor[NUMERO_MAXIMO_LINHAS_MONITOR][NUMERO_MAXIMO_COLUNAS_MONITOR], /* E/S */
                        unsigned numeroLinhas, 
                        unsigned numeroColunas, 
                        float percentualDefeituosos, 
                        float percentualApagados);


#endif

/* $RCSfile$ */