#include <stdio.h>
#include <stdlib.h>
#include "aula0101.h"
#include "cores.h"

#define SUCESSO                       1
#define NUMERO_ARGUMENTOS_INVALIDO    2
#define ARGUMENTO_FORA_INTERVALO      3

int main(int argc, char *argv[]) {

  if (argc != 2) 
  {
    printf("%sEntrada com mais de 1 argumento invalida. Utilize apenas um numero inteiro como entrada%s", RED, RESET);
    exit(NUMERO_ARGUMENTOS_INVALIDO);
  }

  ul numero = strtoul(argv[1], NULL, 10);

  if (numero == 0 || numero > 500) 
  {
    printf("%sO valor deve ser um numero positivo entre 1 e 500.%s\n", RED, RESET);
    exit(ARGUMENTO_FORA_INTERVALO);
  }

  us numCols = (us)numero;

  ExibirCabecalho(numCols);
  
  return SUCESSO;
}