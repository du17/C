#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct no {
    int valor;
    struct no *prox;
} No;

// Função para percorrer e imprimir os valores da lista
void imprimir(No *inicio) {
    No *atual = inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

// Função para criar um novo nó
No* criar_no(int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

// Função para inserir um novo nó no início da lista
No* inicio(No *inicio, int valor) {
    No *novo = criar_no(valor);
    novo->prox = inicio;
    return novo;
}

int main() {
    No *lista = NULL;

    //limpa a tela
    system("cls");

    // Inserindo alguns valores na lista
    lista = inicio(lista, 10);
    lista = inicio(lista, 20);
    lista = inicio(lista, 30);

    // Imprimindo a lista
    imprimir(lista);

    // Liberando a memória alocada
    No *atual = lista;
    No *temp;
    while (atual != NULL) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }

    return 0;
}