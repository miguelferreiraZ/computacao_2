/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Funcoes para manipular matrizes
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#include <stdio.h>
#include "cores.h"
#include "aula0501.h"

tipoErros 
ExibirMatriz(us numeroLinhas, us numeroColunas, long double matriz[numeroLinhas][numeroColunas])
{
	
	unsigned linha, coluna;
	

	for (linha = 0; linha < numeroLinhas; linha++)
	{
		printf("%s|%s ", BOLD_GREEN, RESET); 
		for (coluna = 0; coluna < numeroColunas; coluna++)
		{
			printf("%.5Lf ", matriz[linha][coluna]);
		}
		printf("%s|%s\n", BOLD_GREEN, RESET);
	}
	return ok;
}

tipoErros
MultiplicarMatrizes(us numeroLinhas1, us numeroColunas1, us numeroLinhas2, us numeroColunas2, long double matriz1[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], long double matriz2[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], long double matrizProduto[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS])
{
	us linha, coluna, index;

	if (numeroColunas1 != numeroLinhas2)
	{
		return dimensaoMatrizesInvalida;
	}

	for (linha = 0; linha < numeroLinhas1; linha++)       /* Inicializa a matrizProduto */
	{
		for (coluna = 0; coluna < numeroColunas2; coluna++)
		{
			matrizProduto[linha][coluna] = 0;
		}
	}

	for (linha = 0; linha < numeroLinhas1; linha++)
	{
		for (coluna = 0; coluna < numeroColunas2; coluna++)
		{
			for (index = 0; index < numeroColunas1; index++)
			{
				matrizProduto[linha][coluna] += matriz1[linha][index] * matriz2[index][coluna];
			}
		}
	}

	ExibirMatriz(numeroLinhas1, numeroColunas2, matrizProduto);

	return ok;
}

/* $RCSfile$ */
