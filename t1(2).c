#include <stdio.h>

struct retangulo {
    float base;
    float altura;
    float perimetro;
    float area;
};
typedef struct retangulo Retangulo;

void define_valores_retangulos(Retangulo ret[])
{
    for (int i = 0; i < 5; ++i) {
        printf("Digite a largura da base do retangulo %i: \n",i+1);
        scanf("%f",&ret[i].base);
        printf("Digite a altura do retangulo %i: \n",i+1);
        scanf("%f",&ret[i].altura);
    }

}

void calculaPeriArea (Retangulo ret[])
{
    for (int i = 0; i < 5; ++i) {
        ret[i].perimetro=(ret[i].base+ret[i].altura)*2;
        ret[i].area=ret[i].base*ret[i].altura;
        printf("O retangulo %i tem perimetro %.3f e area %.3f\n",i+1,ret[i].perimetro,ret[i].area);
    }
}

int main(){
    Retangulo vet[5];
    define_valores_retangulos(vet);
    calculaPeriArea(vet);
return 0;
}