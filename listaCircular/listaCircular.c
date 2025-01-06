#include <stdio.h>
#include <stdlib.h>

typedef struct no *p_no;

typedef struct no {
    int valor;
    p_no prox;
};

// Função para criar e inserir um novo nó na lista circular
p_no createFila(p_no lista, int y) {
    p_no novo;
    if (lista == NULL) {
        novo = malloc(sizeof(struct no));
        novo->valor = y;
        novo->prox = novo;
        return novo;
    }
    novo = malloc(sizeof(struct no));
    novo->valor = y;
    novo->prox = lista->prox;
    lista->prox = novo;
    return lista;
}

// Função para imprimir a lista circular
void imprimir(p_no lista) {
    if (lista == NULL) {
        return;
    }
    p_no atual = lista->prox;
    do {
        printf("%d\n", atual->valor);
        atual = atual->prox;
    } while (atual != lista->prox);
}

// Função para concatenar duas listas circulares
p_no concatenar_listas(p_no L1, p_no L2) {
    if (L1 == NULL) return L2;
    if (L2 == NULL) return L1;

    p_no temp = L1->prox;

    // Encontrar o último nó de L1
    while (temp->prox != L1->prox) {
        temp = temp->prox;
    }

    // Conectar o último nó de L1 ao primeiro nó de L2
    temp->prox = L2->prox;

    // Encontrar o último nó de L2
    temp = L2->prox;
    while (temp->prox != L2->prox) {
        temp = temp->prox;
    }

    // Conectar o último nó de L2 ao início de L1
    temp->prox = L1->prox;

    return L1; // Retorna o início da lista concatenada
}

int main() {
    p_no L1 = NULL;
    p_no L2 = NULL;

    // Inserindo elementos em L1
    L1 = createFila(L1, 1);
    L1 = createFila(L1, 2);
    L1 = createFila(L1, 3);

    // Inserindo elementos em L2
    L2 = createFila(L2, 4);
    L2 = createFila(L2, 5);
    L2 = createFila(L2, 6);

    // Concatenando as listas L1 e L2
    L1 = concatenar_listas(L1, L2);

    // Imprimindo a lista concatenada
    imprimir(L1);

    return 0;
}
