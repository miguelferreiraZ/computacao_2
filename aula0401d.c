/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Funcao que calcula a exponencial pelo loop while
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#include "aula0401.h" 

long double
CalcularExponencial(double base, int expoente)
{
  long double resultado = 1;
  int expoenteAbsoluto = expoente;
  if (base == 0 && expoente == 0)
  {
    return 1;
  }
  else if (expoente == 0)
  {
    return 1;
  }
  else if (expoente < 0)
  {
    expoenteAbsoluto = -expoente;
  }
  while (expoenteAbsoluto > 0)
  {
    resultado *= base;
    expoenteAbsoluto--;
  }
  if (expoente < 0)
  {
    return 1 / resultado;
  }
  return resultado;
} 


/* $RCSfile$ */