#include <stdio.h>
#include <stdlib.h>

typedef struct no *p_no;

struct no {
    int valor;
    p_no prox;
};

p_no criar_lista() {
	return NULL;
}

p_no inserir_no(p_no lista, int x) {
	p_no novo;
	novo = malloc(sizeof(struct no));
	novo->valor = x;
	novo->prox = lista;
	return novo;
}

void imprimir(p_no lista) {
	p_no atual;
	for (atual = lista; atual != NULL; atual = atual->prox)
		printf("%d\n", atual->valor);
}

// versão recursiva
/*
void imprimir_recursivo(p_no lista) {
	if (lista != NULL) {
		printf("%d\n", lista->valor);
		imprimir_recursivo(lista->prox);
	}
}
*/

void destruir_lista(p_no lista) {
	if (lista != NULL) {
		destruir_lista(lista->prox);
		free(lista);
	}
}

// versão iterativa (exercício)
/*
void destruir_lista(p_no lista) {
	p_no p = lista, aux;
	while (p != NULL) {
		aux = p->prox;
		free(p);
		p = aux;
	}
}
*/

p_no remover(p_no primeiro, int x) {
   	if (primeiro == NULL) 
    	return NULL;
    primeiro->prox = remover(primeiro->prox, x);
    if (primeiro->valor == x) {
        p_no proximo = primeiro->prox;
        free(primeiro);
        return proximo;
    }
    return primeiro;
}

p_no concatenar_lista(p_no primeira, p_no segunda) { 
	if (primeira == NULL)
		return segunda;
	primeira->prox = concatenar_lista(primeira->prox, segunda); 
	return primeira;
}

p_no inverter_lista(p_no inicio) {
	p_no aux1, aux2=NULL, atual=inicio;

	while (atual != NULL) {
		aux1 = atual->prox;
		atual->prox = aux2;
		aux2 = atual;
		atual = aux1;
	}
	return aux2;
}

void dividir(p_no lista, p_no * lista1, p_no * lista2) {
  p_no atual=lista;
  int contador=0,meio,i;
  float divisao,resto;

  while(atual!=NULL)
  {
     contador++;
     atual=atual->prox;
  }
  
  meio = contador/2;

  *lista1 = lista;
  for(i=0; i<meio; i++)
     lista=lista->prox;
  *lista2 = lista->prox;
  lista->prox = NULL;

}

int no_central(p_no lista) {
  p_no atual=lista;
  int contador=0,meio,i;
  float divisao,resto;

  while(atual!=NULL)
  {
     contador++;
     atual=atual->prox;
  }
  
  meio=contador/2;

  for(i=0;i<meio;i++)
     lista=lista->prox;
  return lista->valor;

}

int main() {

	return 0;

}