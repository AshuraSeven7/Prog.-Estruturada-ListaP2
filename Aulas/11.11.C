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