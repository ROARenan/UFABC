#include <stdio.h>

void combinacao(int arr[], int data[], int start, int end, int index, int r) {
    // Se a combinação de tamanho r for formada, imprima-a
    if (index == r) {
        for (int i = 0; i < r; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
        return;
    }

    // Processa os elementos restantes do array
    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        combinacao(arr, data, i + 1, end, index + 1, r);
    }
}

int main() {
    int n, k;

    // Recebe o número de elementos e o tamanho da combinação
    printf("Digite o número de elementos (n): ");
    scanf("%d", &n);

    printf("Digite o tamanho da combinação (k): ");
    scanf("%d", &k);

    int arr[n];

    // Recebe os valores
    printf("Digite os elementos:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int data[k];

    // Chama a função para imprimir todas as combinações
    combinacao(arr, data, 0, n - 1, 0, k);

    return 0;
}
