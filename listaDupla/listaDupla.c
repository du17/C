#include <stdio.h>
#include <stdlib.h>

// Definição do nó em uma lista duplamente ligada
typedef struct no *p_no;

struct no {
    int valor;
    p_no ant, prox;
};

// Função para inserir um nó no início da lista
p_no inserir_no_inicio(p_no inicio, int valor) {
    // Aloca memória para o novo nó
    p_no novo = (p_no)malloc(sizeof(struct no));
    if (novo == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    // Define o valor do novo nó
    novo->valor = valor;
    
    // Ajusta os ponteiros do novo nó
    novo->prox = inicio;
    novo->ant = NULL;

    // Se a lista não estiver vazia, ajusta o ponteiro anterior do antigo primeiro nó
    if (inicio != NULL) {
        inicio->ant = novo;
    }

    // O novo nó se torna o primeiro da lista
    return novo;
}

// Função para imprimir a lista (para fins de teste)
void imprimir_lista(p_no lista) {
    p_no temp = lista;
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->prox;
    }
    printf("\n");
}

int main() {
    p_no lista = NULL;

    //limpa a tela
    system("cls");

    // Inserindo nós no início da lista
    lista = inserir_no_inicio(lista, 10);
    lista = inserir_no_inicio(lista, 20);
    lista = inserir_no_inicio(lista, 30);

    // Imprimindo a lista
    imprimir_lista(lista);

    return 0;
}
