/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Funcao para gerar digitos verificadores de RG
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#include "aula0601.h"

tipoErros
GerarDigitosVerificadoresRG (byte entrada [NUMERO_MAXIMO_ENTRADA + 1])
{
  us index;

  for (index = 0; index < NUMERO_MAXIMO_ENTRADA; index++)
  {
    if (entrada[index] < 0 || entrada[index] > 9)
    {
      return erroDigitoInvalido;
    }
  }

  byte pesos[NUMERO_MAXIMO_ENTRADA] = {2, 3, 4, 5, 6, 7, 8, 9};
  us soma = 0;

  for (index = 0; index < NUMERO_MAXIMO_ENTRADA; index++)
  {
    soma += entrada[index] * pesos[index];
  }
  
  us resto = soma % 11;
  us dVerificador = 11 - resto;

  if (dVerificador == 10) {
    entrada[NUMERO_MAXIMO_ENTRADA] = 'X';
  } else if (dVerificador == 11) {
    entrada[NUMERO_MAXIMO_ENTRADA] = 0;
  } else {
    entrada[NUMERO_MAXIMO_ENTRADA] = dVerificador;
  }

  return ok;
}

tipoErros
ValidarRg (byte rg [ENTRADA_RG])
{
  us index;

  for (index = 0; index < ENTRADA_RG - 1 ; index++)
  {
    if (rg[index] < 0 || rg[index] > 9)
    {
      return erroDigitoInvalido;
    }
  }
  
  byte manipulaRG[] = {rg[0], rg[1], rg[2], rg[3], rg[4], rg[5], rg[6], rg[7]};

  GerarDigitosVerificadoresRG(manipulaRG);

  if (manipulaRG[8] == rg[8])
  {
    return ok;
  } else
  {
    return rgInvalido;
  }
}

/* $RCSfile$ */