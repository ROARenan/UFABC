//Renan Santana RA: 11202131332

#include <stdio.h>

void combinations(int arr[], int data[], int start, int end, int index, int r) {
    // Quando todas as combinações de tamanho r são geradas, imprime
    if (index == r) {
        for (int i = 0; i < r; i++) {
            printf("%d", data[i]);
        }
        printf("\n");
        return;
    }

    // Processa os elementos restantes
    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        combinations(arr, data, i + 1, end, index + 1, r);
    }
}

// Função para gerar todas as combinações de tamanho r dos primeiros n números naturais
void generateCombinations(int n) {
    int arr[n];
    int data[n];

    // Preenche o array com os primeiros n números naturais
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Gera combinações de tamanho 1 até n
    for (int r = 1; r <= n; r++) {
        combinations(arr, data, 0, n - 1, 0, r);
    }
}

int main() {
    int n;

    // Solicita ao usuário o valor de n
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    // Gera e imprime todas as combinações dos primeiros n números naturais
    generateCombinations(n);

    return 0;
}
