#include "funçoes.h"
#include <stdio.h>
#include <stdlib.h>


void menu_secundario_r1(struct mesas** matriz_mesas,int linhas,int colunas){
    printf("Pesquisar:\n\n"
           "1) Todas as mesas\n"//(número da mesa e quantidade de pessoas que ocupam a mesa)
           "2) Mesa unica\n"//(número da mesa e quantidade de pessoas que ocupam a mesa)
           "3) voltar\n");
    int n;
    scanf("%d", &n);
    switch (n) {
        case 1:
            print_restaurante(matriz_mesas,linhas,colunas);
            break;
        case 2:
            printf("Mesa de qual linha e coluna(comecando do zero):\n");
            int l,c;
            scanf("%d",&l);
            scanf("%d",&c);
            print_mesa(matriz_mesas,l,c);
            break;
        default:
            printf("Opcao invalida\n");
    }
}



void relatorios(struct mesas** matriz_mesas,int linhas,int colunas,Pilha* pratos,No_Fila* fila){
    printf("Relatorios\n\n"
            "1) Ocupacao das mesas\n"//(número da mesa e quantidade de pessoas que ocupam a mesa) - o usuário pode pesquisar
    //por número de mesa ou então consultar todas as mesas;
           "2) Fila de espera\n"//(quantos grupos estão na fila de espera, e quantas pessoas aguardam na fila de espera. Por ex:
    //grupo 1 aguarda por 3 lugares, grupo 2 aguarda por 5 lugares, logo há 2 grupos aguardando, e um total de 8 pessoas
    //esperam na fila);
           "3) Pilha de pratos\n"//(quantos pratos existem na pilha de pratos).
           "4) Voltar\n");
    int n;
    scanf("%d", &n);
    switch (n) {
        case 1:
            menu_secundario_r1(matriz_mesas,linhas,colunas);
            break;
        case 2:
            r2(fila);
            break;
        case 3:
            r3(pratos,linhas,colunas);
            break;
        case 4:
            return;
        default:
            printf("Opcao invalida\n");
    }

}


int Menu(){
    int linhas, colunas;
    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);
    struct mesas** matriz_mesas=quantas_mesas(linhas,colunas);
    Pilha* pratos= pilha_cria(linhas*colunas);
    No_Fila* fila=fila_cria();
    while(1){
        printf("Sistema de Restaurante\n\n"
               "1) Novo grupo de clientes \n"
               "2) Finalizar refeicao/liberar mesa\n"//(liberar a mesa, chamar clientes da fila de espera (se houver), e arrumar mesa)
               "3) Desistir de esperar\n"//(sair da fila de espera)
               "4) Arrumar mesa \n"//(retirar pratos da pilha)
               "5) Repor pratos \n"//(adicionar pratos na pilha)
               "6) Relatorios\n"//Imprimir pilha de pratos, fila de espera e ocupação das mesas\n");
               "7) Finalizar\n");
        int n;
        scanf("%d", &n);
        switch (n) {
            case 1:
                novo_cliente(matriz_mesas,linhas,colunas,pratos,fila);
                break;
            case 2:
                liberar_mesa(matriz_mesas,fila,linhas,colunas,pratos);
                break;
            case 3:
                desitir_fila(fila);
                break;
            case 4:
                arrumar_mesa(pratos,matriz_mesas,linhas,colunas,1,0,0);
                break;
            case 5:
                repor_pratos(pratos,matriz_mesas,linhas,colunas);
                break;
            case 6:
                relatorios(matriz_mesas,linhas,colunas,pratos,fila);
                break;
            case 7:
                pilha_libera(pratos);
                fila_libera(fila);
                for (int i = 0; i < linhas; i++) {
                    free(matriz_mesas[i]);
                }
                free(matriz_mesas);
                return 0;
            default:
                printf("Opcao invalida\n");
        }
    }
}


int main() {
    Menu();
    return 0;
}
