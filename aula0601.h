/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Prototipo das funcoes de gerar e validar RG
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#ifndef _AULA0601_
#define _AULA0601_							                  "@(#)aula0601.h $Revision$"

#define NUMERO_MAXIMO_ENTRADA                                              8
#define ENTRADA_RG                                                         10

typedef enum { ok, tamanhoEntradaIncorreto, erroDigitoInvalido, rgInvalido, erroDesconhecido } tipoErros;

typedef unsigned char byte;
typedef unsigned short us;

tipoErros
GerarDigitosVerificadoresRG (byte [NUMERO_MAXIMO_ENTRADA]);

tipoErros
ValidarRg (byte [ENTRADA_RG]);     /* Apenas entrada e retorna se foi valido ou nao */

#endif

/* $RCSfile$ */