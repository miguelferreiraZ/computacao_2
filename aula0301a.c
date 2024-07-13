/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Funcao que calcula o numero de fibonacci, de acordo com recursao
 * 
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#include "aula0301.h"

ull
CalcularTermoSerieFibonacci(us numero){
  if (numero <= 1){
    return numero;
  }
  
  return CalcularTermoSerieFibonacci(numero-1) + CalcularTermoSerieFibonacci(numero-2);
}

/* $RCSfile$ */