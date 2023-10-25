#include <stdio.h>
#define MAX 10

int main()
{
    int i, cont = 0, big = 0;
    char frase[MAX];

    printf("Escreva seu binário:\n");
    scanf("%s", frase);

    for (i = 0; i < MAX; i++)
    {
        if (frase[i] == '0')
        {
            cont++;
            if (cont > big)
            {
                big = cont;
            }
        }
        else
        {
            cont = 0;
        }
    }

    printf("Tamanho da maior sequência de zeros: %d\n", big);

    return 0;
}
