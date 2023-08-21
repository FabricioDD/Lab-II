#include <stdio.h>


struct aluno
{
    float nota1;
    float nota2;
    int aulasAssistidas;
    float media;
    char status;
};
typedef struct aluno Aluno;
struct disciplina
{
    Aluno vet[5];
    int aulasMinistradas;
};
typedef struct disciplina Disciplina;

//Faça um programa que leia a quantidade de aulas ministradas em uma disciplina. Para esta disciplina
//informada, considere 5 alunos. Para cada aluno, leia as duas notas obtidas pelo aluno na disciplina e o número de
//aulas assistidas. A seguir, calcule e mostre a média final deste aluno e verifique se ele foi aprovado (status = ‘A’) ou
//reprovado (status = ‘B’). Condição para ser aprovado: média >= 6 e mínimo de 75% de frequência.


void leVetor (int tamanho, Aluno* vet){
    for (int i = 0; i < tamanho; ++i) {
        printf("Digite a primeira nota do aluno %i:\n(m/f): ",i+1);
        scanf(" %f", &vet[i].nota1);
        printf("Digite a segunda nota do aluno %i:\n",i+1);
        scanf("%f", &vet[i].nota2);
        printf("Digite a quantidade de aulas assistidas pelo aluno %i:\n",i+1);
        scanf("%i", &vet[i].aulasAssistidas);
    }
}


void aulasMinistradas(Disciplina dis){
    printf("Digite a quantidade de aulas ministradas pelo professor:");
    scanf("%i", &dis.aulasMinistradas);
}


void avaliaMediaEPrinta(Disciplina dis){
    float porcento= 0.75*dis.aulasMinistradas;
    for (int i = 0; i < 5; ++i) {
        if (dis.vet[i].aulasAssistidas<=porcento){
            dis.vet[i].status='B';
            dis.vet[i].media=(dis.vet[i].nota1 + dis.vet[i].nota2)/2;
            printf("Aluno %i\nMedia final: %f\nSituacao: reprovado\n" ,i ,dis.vet[i].media);
            continue;
        }else{
            dis.vet[i].media=(dis.vet[i].nota1 + dis.vet[i].nota2)/2;
            if(dis.vet[i].media<6){
                dis.vet[i].status='B';
                printf("Aluno %i\nMedia final: %f\nSituacao: reprovado\n" ,i ,dis.vet[i].media);
                continue;
            }else{
                dis.vet[i].status='A';
                printf("Aluno %i\nMedia final: %f\nSituacao: aprovado\n" ,i ,dis.vet[i].media);
                continue;
            }
        }
    }
}

int main(){
    Disciplina dis;
    aulasMinistradas(dis);
    leVetor(5,dis.vet);
    avaliaMediaEPrinta(dis);
    return 0;
}