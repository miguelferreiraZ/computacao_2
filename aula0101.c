/*******************************************************************************
  *
  * Universidade Federal do Rio de Janeiro
  * Escola Politecnica
  * Departamento de Eletronica e de Computacao
  * Prof. Marcelo Luiz Drumond Lanza
  * EEL270 - Computacao II - Turma 2024/1
  * Autor: Miguel de Azevedo Ferreira
  * Descricao: Aula pratica 1
  *
  * $Author$
  * $Date$
  * $Log$
  *
  *******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#include "aula0101.h"
#include "cores.h"

#define SUCESSO                         0
#define NUMERO_ARGUMENTOS_INVALIDO      1
#define ARGUMENTO_FORA_INTERVALO        2

void
ExibirCabecalho(us numero){

        us digitoUni;
        us digitoCent;
        us digitoDez;

        for (digitoCent = 0; digitoCent < numero; digitoCent++)
        {
                printf("%s%s%hu%s", BLACK, WHITE_BACKGROUND, digitoCent/100, RESET);
        }
        printf("\n");

        for (digitoDez = 0; digitoDez < numero; digitoDez++)
        {
                printf("%s%s%hu%s", BLACK, WHITE_BACKGROUND, (digitoDez%100)/10, RESET);
        }
        printf("\n");

        for (digitoUni = 0; digitoUni < numero; digitoUni++)
        {
                printf("%s%s%hu%s", BLACK, WHITE_BACKGROUND, (digitoUni%100)%10, RESET);
        }
        printf("\n");
}


void
ExibirHifens(us numHifens)
{
  us limite;
  char hifen = '-';

  for (limite = 0; limite < numHifens; limite++)
  {
    printf("%s%s%c%s", WHITE, BLACK_BACKGROUND, hifen, RESET);
  }
}
