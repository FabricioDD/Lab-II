
struct Clientes{
    char cnh[11];
    char nome[20];
    char telefone[16];
};
typedef struct Clientes Cliente;

struct Veiculos {
    char placa[9];
    char marca[16];
    char modelo[16];
    int ano_de_fabricacao;
    float km;
    float valor_diaria;
    int disponibilidade;
};
typedef struct Veiculos Veiculo;

struct data_locacao {
    int dia_retirada;
    int mes_retirada;
    int ano_retirada;
    int dia_devolucao;
    int mes_devolucao;
    int ano_devolucao;
};
typedef struct data_locacao Data;

struct Locacao{
    Veiculo carro;
    Cliente locador;
    Data data;
};
typedef struct Locacao Locacao;


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

Lista_clientes* cria_clientes(void);

Lista_veiculos* cria_veiculos(void);

Lista_locacao* cria_locacao(void);