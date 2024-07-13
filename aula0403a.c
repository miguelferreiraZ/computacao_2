/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Funcao que calcula a serie harmonica alternada por recursao
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
  if (termo == 0)
  {
    return 0.0;
  }
  
  float termoAtual = 1.0 / CalcularExponencial(termo, termo);

  if (termo % 2 == 0) 
  {
    termoAtual = -termoAtual;
  }

  return CalcularSerieHarmonicaAlternada(termo - 1) + termoAtual;
}


/* $RCSfile$ */