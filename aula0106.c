/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Programa que exibe os tamanhos dos 5 tipos basicos, dos 2 
 * modificadores de sinal e dos 3 modificadores de largura.
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "aula0101.h"
#include "cores.h"

#define SUCESSO															0

#define NUMERO_HIFENS												100
#define NUMERO_ESPACO_EM_BRANCO						  91

void
ExibirTamanho (char *, us);

void 
ExibirTamanho (char *palavra, us quantidadeBytes)
{
	
	us indice;
	us espacoEmBranco = NUMERO_ESPACO_EM_BRANCO - strlen (palavra);
	
	printf ("%s%s%s:", GREEN, palavra, RESET);

	for (indice = espacoEmBranco; indice > 0; indice--)
		printf (" ");

	printf ("%s%i byte%s%s\n", YELLOW,  quantidadeBytes, quantidadeBytes > 1 ? "s" : "", RESET);

}

int
main (int argc, char *argv [])
{
	ExibirHifens(NUMERO_HIFENS);

	printf ("%sTamanhos dos Tipos Basicos%s\n\n", UNDERLINE_WHITE, RESET);

	ExibirTamanho ("void", sizeof (void));
	
	ExibirTamanho ("char", sizeof (char));

	ExibirTamanho ("int", sizeof (int));

	ExibirTamanho ("float", sizeof (float));

	ExibirTamanho ("double", sizeof (double));

	ExibirHifens (NUMERO_HIFENS);

	printf ("%sTamanhos dos Modificadores de Sinal%s\n\n", UNDERLINE_WHITE, RESET);

	ExibirTamanho ("signed", sizeof (signed));

	ExibirTamanho ("unsigned", sizeof (unsigned));

	ExibirHifens (NUMERO_HIFENS);

	printf ("%sTamanhos dos Modificadores de Largura%s\n\n", UNDERLINE_WHITE, RESET);
	
	ExibirTamanho ("short", sizeof (short));

	ExibirTamanho ("long", sizeof (long));	

	ExibirTamanho ("long long", sizeof (long long));

	ExibirHifens (NUMERO_HIFENS);

	return SUCESSO;

}

/* $RCSfiles$ */