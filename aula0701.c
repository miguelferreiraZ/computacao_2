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

#include <stdio.h>
#include <string.h>

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


/* $RCSfile$ */