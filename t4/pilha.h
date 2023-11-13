#ifndef BIBLIOTECAS_PILHA_H
#define BIBLIOTECAS_PILHA_H

#endif //BIBLIOTECAS_PILHA_H

struct pilha {
    int n;          /* vet[n]: primeira posição livre do vetor */
    int *vet; /* vet[n-1]: topo da pilha */
                /* vet[0] a vet[N-1]: posições ocupáveis */
};
typedef struct pilha Pilha;

Pilha* pilha_cria (int n);

void pilha_libera (Pilha* p);