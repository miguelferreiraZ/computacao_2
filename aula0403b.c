/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Funcao que calcula a serie harmonica alternada pelo loop do-while
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#include "aula0401.h"

float
CalcularSerieHarmonicaAlternada(us termo)
{
  float termoAtual = 0.0;
  float resultado = 0.0;
  us contador = 1;
  
  do
  {
    termoAtual = 1.0 / CalcularExponencial(contador, contador);
    
    if (contador % 2 == 0)
    {
      termoAtual = -termoAtual;
    }
    
    resultado += termoAtual;
    contador++;
  }
  while (contador <= termo);
  
  return resultado;
}


/* $RCSfile$ */