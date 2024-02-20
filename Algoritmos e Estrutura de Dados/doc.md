## Objetivos
- Aprender a identificar vazamentos de memória

- Aprender a corrigir vazamentos de memória

## Definição do problema
A atividade é composta de um único arquivo (main.c) que contém um programa que faz uma operação “secreta”, mas apresenta um ou mais vazamentos de memória. Além disso, esse(s) vazamento(s) estão prejudicando a saída do programa, que está fora do esperado. Não importa o que o programa faz, o importante é que ele possui vazamentos de memória que precisam ser corrigidos.

## O que fazer
Você precisa rastrear o funcionamento do programa, identificar os vazamentos de memória e corrigi-los. O objetivo final é que todos os vazamentos de memória sejam corrigidos e que a saída esperada seja obtida.

Lembre-se da regra geral: para cada chamada de malloc deve haver uma chamada correspondente de free. Falhar em chamar free para cada malloc é um vazamento de memória.

## Saída esperada
Uma vez corrigido todos os problemas, a saída do programa deve ser a seguinte:

  Stage 1: Confidential details
  Stage 2: Confidential details (copied)
  Progress: 0 1 2 3 4 5 6 7 8 9 
  Stage 3: Confidential details (using data)
Restrições
Não é permitido remover ou incluir novas chamadas de malloc no programa, ou seja, não é permitido alterar a quantidade de memória alocada — isso é verificado pelos testes. Apenas corrija os vazamentos de memória, inserindo chamadas da função free nos locais adequados.

## O que será testado
- Presença de vazamentos de memória

- Saída esperada do programa

- Quantidade esperada de memória alocada

A atribuição de nota será binária, ou seja, nota máxima para programas que não possuem vazamentos de memória e que produzem a saída esperada, e nota zero para programas que possuem vazamentos de memória ou que não produzem a saída esperada.

### Arquivos requeridos
main.c

```C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_data() {
  char *temp = malloc(30);

  strcpy(temp, "Confidential details");
  printf("Stage 1: %s\n", temp);

  return temp;
}

void process_data(char *data) {
  int size = strlen(data) + 1;
  char *buffer = malloc(size);

  strcpy(buffer, data);
  printf("Stage 2: %s (copied)\n", buffer);
  free(data); 

  int *progress = malloc(10 * sizeof(int));

  for (int i = 0; i < 10; i++) {
    progress[i] = i;
  }
  printf("Progress: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", progress[i]);
  }
  printf("\n");
}

void perform_task(char *data) {
  process_data(data);
  printf("Stage 3: %s (using data)\n", data);
}

int main() {
  perform_task(get_data());

  return 0;
}

```

