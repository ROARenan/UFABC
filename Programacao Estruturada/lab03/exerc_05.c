#include <stdio.h>
#define MAX 1000

void tira_final(char texto[MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        if (texto[i] == '\n')
        {
            texto[i] = '\0';
            break;
        }
    }
}

int len(char texto[MAX])
{
    int cont = 0, i = 0;
    while (i < MAX && texto[i] != '\0')
    {
        cont = cont + 1;
        i = i + 1;
    }
    return cont - 1;
}

int compara_palavras(int inicio, char p1[MAX], char p2[MAX])
{
    int i = 0;
    if (len(p1) != len(p2))
        return 0;

    while (p1[i] != '\0' && p2[i] != '\0' && i < MAX)
    {
        if (p1[i] != p2[i])
            return 0;
        i = i + 1;
    }
    return 1;
}

int p_frase(char frase[MAX], char p[MAX])
{
    int i = 0;
    while (frase[i] != '\0')
    {
        int k = 0;
        while (frase[i] != ' ' && frase[i] != '\0')
        {

            if (frase[i] != p[k])
                break;
            k = k + 1;
            i = i + 1;
        }

        if (p[k] == '\0')
        {
            return 1;
        }

        if (frase[i] == ' ')
        {
            i = i + 1;
        }
    }

    return 0;
}

char frase[MAX];
int i = 0, x;
int main()
{
    printf("Entre com a frase\n");
    fgets(frase,MAX,stdin);
    while (frase[i] != '\0'){
        if( i%80 == 0){
            printf("\n");
        }
        printf("%c",frase[i]);

        i = i + 1;
    }
    return 0;
}