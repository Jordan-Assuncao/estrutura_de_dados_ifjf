#include <stdlib.h>
#include <stdio.h>

struct EstruturaAluno
{
    int matricula;
    char *nome;
    float nota;

    struct EstruturaAluno *prox;
};
typedef struct EstruturaAluno Aluno;

Aluno *insereInicio(Aluno *atual, Aluno no)
{
    Aluno *novo = (Aluno*) malloc(sizeof(Aluno));
    novo->matricula = no.matricula;
    novo->nome = no.nome;
    novo->nota = no.nota;

    if (atual == NULL) //9 Lista está vazia?
    {
        novo->prox = NULL;
    }
    else
    {
        novo->prox = atual;
    }
    return novo;
}

Aluno *insereFinal(Aluno *atual, Aluno no){
    Aluno *aux = atual;
    Aluno *novo = (Aluno*) malloc(sizeof(Aluno));
    novo->matricula = no.matricula;
    novo->nome = no.nome;
    novo->nota = no.nota;
    if (atual == NULL)
    {
      return insereInicio(atual, no);
    }
    else
    {
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = NULL;
    }
    return atual;
}

void imprime(Aluno *atual){
    if (atual == NULL){
        printf("\nLista Vazia!");
    }
    while(atual != NULL){
        printf("\nMatricula: %d", atual->matricula);
        printf("\nNome.....: %s", atual->nome);
        printf("\nNota.....: %f", atual->nota);
        printf("\n");
        atual = atual->prox;}
}

Aluno *removeAluno(Aluno *atual, int matricula){
    Aluno *ant = NULL; /* ponteiro para elemento anterior */
    Aluno *inicio = atual; /*guarda o inicio da lista.*/

    while((atual != NULL) && (atual->matricula != matricula)){
        ant = atual;
        atual = atual->prox;
    }
    if(atual == NULL){
        return inicio;
    } /* não achou: retorna lista original */
    Aluno *exclui = atual;
    if(ant == NULL){
    /* remove elemento do inicio */
    inicio = atual->prox;
    }
    else{
    /* remove elemento intermediario ou último */
    ant->prox = atual->prox;
    }
    free(exclui);
    return inicio;

}

Aluno *busca(Aluno *atual, int matricula) {
    Aluno *inicio = atual; /*guarda o inicio da lista.*/
    while (atual != NULL && atual->matricula != matricula){
        atual = atual->prox;
    }
    if(atual == NULL){
        return NULL;
    }else{
        return atual;
    }
}

float calcularMedia(Aluno *atual) {
    if (atual == NULL) {
        printf("\nLista Vazia!");
        return 0.0;
    }

    float somaNotas = 0.0;
    int numAlunos = 0;

    while (atual != NULL) {
        somaNotas += atual->nota;
        numAlunos++;
        atual = atual->prox;
    }

    return somaNotas / numAlunos;
}

main(){

    Aluno *listaAluno = NULL;

    Aluno no;

    no.matricula = 111;
    no.nome = "Flavio";
    no.nota = 10.0;
    listaAluno = insereInicio(listaAluno, no);

    no.matricula = 221;
    no.nome = "b";
    no.nota = 10.0;
    listaAluno = insereInicio(listaAluno, no);

    no.matricula = 31;
    no.nome = "o";
    no.nota = 0.0;
    listaAluno = insereFinal(listaAluno, no);

    no.matricula = 114441;
    no.nome = "joao";
    no.nota = 7.0;
    listaAluno = insereInicio(listaAluno, no);

    no.matricula = 777;
    no.nome = "Flo";
    no.nota = 3.0;
    listaAluno = insereFinal(listaAluno, no);

    no.matricula = 9999;
    no.nome = "luis";
    no.nota = 10.0;
    listaAluno = insereFinal(listaAluno, no);
    imprime(listaAluno);

    Aluno *alunobuscado = busca(listaAluno, 777);
    if (alunobuscado != NULL){
        printf("\nAluno encontrado!\nMatricula: %d\nNome: %s\nNota: %f\n", alunobuscado->matricula,alunobuscado->nome,alunobuscado->nota);
    }else{
        printf("Aluno nao encontrado!");
    }

    alunobuscado = busca(listaAluno, 0);
    if (alunobuscado != NULL){
        printf("\nAluno encontrado!\nMatricula: %d\nNome: %s\nNota: %f\n", alunobuscado->matricula,alunobuscado->nome,alunobuscado->nota);
    }else{
        printf("\nAluno nao encontrado!\n");
    }

    float media = calcularMedia(listaAluno);
    printf("\nMedia das notas dos alunos: %f\n", media);

    return 0;
}

