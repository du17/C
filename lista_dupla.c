#include <stdio.h>
#include <stdlib.h>

typedef struct no *p_no;

struct no {
    int valor;
    p_no ant, prox;
};

p_no inserir_primeiro(p_no inicio, p_no * fim, int x) {
  p_no novo;
  novo = malloc(sizeof(struct no));
  novo->valor = x;
  novo->ant = NULL;
  novo->prox = NULL;
  *fim = novo;
  return novo;
}

p_no inserir(p_no lista, int valor) {
    p_no novo = malloc(sizeof(struct no));
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = lista;
    if (lista != NULL)
        lista->ant = novo;
    return novo;
}

void imprimir(p_no inicio) {
    p_no atual;
    for (atual = inicio; atual != NULL; atual = atual->prox)
        printf("%d\n", atual->valor);
}

void imprimir_invertido(p_no fim) {
    p_no atual;
    for (atual = fim; atual != NULL; atual = atual->ant)
        printf("%d\n", atual->valor);
}

void destruir_lista(p_no lista) {
    if (lista != NULL) {
        destruir_lista(lista->prox);
        free(lista);
    }
}

int main() {

    return 0;

}