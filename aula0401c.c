/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Funcao que calcula a exponencial pelo loop for
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
  int i;

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
  for (i = 0; i < expoenteAbsoluto; i++)
  {
    resultado *= base;
  }
  if (expoente < 0)
  {
    return 1 / resultado;
  }
  return resultado;
}

/* $RCSfile$ */