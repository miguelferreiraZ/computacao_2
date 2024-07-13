/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Funcao que calcula a serie harmonica alternada pela biblio math.h
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#include <math.h>
#include "aula0401.h"

float
CalcularSerieHarmonicaAlternada(us termo)
{
  float resultado = 0.0;
  us contador;
  
  for (contador = 1; contador <= termo; contador++)
  {
    resultado += 1.0 / pow(contador, contador);
  }
  
  return resultado;
}


/* $RCSfile$ */