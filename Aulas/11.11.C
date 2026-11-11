#include <stdio.h>
#include <string.h>
typedef struct {
    int dia;
    int mes;
 } aniversario;

typedef struct {
    char nome[50];
    char telefone;
    aniversario niver;
}Contato;


Contato* Alocavetor(int capacidadeInicial) {
    Contato *vetor = malloc(capacidadeInicial * sizeof(Contato));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria inicial!\n");
        exit(1);
    }
    return vetor;
}

void inserirContato( Contato **vetorContatos, int *qtdContatos, int *capacidade){
    if (*qtdContatos>=*capacidade){
        *capacidade *= 2;
    }
    Contato *temp = realloc(*vetorContatos, (*capacidade) * syzeof(Contato))
    if(temp==NULL){
        printf("Erro ao realocar memoria!\n");
        exit(1);
    }
    *vetirContatos = temp;
}
Contato novo;
    printf("\n--- Novo Contato ---\n");
    printf("Digite o nome: ");
    scanf(" %s", novo.nome);
    printf("Digite o telefone: ");
    scanf(" %s", novo.telefone);
    printf("Digite o dia do aniversario: ");
    scanf("%d", &novo.niver.dia);
    printf("Digite o mes do aniversario: ");
    scanf("%d", &novo.niver.mes);