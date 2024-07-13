/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Funcao que calcula o MDC pelo laco do while
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/


#include <stdio.h>
#include <stdlib.h>

#include "aula0201.h"
#include "cores.h"

ull
CalcularMaximoDivisorComum(ull numero1, ull numero2)
{
  ull resto;
  ull resultado = 0;

  if (numero1 == 0 && numero2 == 0)
  {
    printf("%s\nMDC entre 0 e 0 nao existe, portanto e 0.\n\n%s", RED, RESET);
    return resultado;
  }

  else if (numero1 == 0)
  {
    resultado = numero2;
    return resultado;
  }

  else if (numero2 == 0)
  {
    resultado = numero1;
    return resultado;
  }

  do
  {
    resto = numero1 % numero2;
    numero1 = numero2;
    numero2 = resto;
  } while (numero2 != 0);

  return numero1;

}

/* $RCSfile$ */