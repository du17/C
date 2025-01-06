#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef No* p_no;

// Função para remover todas as ocorrências de x na lista
void remover(p_no *lista, int x) {
    p_no atual = *lista;
    p_no anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == x) {
            if (anterior == NULL) {
                // Removendo o primeiro nó
                *lista = atual->prox;
            } else {
                // Removendo um nó intermediário ou final
                anterior->prox = atual->prox;
            }
            p_no temp = atual;
            atual = atual->prox;
            free(temp);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

// Função para inserir um novo nó no início da lista
p_no inserir_no(p_no inicio, int x) {
    p_no novo = malloc(sizeof(No));
    novo->valor = x;
    novo->prox = inicio;
    return novo;
}

// Função para imprimir os valores da lista
void imprimir(p_no lista) {
    p_no atual;
    for (atual = lista; atual != NULL; atual = atual->prox) {
        printf("%d\n", atual->valor);
    }
}

int main() {
    p_no lista = NULL;

    //limpa a tela
    system("cls");

    // Inserir valores na lista
    lista = inserir_no(lista, 10);
    lista = inserir_no(lista, 7);
    lista = inserir_no(lista, 23);
    lista = inserir_no(lista, 12);
    lista = inserir_no(lista, 7);
    lista = inserir_no(lista, 10);

    printf("Lista original:\n");
    imprimir(lista);

    int x;
    printf("Digite o valor a ser removido: ");
    scanf("%d", &x);

    remover(&lista, x);

    printf("Lista após remover todas as ocorrências de %d:\n", x);
    imprimir(lista);

    return 0;
}