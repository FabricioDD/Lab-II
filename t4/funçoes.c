#include <stdio.h>
#include <stdlib.h>
#include "funçoes.h"


struct mesas** quantas_mesas(int linhas,int colunas){//feito
    struct mesas** matriz_mesas;
    matriz_mesas = malloc(linhas * sizeof(struct mesas*));
    for (int i = 0; i < linhas; i++) {
        matriz_mesas[i] = malloc(colunas * sizeof(Mesas));
    }
    int k=0;
    for (int i=0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            k++;
            matriz_mesas[i][j].num_mesa = k;
            matriz_mesas[i][j].livre = 1; // Inicialmente livre
            matriz_mesas[i][j].pessoas_ocupando = 0; // Inicialmente sem pessoas
            matriz_mesas[i][j].pratos=4;// Inicialmente limpa
            matriz_mesas[i][j].comanda = (i+1)*100+j*10; // Comanda unica pra cada mesa
        }
    }
    return matriz_mesas;
}


void print_restaurante(struct mesas** matriz,int l,int c){//feito
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("Mesa[%d][%d] numero: %d\n%d cadeiras ocupadas\n\n",i,j,matriz[i][j].num_mesa,matriz[i][j].pessoas_ocupando);
        }

    }
}

void print_mesa(struct mesas** matriz,int l,int c){//feito
    printf("Mesa numero: %d\n%d cadeiras ocupadas\n\n",matriz[l][c].num_mesa,matriz[l][c].pessoas_ocupando);
}

void r2(No_Fila* fila){//feito
    if(fila_vazia(fila)){
        printf("Fila de espera se encontra vazia\n\n");
        return;
    }
    int esperando = 0;
    int n=0;
    Fila *aux = fila->ini;
    while (aux != fila->fim) {
        n++;
        esperando += aux->tamanho_grupo;
        printf("\nGrupo %d aguarda por %d lugares", n,aux->tamanho_grupo);
        aux = aux->prox;
    }
    n++;
    esperando += aux->tamanho_grupo;
    printf("\nGrupo %d aguarda por %d lugares", n,aux->tamanho_grupo);
    printf("\n\nUm total de %d pessoas esperam na fila!\n\n", esperando);
}

void r3(Pilha *pratos,int l,int c){//feito
    int p=0;

    for (int i = 0; i < l*c*4; ++i) {
        if(pratos->vet[i]==1){
            p++;
        }else{
            break;
        }
    }
    printf("Existem %d pratos na pilha\n\n",p);
}

void novo_cliente(struct mesas** matriz,int l,int c,Pilha* pratos,No_Fila* fila){//feito
    int q;
    printf("Quantas pessoas tem no grupo? \n");
    scanf("%d", &q);
    int mesa=0;
    int i,j;
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            if (matriz[i][j].livre) {
                mesa=matriz[i][j].num_mesa;
                break;
            }
        }
        if(mesa!=0){ break;}
    }
    if(mesa==0){
        Fila* nova_espera=(Fila*)malloc(sizeof(Fila));
        nova_espera->tamanho_grupo=q;
        if(fila_vazia(fila)){
            nova_espera->senha=1;
        }else{
           nova_espera->senha=fila->fim->senha+1;
        }
        fila_insere(fila,nova_espera);
        return;
    }else{
        matriz[i][j].livre=0;
        while(4 < q){
            q=q-4;
            sub_novo_cliente(matriz,l,c,4,pratos,fila);
        }
        if(matriz[i][j].pratos>=q){
            matriz[i][j].pessoas_ocupando=q;
            matriz[i][j].comanda=(i+1)*100+j*10;
            while(matriz[i][j].pratos!=q){
                matriz[i][j].pratos--;
                pratos->vet[pratos->n]=1;
                pratos->n++;
            }
            printf("Grupo registrado com comanda %d\n\n",(i+1)*100+j*10);
            return;
        }else{
            arrumar_mesa(pratos,matriz,l,c,1,i,j);
            matriz[i][j].pessoas_ocupando=q;
            while(matriz[i][j].pratos>q){
                matriz[i][j].pratos--;
                pratos->vet[pratos->n]=1;
                pratos->n++;
            }
            matriz[i][j].comanda=(i+1)*100+j*10;
            printf("Grupo registrado com comanda %d\n\n",(i+1)*100+j*10);
            return;
        }
    }
}

void sub_novo_cliente(struct mesas** matriz,int l,int c,int q,Pilha* pratos,No_Fila* fila){//feito
    int mesa=0;
    int i,j;
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            if (matriz[i][j].livre) {
                mesa=matriz[i][j].num_mesa;
                break;
            }
        }
        if(mesa!=0){ break;}
    }
    if(mesa==0){
        Fila* nova_espera=(Fila*)malloc(sizeof(Fila));
        nova_espera->tamanho_grupo=q;
        if(fila_vazia(fila)){
            nova_espera->senha=1;
        }else{
            nova_espera->senha=fila->fim->senha+1;
        }
        fila_insere(fila,nova_espera);
        return;
    }else{
        matriz[i][j].livre=0;
        while(4 < q){
            q=q-4;
            sub_novo_cliente(matriz,l,c,4,pratos,fila);
        }
        if(matriz[i][j].pratos>=q){
            matriz[i][j].pessoas_ocupando=q;
            matriz[i][j].comanda=(i+1)*100+j*10;
            printf("Grupo registrado com comanda %d\n\n",(i+1)*100+j*10);
            return;
        }else{
            arrumar_mesa(pratos,matriz,l,c,1,i,j);
            matriz[i][j].pessoas_ocupando=q;
            while(matriz[i][j].pratos>q){
                matriz[i][j].pratos--;
                pratos->vet[pratos->n]=1;
                pratos->n++;
            }
            matriz[i][j].comanda=(i+1)*100+j*10;
            printf("Grupo registrado com comanda %d\n\n",(i+1)*100+j*10);
            return;
        }
    }
}

void liberar_mesa(struct mesas** matriz,No_Fila* fila,int l,int c,Pilha* pratos){
    printf("Qual a mesa que deseja liberar?\n");
    int comp;
    scanf("%d",&comp);
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            if(matriz[i][j].num_mesa==comp){
                if(matriz[i][j].livre==0) {
                    matriz[i][j].pessoas_ocupando = 0;
                    matriz[i][j].livre = 1;
                    arrumar_mesa(pratos, matriz, l, c, 0, i, j);
                    if(!fila_vazia(fila)){
                        Fila* novo_grupo;
                        novo_grupo=fila->ini;
                        fila->ini=novo_grupo->prox;
                        if(fila->ini==NULL){
                            fila->fim=NULL;
                        }
                        sub_novo_cliente(matriz,l,c,novo_grupo->tamanho_grupo,pratos,fila);
                        free(novo_grupo);
                        printf("Mesa recem liberada foi ocupada por um grupo da fila\n");
                    }else{
                        printf("Mesa liberada com sucesso\n");
                    }
                }else{
                    printf("Mesa já esta livre\n");
                }
            }
        }
    }

}

void desitir_fila(No_Fila* fila){
    if(fila_vazia(fila)){
        printf("Fila vazia.\n");
        return;
    }
    Fila * aux1=fila->ini;
    Fila * aux2=fila->ini;
    printf("Qual a senha do seu grupo?\n");
    int n;
    scanf("%d",&n);
    for (; aux1!=NULL; aux1=aux1->prox) {
        if(aux1->senha==n){
            if(aux1==aux2){
                fila->ini=aux1->prox;
                free(aux1);
                if(fila->ini==NULL){
                    fila->fim=NULL;
                }
                printf("Grupo saiu da fila com sucesso\n\n");
                return;
            }
            aux2->prox=aux1->prox;
            free(aux1);
            if(aux2->prox==NULL){
                fila->fim=aux2;
            }
            printf("Grupo saiu da fila com sucesso\n\n");
            return;
        }
        if(aux1!=fila->ini){
            aux2=aux2->prox;
        }

    }
    printf("Seu grupo nao foi encontrado\n\n");
}

void arrumar_mesa(Pilha* pratos,struct mesas** matriz_mesas,int l,int c,int controle,int k, int x){
    if(pratos->vet[0]==1){
        if(controle){
            int aux;
            printf("Qual mesa deseja arrumar?\n");
            scanf("%d",&aux);
            for (int i = 0; i < l; ++i) {
                for (int j = 0; j < c; ++j) {
                    if(matriz_mesas[i][j].num_mesa==aux) {
                        if(matriz_mesas[i][j].livre==1) {
                            if (matriz_mesas[i][j].pratos < 4) {
                                int pratos_necessarios = 4 - matriz_mesas[i][j].pratos;
                                while (pratos_necessarios != 0) {
                                    pratos->vet[pratos->n] = 0;
                                    matriz_mesas[i][j].pratos++;
                                    pratos_necessarios--;
                                    pratos->n--;
                                }
                                printf("Mesa arrumada com sucesso\n");
                            } else {
                                printf("Mesa já esta arrumada\n");
                            }
                        } else{
                            printf("Mesa ocupada\n");
                        }
                    }
                }
            }
        }else{
            int pratos_necessarios = 4 - matriz_mesas[k][x].pratos;
            while (pratos_necessarios != 0) {
                pratos->vet[pratos->n] = 0;
                matriz_mesas[k][x].pratos++;
                pratos_necessarios--;
                pratos->n--;
            }
        }

    } else{
        printf("Pilha de pratos vazia\n\n");
    }
}

void repor_pratos(Pilha* pratos,struct mesas** matriz_mesas,int l,int c){
    int aux;
    printf("Qual o numero da mesa que deseja repor os pratos?\n");
    scanf("%d",&aux);
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            if(matriz_mesas[i][j].num_mesa==aux) {
                if(matriz_mesas[i][j].livre==1) {
                    if (matriz_mesas[i][j].pratos > 0) {
                        while (matriz_mesas[i][j].pratos != 0) {
                            pratos->vet[pratos->n] = 1;
                            matriz_mesas[i][j].pratos--;
                            pratos->n++;
                        }
                        printf("Pratos da mesa foram postos na pilha\n\n");
                        return;
                    } else {
                        printf("Mesa nao possui pratos para repor na pilha\n\n");
                        return;
                    }
                } else{
                    printf("Mesa ocupada\n\n");
                    return;
                }
            }
        }
    }
    printf("Numero de mesa inexitente, busque o relatorios sobre as mesas para ver os numeros das mesas existentes\n\n");
}

