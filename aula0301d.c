/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Funcao que calcula o numero de fibonacci, de acordo com a
 * entrada do usuario, com o loop while
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#include "aula0301.h"


ull
CalcularTermoSerieFibonacci(us numero)
{
  if (numero <= 1){
    return numero;
  }

  ull anterior = 0;
  ull atual = 1;
  ull temp;
  us index = 1;

  while (index < numero)
  {
    temp = anterior + atual;
    anterior = atual;
    atual = temp;
    index++;
  }
  
  return atual;
}


/* $RCSfile$ */