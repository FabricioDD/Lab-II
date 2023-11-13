#ifndef BIBLIOTECAS_FILA_H
#define BIBLIOTECAS_FILA_H

#endif //BIBLIOTECAS_FILA_H

typedef struct fila {
    int senha;
    int tamanho_grupo;
    struct fila *prox;
} Fila;

typedef struct no_fila {
    Fila* ini;
    Fila* fim;
} No_Fila;

No_Fila* fila_cria (void);

void fila_insere (No_Fila* f, Fila* v);

int fila_vazia (No_Fila* f);

void fila_libera (No_Fila* f);