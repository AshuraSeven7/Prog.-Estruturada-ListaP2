#include <stdio.h>

int main(){
    int *vetor=NULL;
    int n=5, i;
    char nome[50];
    FILE *arquivo=NULL;

    //alocando
    vetor=(int*)malloc(n*sizeof(int));
    
    //preenchendo
    for(i=0; i<n; i++){
        scanf("%d", vetor[i]);
    }

    printf("Digite um nome: ");
    scanf("%s", nome);
    
    arquivo = fopen(nome,"w");

    vetor=
}