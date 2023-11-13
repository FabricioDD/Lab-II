#ifndef T4_FUNÇOES_H
#define T4_FUNÇOES_H

#endif //T4_FUNÇOES_H
#include "pilha.h"
#include "fila.h"

struct mesas{
    int num_mesa;
    int livre;
    int pessoas_ocupando;
    int pratos;
    int comanda;
};

typedef struct mesas Mesas;

struct mesas** quantas_mesas(int linhas,int colunas);

void print_restaurante(struct mesas** matriz,int l,int c);

void print_mesa(struct mesas** matriz,int l,int c);

void r2(No_Fila* fila);

void r3(Pilha *pratos,int l,int c);

void novo_cliente(struct mesas** matriz,int l,int c,Pilha* pratos, No_Fila* fila);

void sub_novo_cliente(struct mesas** matriz,int l,int c,int q,Pilha* pratos, No_Fila* fila);

void liberar_mesa(struct mesas** matriz,No_Fila* fila,int l,int c,Pilha* pratos);

void desitir_fila(No_Fila* fila);

void arrumar_mesa(Pilha* pratos,struct mesas** matriz_mesas,int l,int c,int controle,int i, int j);

void repor_pratos(Pilha* pratos,struct mesas** matriz_mesas,int l,int c);