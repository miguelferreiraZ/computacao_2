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

#include "aula0101.h"
#include "cores.h"

void 
TodasCores(void);

void
TodasCores(void)
{
  us numero;
  us contador = 1;

  printf("    ");
  for (numero = 0; numero < 256; numero++)
  {
    if (contador == 17)
    {
      contador = 1;
      printf("\n    ");
    }

    printf("\e[38;5;%hum%03hu\e[0m ", numero, numero);

    contador++;

  }
}

int
main(void)
{
  printf("\n");
  ExibirCabecalho(80);
  printf("\n");
  TodasCores();

  return 0;
}

/* $RCSfiles$ */