#include <stdio.h>
#include <string.h>


struct triangulo
{
    int ladoA;
    int ladoB;
    int ladoC;
    char ehTriangulo;
    char tipo[20];
};
typedef struct triangulo Triangulo;


void avalia_trangulo(int l1, int l2, int l3, Triangulo vet) {
    if (l1 >= l2 + l3 || l2 >= l1 + l3 || l3 >= l1 + l2) {
        vet.ehTriangulo = 'n';
    }
    else{
        if (l1 == l2 && l2 == l3)
        {
            vet.ehTriangulo = 's';
            strcpy(vet.tipo, "equilatero");
            return;
        }
        if ((l1 == l2 && (l3 / 2) < l1) || (l2 == l3 && (l1 / 2) < l3) || (l1 == l3 && (l2 / 2) < l1))
        {
            vet.ehTriangulo = 's';
            strcpy(vet.tipo, "isoceles");
            return;
        }
        if (l1 != l2 && l2 != l3 && l1 != l3)
        {
            vet.ehTriangulo = 's';
            strcpy(vet.tipo, "escaleno");
        }
    }
}


void define_valores_triangulo(Triangulo ret[])
{
    for (int i = 0; i < 3; ++i) {
        printf("Digite o lado A do trinagulo %i: \n",i+1);
        scanf("%i",&ret[i].ladoA);
        printf("Digite o lado B do trinagulo %i: \n",i+1);
        scanf("%i",&ret[i].ladoB);
        printf("Digite o lado C do trinagulo %i: \n",i+1);
        scanf("%i",&ret[i].ladoC);
    }
}


void imprime_resultados(Triangulo vet[]){
    for (int i = 0; i < 3; ++i) {
        if (vet[i].ehTriangulo=='n'){
            printf("triangulo inválido");
            continue;
        }
        printf("O trinagulo é valido e é um triangulo %s",vet[i].tipo);
    }
}


int main() {
    Triangulo vet[3];
    define_valores_triangulo(vet);
    for (int i = 0; i < 3; ++i) {
        avalia_trangulo(vet[i].ladoA,vet[i].ladoB,vet[i].ladoC,vet[i]);
    }
    imprime_resultados(vet);
    return 0;

}