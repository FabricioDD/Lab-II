#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

No_Fila* fila_cria (void){
    No_Fila* f = (No_Fila*) malloc(sizeof(No_Fila));
    f->ini = f->fim = NULL;
    return f;
}


int fila_vazia(No_Fila* f)
{
    return (f->ini==NULL);
}

void fila_libera (No_Fila* f)

{
    Fila* q = f->ini;
    while (q!=NULL){
        Fila* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}

void fila_insere(No_Fila* fila, Fila* nova_fila) {
    if (fila_vazia(fila)) {
        fila->ini = nova_fila;
        fila->fim = nova_fila;
        printf("Grupo colocado na fila de espera por falta de mesas disponiveis com senha %d\n\n", nova_fila->senha);
        return;
    }
    Fila *aux;
    aux = fila->fim;
    nova_fila->prox = NULL;
    aux->prox=nova_fila;
    fila->fim=nova_fila;
    printf("Grupo colocado na fila de espera por falta de mesas disponiveis com senha %d\n\n", nova_fila->senha);
}
