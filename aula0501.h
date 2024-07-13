/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Implementacao das funcoes de multiplicar
 *			      matrizes, obter matriz transposta, menor 
 *            complementar, complemento algebrico e 
 *				    calcular determinante.
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#ifndef _AULA0501_
#define _AULA0501_							                "@(#)aula0501.h $Revision$"

#define NUMERO_MAXIMO_LINHAS								100
#define NUMERO_MAXIMO_COLUNAS								100

typedef enum { ok, dimensaoMatrizesInvalida } tipoErros;

typedef unsigned short us;

tipoErros
ExibirMatriz (us numeroLinhas, us numeroColunas, long double [][numeroColunas]);

tipoErros
MultiplicarMatrizes (unsigned short,  /* numero de linhas da matriz 1 (E)  */
										 unsigned short,  /* numero de colunas da matriz 1 (E) */
										 unsigned short,  /* numero de linhas da matriz 2 (E)  */
										 unsigned short,  /* numero de colunas da matriz 2 (E) */
										 long double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* matriz 1 (E) */									
										 long double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* matriz 2 (E) */									
										 long double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS]  /* matriz produto (S) */);


#endif