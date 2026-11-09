#include <stdio.h>

int **alocamatriz(int qtdlinhas, int qtdcolunas){
    int **Matriz=null;
    int i;

    Matriz=(int**) malloc(qtdlinhas*sizeof(int*));

    for(i=0; i<qtdlinhas; i++){
        Matriz[i]=(int*)malloc(qtdcolunas*sizeof(int));
    }
    return Matriz;
}

void leituramatriz(int** Matriz, int qtdlinhas, int qtdcolunas){
    int i, j;

    for(i=0; i<qtdlinhas; i++){
        for(j=0; j<qtdcolunas; j++){
            printf("Preencha M[%d][%d]: ", i, j);
            scanf("%d", &M[i][j]);
        }
    }
}

bool verificacao(int qtdlinhas, int qtdcolunas){
    if(qtdlinhas==qtdcolunas){
        return true;
    }
    else{
        return false;
    }
}