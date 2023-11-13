#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


int main() {
    Lista_clientes *l1=cria_clientes();
    Lista_veiculos *l2=cria_veiculos();
    Lista_locacao *l3=cria_locacao();

    Menu(&l1,&l2,&l3);

    free(l1);
    free(l2);
    free(l3);

    printf("Sistema finalizando.");

    return 0;
}
