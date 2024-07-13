#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "cores.h"
#include "aula0101.h"

#define NUMERO_ARGUMENTOS             2
#define SUCESSO                       0
#define NUMERO_ARGUMENTOS_INVALIDO    1
#define ARGUMENTO_INVALIDO            3

void ImprimirHifens(us numero);

int 
main(int argc, char *argv[])
{
  us numero;
  char *validacao;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf("%sEntrada com mais ou menos de 1 argumento invalida. Utilize apenas um numero inteiro como entrada%s", RED, RESET);
    exit(NUMERO_ARGUMENTOS_INVALIDO);
  }

  numero = (us)strtoul(argv[1], &validacao, 10);

  if (argv[1][0] == '-' || numero == 0 || numero > 500)
  {
    printf("O argumento deve ser um numero inteiro positivo maior que 0 e menor que 500.\n");
    exit(ARGUMENTO_INVALIDO);
  }

  if (*validacao != '\0' || errno == ERANGE)
  {
    printf("O argumento deve ser um numero inteiro positivo.\n");
    exit(ARGUMENTO_INVALIDO);
  }

  ImprimirHifens(numero);

  return SUCESSO;
}

void 
ImprimirHifens(us numero)
{
  us i;
  char hifen = '-';

  printf("\n\n");
  for (i = 0; i < numero; i++)
  {
    printf("%s%s%c%s", WHITE, BLACK_BACKGROUND, hifen, RESET);
  }
  printf("\n\n\n");
}