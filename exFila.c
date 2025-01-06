#include<stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 100

typedef struct{
    int itens[TAMANHO_MAX];
    int frente;
    int traseira;
}Fila;

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->frente = 0;
    f->traseira = -1;
}

// Verifica se a fila está vazia
int isVazia(Fila *f) {
    return f->traseira < f->frente;
}

// Verifica se a fila está cheia
int isCheia(Fila *f) {
    return f->traseira == TAMANHO_MAX - 1;
}

// Insere um elemento na fila
void enqueue(Fila *f, int item) {
    if (isCheia(f)) {
        printf("Fila cheia!\n");
    } else {
        f->traseira++;
        f->itens[f->traseira] = item;
    }
}

// Remove um elemento da fila
int dequeue(Fila *f) {
    if (isVazia(f)) {
        printf("Fila vazia!\n");
        return-1;  // Valor de erro
    } else {
        int item = f->itens[f->frente];
        f->frente++;
        return item;
    }
}

// Consulta o elemento da frente da fila sem removê-lo
int peek(Fila *f) {
    if (isVazia(f)) {
        printf("Fila vazia!\n");
        return-1;  // Valor de erro
    } else {
        return f->itens[f->frente];
    }
}

// Exibe todos os elementos da fila
void exibirFila(Fila *f) {
    if (isVazia(f)) {
        printf("Fila vazia!\n");
    } else {
        for (int i = f->frente; i <= f->traseira; i++) {
            printf("%d ", f->itens[i]);
        }
        printf("\n");
    }
}

// Programa principal para testar a fila
int main() {
    Fila fila;
    inicializarFila(&fila);

    enqueue(&fila, 1);
    enqueue(&fila, 2);
    enqueue(&fila, 3);

    printf("Elemento removido: %d\n", dequeue(&fila));  // Saída: 1
    printf("Elemento na frente: %d\n", peek(&fila));    // Saída: 2

    exibirFila(&fila);  // Saída: 2 3
    return 0;
}