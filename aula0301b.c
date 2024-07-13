/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Funcao que calcula o numero de fibonacci, de acordo com a
 * entrada do usuario, com o loop do while
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#include "aula0301.h"


ull anterior = 0;
ull atual = 1;
ull temp = 0;
us index = 1;

ull
CalcularTermoSerieFibonacci(us numero)
{
  if (numero <= 1){
    return numero;
  }

  do
  {
    temp = anterior + atual;
    anterior = atual;
    atual = temp;
    index++;
  
  } while (numero < index);
  
  return atual;
}

/* $RCSfile$ */