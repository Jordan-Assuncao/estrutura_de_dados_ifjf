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
    }
    return atual;
}

void imprime(Aluno *atual)
{
    if (atual == NULL)
    {
        printf("\nLista Vazia!");
    }
    while(atual != NULL)
    {
        printf("\nMatrícula: %d", atual->matricula);
        printf("\nNome.....: %s", atual->nome);
        printf("\nNota.....: %f", atual->nota);
        printf("\n");
        atual = atual->prox;
    }
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
    while (atual != NULL && atual->matricula != matricula){
        atual = atual->prox;
    }
    if(atual == NULL){
        printf("\nAluno não encontrado");
    }else{
        return atual;
    }

}


main(){

    Aluno *listaAluno = NULL;

    Aluno no;

    no.matricula = 111;
    no.nome = "Flavio";
    no.nota = 10.0;
    listaAluno = insereInicio(listaAluno, no);

    no.matricula = 311;
    no.nome = "Flo";
    no.nota = 10.0;
    listaAluno = insereInicio(listaAluno, no);

    no.matricula = 31251;
    no.nome = "o";
    no.nota = 10.0;
    listaAluno = insereFinal(listaAluno, no);
    imprime(listaAluno);

    listaAluno = busca(listaAluno, 0);

    return 0;
}
