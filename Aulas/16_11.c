#include <stdio.h>
#include <stdlib.h>

int *alocavetor(int n){
    int *vet=NULL;
    vet=(int*)malloc(n*sizeof(int));
    return vet;
}

void leitura(int *vet, int n){
    int i;
    for(i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }
}

void imprimevetor(int *vet, int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", vet[i]);
    }
}

void ordenacao(int *vet, int n){
    int aux=0, i, j;
    for(i=n-1; i>0; i--){
        for(j=1; j<=i; j++){
            if(vet[j]<vet[j-1]){
                aux=vet[j];
                vet[j]=vet[j-1];
                vet[j-1]=aux;
            }
        }
    }
}


int main(){
    int n;
    int *vet=NULL;

    printf("Qual tamanho do vetor a ser definido: ");
    scanf("%d", &n);
    vet=alocavetor(n);
    leitura(vet, n);
    ordenacao(vet, n);

    imprimevetor(vet, n);
}
