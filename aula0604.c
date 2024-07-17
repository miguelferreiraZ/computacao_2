/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Funcoes de gerar e validar RG
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#include "aula0604.h"

#define COMPRIMENTO_RG														9

tipoErros
GerarDigitosVerificadoresRg (char *rg, char *digito)
{

	unsigned contador,
					 resultado = 0,
					 peso = 2;

	for (contador = 0; contador < (COMPRIMENTO_RG - 1); contador++)
	{
		resultado += (peso * (rg [contador] - '0'));
		peso++;
	}
	
	resultado %= 11;
	resultado = 11 - resultado;

	*digito = resultado + '0'; 	

	return sucesso;
	
}

tipoErros
ValidarRg (char *rg)
{
	
	char rgAnalisado [COMPRIMENTO_RG];

	unsigned indice;

	char digito;

	tipoErros resultado = valido;

	for (indice = 0; indice < (COMPRIMENTO_RG - 1); indice++)
		rgAnalisado [indice] = rg [indice];

	GerarDigitosVerificadoresRg (rgAnalisado, &digito);

	if (digito != rg [8])
		resultado = invalido;
	
	return resultado;
}

/* $RCSfile$ */