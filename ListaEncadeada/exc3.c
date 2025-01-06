#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct no {
    int valor;
    struct no *prox;
} No;

// Função para criar uma lista vazia
No* criar() {
    return NULL;
}

// Função para inserir um nó no início da lista
No* inserir_no(No *inicio, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo) {
        novo->valor = valor;
        novo->prox = inicio;
    }
    return novo;
}

// Função para concatenar duas listas ligadas L1 e L2
No* concatenacao(No *L1, No *L2) {
    if (L1 == NULL) return L2;
    if (L2 == NULL) return L1;

    No *temp = L1;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = L2;
    return L1;
}

// Função para imprimir a lista
void imprimir(No *lista) {
    No *temp = lista;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->prox;
    }
    printf("NULL\n");
}

int main() {
    No *L1 = criar();
    No *L2 = criar();

    //limpa a tela
    system("cls");

    // Inserindo elementos em L1
    L1 = inserir_no(L1, 3);
    L1 = inserir_no(L1, 2);
    L1 = inserir_no(L1, 1);

    // Inserindo elementos em L2
    L2 = inserir_no(L2, 6);
    L2 = inserir_no(L2, 5);
    L2 = inserir_no(L2, 4);

    // Concatenando L1 e L2
    No *L = concatenacao(L1, L2);

    // Imprimindo a lista concatenada
    imprimir(L);

    return 0;
}