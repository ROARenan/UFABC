# Objetivos

- Praticar o processamento de listas simplesmente encadeadas.
- Praticar o armazenamento de tipos compostos em listas.

## Definição do problema

O TAD Student permite representar estudantes com RA, nome e matrícula. Os arquivos `student.h` e `student.c` contêm a interface e a implementação do TAD, respectivamente. Todas as operações do TAD já estão definidas, você não deve alterar esses arquivos.

Uma lista de estudantes é definida pelo TAD StudentList, que permite armazenar e manipular estudantes em uma lista simplesmente encadeada. Ou seja, cada nó da lista encadeada tem como informação um estudante. A interface do TAD é definida no arquivo `student_list.h`, enquanto a implementação do TAD é definida no arquivo `student_list.c`. As seguintes operações já estão implementadas no TAD: construtor, destrutor, inserção, acesso e impressão. Você pode usar essas operações como auxílio para resolver e testar a atividade.

Em resumo, a atividade tem os seguintes arquivos prévios:

- `student.h`: interface do TAD Student.
- `student.c`: implementação do TAD Student.
- `student_list.h`: interface do TAD StudentList.
- `student_list.c`: implementação do TAD StudentList.

O código-cliente `main.c` ilustra alguns exemplos de uso do TAD StudentList. Você pode usar o `main.c` para testar a sua implementação.

## O que fazer

Primeiramente você deve estudar o código-base e compreender como funciona. Na interface do TAD StudentList (`student_list.h`), estão definidos os protótipos das funções que você deve implementar. Seguem algumas observações importantes:

- A única função que pode modificar a lista passada como argumento é a `list_incrementGrades`. As demais funções devem retornar uma nova lista, sem modificar a lista original.
- Nas funções que retornam uma nova lista, a ordem dos estudantes na lista retornada é irrelevante.

As funções a serem implementadas são as seguintes:

- `list_findByRa`: busca um estudante na lista pelo RA e retorna um ponteiro para o estudante encontrado. Se o estudante não for encontrado, a função deve retornar NULL.
- `list_incrementGrades`: incrementa as notas de todos os estudantes da lista. A função recebe como argumento uma lista de estudantes e, após sua execução, a lista recebida deve ter as notas de todos os estudantes incrementadas com a quantidade informada. Ou seja, se o total de incremento é 0.5, e as notas dos estudantes são 5.0, 7.0 e 8.0, após a execução da função, as notas dos estudantes devem ser 5.5, 7.5 e 8.5, respectivamente.
- `list_averageGrade`: calcula a média das notas dos estudantes da lista e retorna o valor calculado.
- `list_filterFailed`: retorna uma nova lista contendo apenas os estudantes que foram reprovados. Estão reprovados os estudantes com nota inferior a 6.0.
- `list_filterPassed`: retorna uma nova lista contendo apenas os estudantes que foram aprovados. Estão aprovados os estudantes que obtiveram nota ao menos 6.0.
- `list_filterExam`: retorna uma nova lista contendo apenas os estudantes que estão em recuperação. Estão em recuperação os estudantes reprovados com nota ao menos 4.0. Ou seja, o aluno deve ter nota menor do que 6.0 (reprovado) porém igual ou maior a 4.0.

### Observações

- As funções da API do TAD que retornam uma nova lista devem alocar memória dinamicamente para essa lista.

## Restrições

- É obrigatório respeitar o encapsulamento do TAD StudentList, ou seja, no programa principal (ou código-cliente) só é permitido acessar os serviços oferecidos pelas funções da API do TAD StudentList.
- Para fins de simplificar o código, não é preciso respeitar o encapsulamento do TAD Student, ou seja, é possível acessar membros dessa estrutura sem passar pela API do TAD.
- Não altere ou suprima as funções que já estão implementadas no TAD StudentList, pois elas podem estar sendo usadas nos testes.

## Testes automáticos

Os testes automáticos irão verificar:

- A corretude das funções implementadas.
- A ausência de vazamentos de memória.
