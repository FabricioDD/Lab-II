#include "structs.h"
#include "menu.h"
#include <stdlib.h>


Lista_clientes* cria_clientes(void){
    return (Lista_clientes *) malloc(sizeof(Lista_clientes));
}

Lista_veiculos* cria_veiculos(void){
    return (Lista_veiculos *) malloc(sizeof(Lista_veiculos));
}

Lista_locacao* cria_locacao(void){
    return (Lista_locacao *) malloc(sizeof(Lista_locacao));
}