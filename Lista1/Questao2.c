#include <stdio.h>
#include <stdlib.h>

int *alocarmemoriaest(int estrelas){
    int *vet=(int *)malloc(estrelas*sizeof(int));
    return vet;
}
int *alocarmemoriavis(int estrelas){
    int *visitadas=(int *)calloc(estrelas, sizeof(int));
    return visitadas;
}

void preenchersitio(int estrelas, int *contcarneiros, int *vet){
    int i, aux;
    for(i=0; i<estrelas; i++){
        printf("Quantos carneiros tem no %dº sitio: ", i+1);
        scanf("%d", &aux);
        vet[i]=aux;
        *contcarneiros+=aux;
    }
}
void visitinhas(int *n, int *ataques, int *roubados, int estrelas, int *vet, int *visitadas){

    while (*n>=0 && *n<estrelas){
        int era_impar = (vet[*n] % 2 != 0);
        if(visitadas[*n]==0){
            visitadas[*n]=visitadas[*n]+1;
            (*ataques)++;
        }
            if(vet[*n]>0){
                vet[*n]--;
                (*roubados)++;
            }
        
        if(era_impar){
            (*n)++;
        }else{
            (*n)--;
        }
    }
}

int main(){
    int estrelas;
    int ataques=0, roubadas=0, contcarneiros=0;
    int *vet=NULL;
    int *visitadas=NULL;
    int n=0;
    int Nroubadas;

    printf("Digite o número de estrelas: ");
    scanf("%d", &estrelas);
    vet = alocarmemoriaest(estrelas);
    visitadas = alocarmemoriavis(estrelas);

    preenchersitio(estrelas, &contcarneiros, vet);

    visitinhas(&n, &ataques, &roubadas, estrelas, vet, visitadas);

    Nroubadas=contcarneiros-roubadas;

    printf("A QUANTIDADE DE ESTRELAS ATACADAS FORAM DE: %d\n", ataques);
    printf("A QUANTIDADE DE CARNEIROS NÃO ROUBADOS FORAM DE: %d", Nroubadas);
    free(vet);
    free(visitadas);
}