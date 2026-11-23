#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int code;
    int qtd;
}Info;
typedef struct{
    char nome[50];
    char descrition[100];
    Info info;
}gaveta;

void Realocar(gaveta **armario, int *capacidade, int *quant){
    if(*quant==*capacidade){
        int nova_cap = (*capacidade) + 1;
        gaveta *temp = realloc(*armario, (size_t)nova_cap * sizeof(gaveta));
        if (temp == NULL){
            printf("Erro ao realocar memoria!\n");
            return;
        }
        *armario = temp;
        *capacidade = nova_cap;

    }

}


void Adicionarprodutos(gaveta **armario, int *capacidade, int *quant){
    Realocar(armario, capacidade, quant);

    gaveta nova;
    printf("Nome: ");
    scanf(" %49[^\n]", nova.nome);

    printf("Descrition: ");
    scanf(" %99[^\n]", nova.descrition);

    printf("code: ");
    scanf("%d", &nova.info.code);

    printf("Quantidade: ");
    scanf("%d", &nova.info.qtd);

    (*armario)[*quant] = nova;
    (*quant)++;
    printf("Produto Adicionado com sucesso!");
}

void Removerprodutos(gaveta *armario, int *quant){
    if(*quant == 0){
        printf("Agenda Vazia!\n");
        return;
    }
    char alvo[50];
    printf("Digite o nome do produto a remover: ");
    scanf(" %49[^\n]", alvo);

    int idx=-1;
    for(int i=0; i<*quant; i++){
        if(strcmp(armario[i].nome, alvo)==0){
            idx = i;
            break;
        }
    }

    if(idx==-1){
        printf("Produto não encontrado.\n");
        return;
    }

    for (int i=idx; i<*quant-1; i++){
        armario[i]=armario[i+1];
    }
    (*quant)--;
    printf("Contato removido com sucesso.\n");
}

void Relatoriogeral(const gaveta *armario, int *quant){
    if(quant == 0){
        printf("\nNenhum produto cadastrado na dispensa.\n");
        return;
    }
    printf("---- Relatorio Geral ----\n");
    for(int i=0; i<quant; i++){
        printf("%d | Nome: %c | Descricao: %c | Codigo: %d | Quantidade: %d |\n", i+1, armario[i].nome,armario[i].descrition, armario[i].info.code, armario[i].info.qtd);

    } 
}
int main(void){
    int capacidade=5;
    int quant=0;
    
    gaveta *armario = malloc((size_t)capacidade * sizeof(gaveta));
    if(armario == NULL){
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    
    int d=0;
    char add[20];
    printf("---- Dispensa Domestica ----\n");
    printf("1 - Adicionar Produtos.\n");
    printf("2 - Remover Produtos.\n");
    printf("3 - Relatorio Geral Produtos.\n");
    printf("4 - Produtos Nao Disponiveis.\n");
    printf("Oque voce deseja executar: ");
    scanf("%d", &d);
    switch (d){
        case 1:{
            char resp = 'S';
            while(resp =='S' || resp == 's'){
                Adicionarprodutos(&armario, &capacidade,&quant);
                printf("Quer adicionar outro produto S / N: ");
                scanf(" %c", &resp);
            }
            break;
        }
        case 2: {
            Removerprodutos(armario, &quant);
            break;
        }
        case 3: {
            Relatoriogeral(armario, &quant);
            break;
        }

}
}