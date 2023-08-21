#include <stdio.h>

struct usuario
{
    char sexo;
    int idade;
    int qtdade;
};
typedef struct usuario Usuario;


void leVetor (int tamanho, Usuario* vet){
    for (int i = 0; i < tamanho; ++i) {
        printf("Digite o sexo do usuario %i:\n(m/f): ",i+1);
        scanf(" %c", &vet[i].sexo);
        printf("Digite a idade do usuario %i:\n",i+1);
        scanf("%i", &vet[i].idade);
        printf("Digite a quantidade de livros lidos pelo usuario %i:\n",i+1);
        scanf("%i", &vet[i].qtdade);
    }
}


int calculaQtidadeLivros (int tamanho, Usuario* vet){
    int total=0;
    for (int i = 0; i < tamanho; ++i) {
        if(vet[i].idade<10){
            total = total + vet[i].qtdade;
        }
    }
    return total;
}


int calculaQtidadeMulheres (int tamanho, Usuario* vet){
    int total=0;
    for (int i = 0; i < tamanho; ++i) {
        if(vet[i].sexo=='f'){
            if (4<vet[i].qtdade){
                total++;
            }
        }
    }
    return total;
}


int main(){
    int q;
    printf("Digite a quantidade de usuarios que deseja analizar: \n");
    scanf("%i",&q);
    Usuario vet[q];
    leVetor(q,vet);
    printf("A quantidade total de livros lidos pelos entrevistados menores de 10 anos: %i\n",calculaQtidadeLivros(q,vet));
    printf( "A quantidade de mulheres que leu 5 livros ou mais: %i\n",calculaQtidadeMulheres(q,vet));
}
