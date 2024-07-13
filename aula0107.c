/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2024/1
 * Autor: Miguel de Azevedo Ferreira
 * Descricao: Programa que exibe os tamanhos das combinacoes validas entre
 * modificadores de sinal, de largura e tipos basicos.
 * 
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
ExibirTamanho (char *, unsigned int);

void 
ExibirTamanho (char *palavra, unsigned int quantidadeBytes)
{
	
	unsigned int indice;
	unsigned int espacoEmBranco = NUMERO_ESPACO_EM_BRANCO - strlen (palavra);
	
	printf ("%s%s%s:", GREEN, palavra, RESET);

	for (indice = espacoEmBranco; indice > 0; indice--)
		printf (" ");

	printf ("%s%i byte%s%s\n", YELLOW,  quantidadeBytes, quantidadeBytes > 1 ? "s" : "", RESET);

}

int
main (int argc, char *argv [])
{

	ExibirHifens (NUMERO_HIFENS);

	printf ("%sTamanhos dos Tipos Basicos combinados com Modificadores de Sinal%s\n\n", UNDERLINE_WHITE, RESET);

	ExibirTamanho ("signed char", sizeof (signed char));
	ExibirTamanho ("unsigned char", sizeof (unsigned char));

	ExibirTamanho ("signed int", sizeof (signed int));
	ExibirTamanho ("unsigned int", sizeof (unsigned int));

	ExibirHifens (NUMERO_HIFENS);

	printf ("%sTamanhos dos Tipos Basicos combinados com Modificadores de Largura%s\n\n", UNDERLINE_WHITE, RESET);

	ExibirTamanho ("short int", sizeof (short int));
	ExibirTamanho ("long int", sizeof (long int));
	ExibirTamanho ("long long int", sizeof (long long int));

	ExibirTamanho ("long double", sizeof (long double));

	ExibirHifens (NUMERO_HIFENS);

	printf ("%sTamanhos dos Modificadores de Sinal combinados com Modificadores de Largura%s\n\n", UNDERLINE_WHITE, RESET);

	ExibirTamanho ("signed short", sizeof (signed short));
	ExibirTamanho ("signed long", sizeof (signed long));
	ExibirTamanho ("signed long long", sizeof (signed long long));

	ExibirTamanho ("unsigned short", sizeof (unsigned short));
	ExibirTamanho ("unsigned long", sizeof (unsigned long));
	ExibirTamanho ("unsigned long long", sizeof (unsigned long long));

	ExibirHifens (NUMERO_HIFENS);

	printf ("%sTamanhos dos Tipos Basicos combinados com Modificadores de Sinal e com Modificadores de Largura%s\n\n", UNDERLINE_WHITE, RESET);
	
	ExibirTamanho ("signed short int", sizeof (signed short int));
	ExibirTamanho ("signed long int", sizeof (signed long int));	
	ExibirTamanho ("signed long long int", sizeof (signed long long int));

	ExibirTamanho ("unsigned short int", sizeof (unsigned short int));
	ExibirTamanho ("unsigned long int", sizeof (unsigned long int));
	ExibirTamanho ("unsigned long long int", sizeof (unsigned long long int));

	ExibirHifens (NUMERO_HIFENS);

	return SUCESSO;

}

/* $RCSfiles$ */