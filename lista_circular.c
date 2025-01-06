#include <stdio.h>
#include <stdlib.h>

typedef struct no *p_no;

struct no {
    int valor;
    p_no prox;
};

p_no inserir(p_no lista, int x) {
  p_no novo;
  if (lista == NULL) {
    novo = malloc(sizeof(struct no));
    novo->valor = x;
    novo->prox = novo;
    return novo;
  }
  novo = malloc(sizeof(struct no));
  novo->valor = x;
  novo->prox = lista->prox;
  lista->prox = novo;
  return lista;
}

void imprimir(p_no lista) {
  p_no atual = lista->prox;
  do {
    printf("%d\n", atual->valor);
    atual = atual->prox;
  } while (atual != lista->prox);
}

p_no concatenar(p_no lista1, p_no lista2) {
  p_no aux = lista2->prox;
  lista2->prox = lista1->prox;
  lista1->prox = aux;
  return lista1;
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