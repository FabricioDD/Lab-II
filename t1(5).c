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


void leVetor (int tamanho, Aluno* vet){
    for (int i = 0; i < tamanho; ++i) {
        printf("Digite a primeira nota do aluno %i:\n ",i+1);
        scanf(" %f", &vet[i].nota1);
        printf("Digite a segunda nota do aluno %i:\n",i+1);
        scanf("%f", &vet[i].nota2);
        printf("Digite a quantidade de aulas assistidas pelo aluno %i:\n",i+1);
        scanf("%i", &vet[i].aulasAssistidas);
    }
}


void aulasMinistradas(Disciplina* dis){
    printf("Digite a quantidade de aulas ministradas pelo professor:\n");
    scanf("%i", &dis->aulasMinistradas);
}


char* verificarAprovacao(char status) {
    if (status == 'A') {
        return "Aprovado";
    } else if (status == 'B') {
        return "Reprovado";
    }
}

void avaliaMediaEPrinta(Disciplina dis){
    for (int i = 0; i < 5; ++i) {

        if ((dis.aulasMinistradas/4)*3 > dis.vet[i].aulasAssistidas){
            dis.vet[i].status='B';
            dis.vet[i].media=(dis.vet[i].nota1 + dis.vet[i].nota2)/2;
            printf("Aluno %i\nMedia final: %.2f\nSituacao: %s\n" ,i+1 ,dis.vet[i].media, verificarAprovacao(dis.vet[i].status));
            continue;
        }else{
            dis.vet[i].media=(dis.vet[i].nota1 + dis.vet[i].nota2)/2;
            if(dis.vet[i].media<6){
                dis.vet[i].status='B';
                printf("Aluno %i\nMedia final: %.2f\nSituacao: %s\n" ,i+1 ,dis.vet[i].media, verificarAprovacao(dis.vet[i].status));
                continue;
            }else{
                dis.vet[i].status='A';
                printf("Aluno %i\nMedia final: %.2f\nSituacao: %s\n" ,i+1 ,dis.vet[i].media, verificarAprovacao(dis.vet[i].status));
                continue;
            }
        }
    }
}

int main(){
    Disciplina dis;
    aulasMinistradas(&dis);
    leVetor(5,dis.vet);
    avaliaMediaEPrinta(dis);
    return 0;
}