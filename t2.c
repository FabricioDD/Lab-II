#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void tamanho_matriz(int *colunas, int *linhas){
    printf("Defina o tamanho do caca palavras:\n");
    printf("Numero de colunas:\n");
    scanf(" %d",colunas);
    printf("Numero de linhas:\n");
    scanf(" %d",linhas);
}


char** aloca_matriz(int l, int c)
{
    char** mat;
    int i;
    mat=(char**)malloc(l * sizeof(char*));
    if (mat==NULL)
    {
        printf ("\nErro de alocacao de memoria.");
        system("pause");
        exit(1);
    }
    for (i=0; i < l; i++)
    {
        mat[i]=(char*)malloc(c * sizeof(char));
        if (mat[i]==NULL)
        {
            printf ("\nErro de alocacao de memoria.");
            system("pause");
            exit(1);
        }
    }
    return mat;
}


void print_mat(char** mat,int c, int l){
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%c",mat[j][i]);
        }
        printf("\n");
    }
}


void preenche_matriz_string(char** mat,int c, int l){
    char string[c*l];
    printf("Digite o texto:\n");
    scanf(" ");
    fgets(string, c*l+1, stdin);

    int contador_l=0,contador_c=0;

    for (int i = 0; i < strlen(string)+1; ++i) {
        mat[contador_c][contador_l]=string[i];
        contador_c++;
        if(contador_c == c){
            contador_c=0;
            contador_l++;
            if(contador_l == l){
                break;
            }
        }
    }
    print_mat(mat,c,l);
}


void horizontal_direita(char** mat, int c_inicial,int l_inicial,char const string[],int limite,int i,int c){
    if(c_inicial+i==c){
        return;
    }
    if (string[i]!=mat[c_inicial+i][l_inicial]){
        return;
    }else if(limite==2 && string[i]==mat[c_inicial+i][l_inicial]){
        printf("Palavra %s ocorre na horizontal, iniciando na\n"
               "posicao [%d,%d] e terminando na posicao [%d,%d]\n",string,c_inicial+1,l_inicial+1,c_inicial+i+1,l_inicial+1);
        return;
    }else{
        horizontal_direita(mat,c_inicial,l_inicial,string,limite-1,i+1,c);
    }
}
void horizontal_esquerda(char** mat, int c_inicial,int l_inicial,char const string[],int limite,int i){
    if(c_inicial-i==-1){
        return;
    }
    if (string[i]!=mat[c_inicial-i][l_inicial]){
        return;
    }else if(limite==2 && string[i]==mat[c_inicial+i][l_inicial]){
        printf("Palavra %s ocorre na horizontal reversa, iniciando na\n"
               "posicao [%d,%d] e terminando na posicao [%d,%d]\n",string,c_inicial+1,l_inicial+1,c_inicial-i+1,l_inicial+1);
        return;
    }else{
        horizontal_esquerda(mat,c_inicial,l_inicial,string,limite-1,i+1);
    }
}
void diagonal_cima_direita(char** mat, int c_inicial,int l_inicial,char const string[],int limite,int i,int c){
    if(c_inicial+i==c || l_inicial-i==-1){
        return;
    }
    if (string[i]!=mat[c_inicial+i][l_inicial-i]){
        return;
    }else if(limite==2 && string[i]==mat[c_inicial+i][l_inicial]){
        printf("Palavra %s ocorre na diagonal secundaria direta, iniciando na\n"
               "posicao [%d,%d] e terminando na posicao [%d,%d]\n",string,c_inicial+1,l_inicial+1,c_inicial+i+1,l_inicial-i+1);
        return;
    }else{
        diagonal_cima_direita(mat,c_inicial,l_inicial,string,limite-1,i+1,c);
    }
}
void diagonal_baixo_direita(char** mat, int c_inicial,int l_inicial,char const string[],int limite,int i,int c,int l){
    if(c_inicial+i==c || l_inicial+i==l){
        return;
    }
    if (string[i]!=mat[c_inicial+i][l_inicial+i]){
        return;
    }else if(limite==2 && string[i]==mat[c_inicial+i][l_inicial]){
        printf("Palavra %s ocorre na diagonal principal direta, iniciando na\n"
               "posicao [%d,%d] e terminando na posicao [%d,%d]\n",string,c_inicial+1,l_inicial+1,c_inicial+i+1,l_inicial+i+1);
        return;
    }else{
        diagonal_baixo_direita(mat,c_inicial,l_inicial,string,limite-1,i+1,c,l);
    }
}
void diagonal_cima_esquerda(char** mat, int c_inicial,int l_inicial,char const string[],int limite,int i){
    if(c_inicial-i==-1 || l_inicial-i==-1){
        return;
    }
    if (string[i]!=mat[c_inicial-i][l_inicial-i]){
        return;
    }else if(limite==2 && string[i]==mat[c_inicial+i][l_inicial]){
        printf("Palavra %s ocorre na horizontal secundaria reversa, iniciando na\n"
               "posicao [%d,%d] e terminando na posicao [%d,%d]\n",string,c_inicial+1,l_inicial+1,c_inicial-i+1,l_inicial-i+1);
        return;
    }else{
        diagonal_cima_esquerda(mat,c_inicial,l_inicial,string,limite-1,i+1);
    }
}
void diagonal_baixo_esquerda(char** mat, int c_inicial,int l_inicial,char const string[],int limite,int i,int l){
    if(c_inicial-i==-1 || l_inicial+i==l){
        return;
    }
    if (string[i]!=mat[c_inicial-i][l_inicial+i]){
        return;
    }else if (limite==2 && string[i]==mat[c_inicial+i][l_inicial]){
        printf("Palavra %s ocorre na diagonal secundaria reversa, iniciando na\n"
               "posicao [%d,%d] e terminando na posicao [%d,%d]\n",string,c_inicial+1,l_inicial+1,c_inicial-i+1,l_inicial+i+1);
        return;
    }else{
        diagonal_baixo_esquerda(mat,c_inicial,l_inicial,string,limite-1,i+1,l);
    }
}
void vertical_cima(char** mat, int c_inicial, int l_inicial, char const string[], int limite, int i){
    if(l_inicial-i==-1){
        return;
    }
    if (string[i]!=mat[c_inicial][l_inicial-i]){
        return;
    }else if(limite==2 && string[i]==mat[c_inicial+i][l_inicial]){
        printf("Palavra %s ocorre na vertical reversa, iniciando na\n"
               "posicao [%d,%d] e terminando na posicao [%d,%d]\n",string,c_inicial+1,l_inicial+1,c_inicial+1,l_inicial-i+1);
        return;
    }else{
        vertical_cima(mat, c_inicial, l_inicial, string, limite - 1, i + 1);
    }
}
void vertical_baixo(char** mat, int c_inicial, int l_inicial, char const string[], int limite, int i, int l){
    if(l_inicial+i==l){
        return;
    }
    if (string[i]!=mat[c_inicial][l_inicial+i]){
        return;
    }else if(limite==2 && string[i]==mat[c_inicial+i][l_inicial]){
        printf("Palavra %s ocorre na vertical, iniciando na\n"
               "posicao [%d,%d] e terminando na posicao [%d,%d]\n",string,c_inicial+1,l_inicial+1,c_inicial+1,l_inicial+i+1);
        return;
    }else{
        vertical_baixo(mat, c_inicial, l_inicial, string, limite - 1, i + 1, l);
    }
}


void confere(char** mat, int c_inicial,int l_inicial,char const string[],int limite,int c,int l){
    horizontal_direita(mat,c_inicial,l_inicial,string,limite,1,c);
    horizontal_esquerda(mat,c_inicial,l_inicial,string,limite,1);
    diagonal_cima_direita(mat,c_inicial,l_inicial,string,limite,1,c);
    diagonal_baixo_direita(mat,c_inicial,l_inicial,string,limite,1,c,l);
    diagonal_cima_esquerda(mat,c_inicial,l_inicial,string,limite,1);
    diagonal_baixo_esquerda(mat,c_inicial,l_inicial,string,limite,1,l);
    vertical_cima(mat, c_inicial, l_inicial, string, limite, 1);
    vertical_baixo(mat, c_inicial, l_inicial, string, limite, 1, l);
}


void procura_matriz(char** mat,int c,int l){
    printf("digite uma palavra para procurar no caca palavras:\n");
    scanf(" ");
    char string[300];
    fgets(string,sizeof(string),stdin);
    int limite =(int)strlen(string);
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            if(string[0]==mat[j][i]){
                if(limite==2){
                    printf("Palavra %s ocorre na posicao [%d,%d]\n",string,j+1,i+1);
                    continue;
                }else{
                    confere(mat,j,i,string,limite-1,c,l);
                }
            }
        }
    }
}


int main() {
    int c,l;
    tamanho_matriz(&c, &l);
    char** mat=aloca_matriz(l,c);
    preenche_matriz_string(mat,c, l);
    procura_matriz(mat,c,l);
    return 0;
}