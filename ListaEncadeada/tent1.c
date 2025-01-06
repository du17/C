#include <stdio.h>
#include <stdlib.h>

//definindo o ponteiro
typedef struct{
    int valor;
    struct no *prox;
}No;

No* CriarNo(No* inicio, int x){
    No *novo;
    novo = malloc(sizeof(struct No*));
    novo->valor = x;
    novo->prox = inicio;
    return novo;
}

void destruirLista(No* inicio, int x){
}

No* Lista(No *inicio, int x){
    return NULL;
}

int main(){

}