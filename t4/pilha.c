#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

Pilha* pilha_cria (int n)
{
    struct pilha *p = (struct pilha*)malloc(sizeof(struct pilha));

    if (p == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(1);
    }

    p->n = 0;
    p->vet = (int*)malloc(n * 4 * sizeof(int));

    for (int i = 0; i < n*4; ++i) {
        p->vet[i]=0;
    }
    return p;
}

void pilha_libera (Pilha* p)
{
    free (p);
}