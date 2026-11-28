#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct {
    int dia;
    int mes;
 } aniversario;

typedef struct {
    char nome[50];
    char telefone[100];
    aniversario niver;
}Contato;


void inserircontato(Contato **agenda, int *qtd, int *capacidade){
    if(*qtd==*capacidade){
        int nova_cap=*capacidade*2
        Contato **temp= realloc(*agenda, (size_t)nova_cap*sizeof(Contato));
    if (temp==NULL){
        printf("Erro ao Realocar Memória.");
        return;
    }
    *agenda=temp;
    *capacidade=nova_cap;
    }
    Contato novo;

    printf("Nome: ");
    scanf(" %s", novo.nome);

    printf("Telefone: ");
    scanf(" %s", novo.telefone);

    printf("Aniversário, Dia e Mês: ");
    scanf("%d %d", &novo.niver.dia, &novo.niver.mes);

    int pos=0;
    while(pos<*qtd && strcmp((*agenda)[pos].nome, novo.nome)<0){
        pos++;
    }

    for(int i=*qtd; i>pos; i--){
        *agenda[i]=*agenda[i-1];
    }

    (*agenda)[pos]=novo;
    (*qtd)++;
    printf("Contato Inserido.");
}

void removercontato(Contato *agenda, int *qtd){
    if(*qtd==0){
        printf("Agenda Vazia.\n");
        return;
    }

    char alvo[50];
    printf("Digite o Nome do usuário a ser excluído: ");
    scanf(" %s", alvo);

    int idx = -1;

    for (i=0; i<*qtd; i++){
        if(strcmp(agenda[i].nome, alvo) == 0){
        idx = i;
        break;
        }
    }

    if(idx == -1){
        printf("Usuário não encontrado.\n");
        return;
    }

    for(i=idx; i<*qtd-1; i++){
        agenda[i] = agenda[i+1];
    }

    (*qtd)--;
    printf("Usuário removido.\n");
}
