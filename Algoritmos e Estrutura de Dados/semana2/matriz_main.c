#include <stdio.h>
#include "matriz.h"

struct Matriz {
    double** array;
    int rows;
    int cols;
};

int main() {
    // Testando a criação de matrizes
    Matriz *matriz1 = matriz_create(3, 3);
    Matriz *matriz2 = matriz_create(3, 3);

    // Inicializando as matrizes com valores
    for (int i = 0; i < matriz1->rows; i++) {
        for (int j = 0; j < matriz1->cols; j++) {
            matriz_set(matriz1, i, j, i + j);
            matriz_set(matriz2, i, j, i - j);
        }
    }

    // Imprimindo as matrizes
    printf("Matriz 1:\n");
    matriz_print(matriz1);

    printf("\nMatriz 2:\n");
    matriz_print(matriz2);

    // Testando a adição de matrizes
    Matriz *soma = matriz_add(matriz1, matriz2);
    printf("\nSoma das matrizes:\n");
    matriz_print(soma);

    // Testando a subtração de matrizes
    Matriz *subtracao = matriz_sub(matriz1, matriz2);
    printf("\nSubtração das matrizes:\n");
    matriz_print(subtracao);

    // Testando a multiplicação escalar
    Matriz *escalar = matriz_scalar_mul(matriz1, 2.5);
    printf("\nMultiplicação escalar:\n");
    matriz_print(escalar);

    // Testando a transposição de matriz
    Matriz *transposta = matriz_transpose(matriz1);
    printf("\nTransposta da Matriz 1:\n");
    matriz_print(transposta);

    // Testando se a matriz é simétrica
    printf("\nA Matriz 1 é simétrica? %s\n", matriz_is_symmetric(matriz1) ? "Sim" : "Não");

    // Liberando a memória alocada
    matriz_destroy(matriz1);
    matriz_destroy(matriz2);
    matriz_destroy(soma);
    matriz_destroy(subtracao);
    matriz_destroy(escalar);
    matriz_destroy(transposta);

    return 0;
}
