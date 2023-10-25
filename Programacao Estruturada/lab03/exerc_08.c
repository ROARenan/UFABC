#include <stdio.h>
#define MAX 1000

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct 
{
    char nome[100];
    Data nascimento;
    int ra;
}Aluno;


Data data_le(){
    // return: uma estrutura do tipo Data
    Data data;
    printf("Digite no formato dia, mes, ano um a um\n");
    scanf("%d",data.dia);
    scanf("%d",data.mes);
    scanf("%d",data.ano);
    return data;
}

Aluno aluno_le(){
    // return: uma estrutura de informacoes de aluno
    Aluno aluno;

    printf("Qual o nome do aluno?\n");
    fgets(aluno.nome,100,stdin);

    printf("Qual o aniversario?\n");
    aluno.nascimento = data_le();

    printf("Qual o RA?\n");
    scanf("%d",aluno.ra);
    return aluno;
}

//BUSCA ALUNO → SOLUCAO 1
Aluno aluno_busca(char nome[100]){

}

//BUSCA ALUNO → SOLUCAO 2
int opt;
Aluno lista_de_alunos[MAX];
int main(){
    //rodando o codigo em loop
    int cont_aluno = 0;
    while (opt != 0)
    {   
        printf("Selecione sua operacao\n");
        printf("1 - Cadastro de aluno\n");
        printf("2 - Buscar aluno pelo nome\n");
        printf("3 - Listar todos os alunos\n");

        scanf("%d",opt);

        if (opt == 1){
            lista_de_alunos[cont_aluno] = aluno_le();
            cont_aluno = cont_aluno + 1;
        }

        else if (opt == 2){
            lista_de_alunos[cont_aluno] = aluno_le();
            cont_aluno = cont_aluno + 1;
        }

        else if (opt == 0)
            break;
    }
    
    return 0;
}