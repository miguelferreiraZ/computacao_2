/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Funcao que calcula o MDC por recursividade
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
  ull resultado = 0;
  ull resto;
  ull menorNumero;
  
  /* verifica se o usuario inseriu 0 como parametro da funcao*/

  if (numero1 == 0 && numero2 == 0)
  {
    printf("%s\nMDC entre 0 e 0 nao existe, portanto e 0.\n\n%s");
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

  /* calcula corretamente o resto, maior numero divido pelo menor.*/
  if (numero1 >= numero2)
  {
    menorNumero = numero2;
    resto = numero1 % numero2;
  }
  else if (numero2 > numero1)
  {
    menorNumero = numero1;
    resto = numero2 % numero1;
  }
  
  /* verifica se o resto e 0, se nao, MDC (X,Y) = Y se Z é igual a zero.*/
  if (resto != 0)
    resultado = CalcularMaximoDivisorComum (numero2, resto);
  
  else
    resultado = menorNumero;

  return resultado;
}

/* $RCSfile$ */
