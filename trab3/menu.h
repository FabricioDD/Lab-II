#include "structs.h"

struct ListaDeClientes{
    Cliente cliente;
    struct ListaDeClientes *prox;
};
typedef struct ListaDeClientes Lista_clientes;

struct ListaDeVeiculos{
    Veiculo veiculo;
    struct ListaDeVeiculos *prox;
};
typedef struct ListaDeVeiculos Lista_veiculos;

struct ListaDeLocacao{
    Veiculo* carro;
    Cliente* locador;
    Data data;
    struct ListaDeLocacao *prox;
};
typedef struct ListaDeLocacao Lista_locacao;

int Menu(Lista_clientes** l1,Lista_veiculos** l2, Lista_locacao** l3);

void cadastra_veiculo(Lista_veiculos **l);

void lista_veiculos(Lista_veiculos** l);

void cadastra_cliente(Lista_clientes** l);

void lista_clientes(Lista_clientes** l);

void realizar_locacao(Lista_clientes** l1,Lista_veiculos** l2, Lista_locacao** l3);

void devolver_veiculo();

void listar_locacoes(Lista_locacao** l);

//void relatorios();