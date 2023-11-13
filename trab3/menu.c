#include "menu.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct ListaDeVeiculos ListaDeVeiculos;

int Menu(Lista_clientes** l1, Lista_veiculos** l2, Lista_locacao** l3){
    while(1){
    printf("Locadora de veiculos\n\n"
           "1. incluir veiculos\n"
           "2. listar veiculos\n"
           "3. incluir clientes\n"
           "4. listar clientes\n"
           "5. realizar locacao\n"
           "6. devolver veiculo\n"
           "7. listar locacoes\n"
           "8. relatorios\n"
           "9. finalizar sessao\n");
    int n;
    scanf("%d", &n);
    switch (n) {
        case 1:
            cadastra_veiculo(l2);
            break;
        case 2:
            lista_veiculos(l2);
            break;
        case 3:
            cadastra_cliente(l1);
            break;
        case 4:
            lista_clientes(l1);
            break;
        case 5:
            realizar_locacao(l1,l2, l3);
            break;
        case 6:
            devolver_veiculo(l2,l3);
            break;
        case 7:
            listar_locacoes(l3);
            break;
        case 8:
            //relatorios(l1,l2,l3);
            break;
        case 9: {
            return 0;
        }
    }
}
}



void cadastra_veiculo(Lista_veiculos** l){
    Lista_veiculos *novoVeiculo=(struct ListaDeVeiculos*) malloc(sizeof(ListaDeVeiculos));

    printf("Placa:");
    scanf("%s", novoVeiculo->veiculo.placa);

    Lista_veiculos *p=*l;
    for (; p->prox != NULL ; p= (Lista_veiculos *) p->prox) {
        if(strcmp(p->veiculo.placa,novoVeiculo->veiculo.placa)==0){
            printf("ha um veiculo com a mesma placa já registrada ja registrado.\n");
            return;
        }
    }
    free(p);

    printf("Marca:");
    scanf("%s", novoVeiculo->veiculo.marca);

    printf("Modelo:");
    scanf("%s", novoVeiculo->veiculo.modelo);

    printf("Ano de Fabricacao:");
    scanf("%d", &novoVeiculo->veiculo.ano_de_fabricacao);

    printf("Kilometragem:");
    scanf("%f", &(novoVeiculo->veiculo.km));

    printf("Valor da Diaria:");
    scanf("%f", &(novoVeiculo->veiculo.valor_diaria));

    printf("Disponibilidade(1 para disponivel, 0 para indisponivel):");
    scanf("%d", &(novoVeiculo->veiculo.disponibilidade));

    novoVeiculo->prox = (struct ListaDeVeiculos *) *l;
    *l = novoVeiculo;
    free(novoVeiculo);
}

void lista_veiculos(Lista_veiculos** l){
    Lista_veiculos *p=*l;
    for (p; p->prox!=NULL ; p= (Lista_veiculos *) p->prox) {
        printf("VEICULO:\n");
        printf("  placa = %s\n", p->veiculo.placa);
        printf("  marca = %s\n", p->veiculo.marca);
        printf("  modelo = %s\n", p->veiculo.modelo);
        printf("  ano de fabricacao = %d\n", p->veiculo.ano_de_fabricacao);
        printf("  kilometros rodados = %f\n", p->veiculo.km);
        if(p->veiculo.disponibilidade==1) {
            printf("  disponibilidade = Disponivel\n");
        }else {
            printf("  disponibilidade = Indisponivel\n");
        }
        printf("  valor diario = %.2f",p->veiculo.valor_diaria);
    }
    printf("\n\n");
}




void cadastra_cliente(Lista_clientes** l){
    Lista_clientes* novoCliente = (Lista_clientes*) malloc(sizeof(Lista_clientes));
    printf(" CNH: ");
    scanf(" %s", novoCliente->cliente.cnh);

    Lista_clientes *p=*l;
    for (; p->prox != NULL ; p= (Lista_clientes *) p->prox) {
        if(strcmp(p->cliente.cnh,novoCliente->cliente.cnh)==0){
            printf("CNH do cliente ja registrado.\n");
            return;
        }
    }
    free(p);

    printf("Nome: ");
    scanf(" %s", novoCliente->cliente.nome);

    printf("Telefone: ");
    scanf(" %s", novoCliente->cliente.telefone);

    novoCliente->prox = (struct ListaDeClientes *) *l;
    *l = novoCliente;
    free(novoCliente);
}

void lista_clientes(Lista_clientes** l){
Lista_clientes *p=*l;
    for (p; p->prox!=NULL ; p= (Lista_clientes *) p->prox) {
        printf("CLIENTE:\n");
        printf("  CNH = %s\n", p->cliente.cnh);
        printf("  nome = %s\n", p->cliente.nome);
        printf("  telefone = %s\n", p->cliente.telefone);
    }
    printf("\n\n");
}

void realizar_locacao(Lista_clientes** l1,Lista_veiculos** l2, Lista_locacao** l3){
    Lista_locacao* novaLocacao=(Lista_locacao*) malloc(sizeof (Lista_locacao));
    char cnh[10];
    printf("CNH do locador: ");
    scanf(" %s", cnh);
    Lista_clientes *p=*l1;
    for (; p->prox != NULL ; p= (Lista_clientes *) p->prox) {
        if(strcmp(p->cliente.cnh,cnh)==0){
            novaLocacao->locador = &p->cliente;
        }
    }
    if(novaLocacao->locador==NULL){
        printf("locador nao registrado\n");
        return;
    }
    char placa[9];
    printf("Placa: ");
    scanf("%s", placa);
    Lista_veiculos *c=*l2;
    for (; c->prox != NULL ; c= (Lista_veiculos *) c->prox) {
        if(strcmp(c->veiculo.placa,placa)==0){
            if(c->veiculo.disponibilidade==0){
                printf("veiculo indisponivel.\n\n");
                return;
            }
            novaLocacao->carro = &c->veiculo;
            novaLocacao->carro->disponibilidade=0;
        }
    }
    if(novaLocacao->carro==NULL){
        printf("carro nao registrado\n");
        return;
    }
    printf("quando deseja retirar o carro?\ndia: ");
    scanf(" %d",novaLocacao->data.dia_retirada);
    printf("mes: ");
    scanf(" %d",novaLocacao->data.mes_retirada);
    printf("ano: ");
    scanf(" %d",novaLocacao->data.ano_retirada);
    printf("quando deseja retornar o carro?\ndia: ");
    scanf(" %d",novaLocacao->data.dia_devolucao);
    printf("mes: ");
    scanf(" %d",novaLocacao->data.mes_devolucao);
    printf("ano: ");
    scanf(" %d",novaLocacao->data.ano_devolucao);
    novaLocacao->prox = *l3;
    *l3 = novaLocacao;
    free(novaLocacao);
    printf("locacao concluida.");
}

void devolver_veiculo(){

}

void listar_locacoes(Lista_locacao** l){
    Lista_locacao *p=*l;
    for (p; p->prox!=NULL ; p= (Lista_locacao *) p->prox) {
        printf("LOCACAO:\n\n");
        printf(" Locador\n");
        printf("  CNH = %s\n", p->locador->cnh);
        printf("  nome = %s\n", p->locador->nome);
        printf("  telefone = %s\n\n", p->locador->telefone);
        printf(" Veiculo:\n");
        printf("  placa = %s\n", p->carro->placa);
        printf("  marca = %s\n", p->carro->marca);
        printf("  modelo = %s\n", p->carro->modelo);
        printf("  ano de fabricacao = %d\n", p->carro->ano_de_fabricacao);
        printf("  kilometros rodados = %f\n", p->carro->km);
        printf("  valor diario = %.2f",p->carro->valor_diaria);
        printf("  data de retirada: %d/%d/%d\n", p->data.dia_retirada,p->data.mes_retirada,p->data.ano_retirada);
        printf("  data de devolucao: %d/%d/%d\n",p->data.dia_devolucao,p->data.mes_devolucao,p->data.ano_devolucao);
    }
    printf("\n\n");
}

/*void relatorios(){
    printf("1. listar todas as locações ativas em uma certa data\n"
           "2. listar todas as locações já realizadas por um cliente\n"
           "3. listar o faturamento da locadora por mês\n"
           "4. listar a placa dos 3 veículos mais rodados\n"
           "5. listar a placa e o modelo de todos os veículos disponíveis\n"
           "6. voltar");
           int n;
    switch (n) {
        case 1:
            r1();
            break;
        case 2:
            r2();
            break;
        case 3:
            r3();
            break;
        case 4:
            r4();
            break;
        case 5:
            r5();
            break;
        case 6:
            Menu();
            break;

    }

}
*/
