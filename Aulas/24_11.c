/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int i, contimpar=0, contpar=0;
    int capacidade;
    int *vet=NULL;
    
    printf("Quantos números inteiros vamos guardar: ");
    scanf("%d", &capacidade);
    
    vet=malloc(capacidade*sizeof(int));
    
    printf("Vamos preencher o vetor!\n");
    for (i=0; i<capacidade; i++){
        printf("V[%d]: ", i+1);
        scanf("%d", &vet[i]);
    }
    for (i=0; i<capacidade; i++){
        if (vet[i]%2==0){
            contpar++;
        }
        else{
            contimpar++;
        }
    }
    printf("---- QUANTIDADE NUMEROS PARES E IMPARES ----\n");
    printf("Numeros pares: %d.\n", contpar);
    printf("Numeros impares: %d", contimpar);

    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char sobrenome[100];
    int ano;
}cadastro;


int main(){
    cadastro *cad;
    int capacidade, i;
    

    printf("Digite a quantidade de alunos a serem cadastrados: ");
    scanf("%d", &capacidade);

    cad=malloc(capacidade*sizeof(int));

    for(i=0; i<capacidade; i++){
        printf("aluno %d: ", i+1);

        printf("Digite a Matricula: ");
        scanf("%d", &cad[i].matricula);
        
        printf("Digite o primeiro sobrenome: ");
        scanf("%99s", &cad[i].sobrenome);

        printf("Digite o ano: ");
        scanf("%d", &cad[i].ano);
    }

    printf("----- Tabela de Usuarios -----");
    for (i=0; i<capacidade; i++){
        
        printf("||%s|%d|%d||", cad[i].sobrenome, cad[i].matricula, cad[i].ano);
    }
    free(cad);
}
    */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int **Matriz = NULL;
    int capacidade, i, j, L, C;

    printf("Quantas cidades serao lidas: ");
    scanf("%d", &capacidade);

    Matriz = (int**)malloc(capacidade * sizeof(int*));
    for(j = 0; j < capacidade; j++){
        Matriz[j] = (int*)malloc(capacidade * sizeof(int));
    }

    for(i = 0; i < capacidade; i++){
        for(j = 0; j < capacidade; j++){
            if(i == j){
                Matriz[i][j] = 0;
            }
            else if(j > i){
                printf("Distancia entre a cidade %d e %d: ", i+1, j+1);
                scanf("%d", &Matriz[i][j]);
                Matriz[j][i] = Matriz[i][j];
            }
        }
    }

    printf("Digite quais cidades voce pretende ver a distancia: ");
    scanf("%d %d", &L, &C);

    printf("A distancia entre a cidade %d e %d eh: %d\n", L, C, Matriz[L-1][C-1]);

    for(i = 0; i < capacidade; i++){
        free(Matriz[i]);
    }
    free(Matriz);

    return 0;
}