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

#ifndef _AULA0604_
#define _AULA0604_							                    "@(#)aula0604.h $Revision$"

typedef enum { sucesso, valido, invalido } tipoErros;

tipoErros
GerarDigitosVerificadoresRg (char * /* entrada */, char * /* saida */);

tipoErros
ValidarRg (char * /* entrada */);

#endif

/* $RCSfile$ */