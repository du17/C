#include <stdio.h>

void swap(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

//função bubble sort
void bubbleSort(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j],&arr[j + 1]);
            }
            
        }
        
    }
    
}

//busca sequencial
//ela é melhor em casos de listas desordenadas ou conjuntos de dados
//pior : O elemento esta na ultima posição ou nao esta no vetor (O(n)).
//melhor : O elemento esta na primeira posição (O(1)).
int buscaSequencial(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // retorna o indice do elemento
        }
    }
    return -1; // nao encontrou
}

//busca binaria
//ela é melhor em casos de grandes listas desordenadas
//pior : O elemento esta na posição ou nao esta no vetor (O(log n)).
//melhor : O elemento esta no meio do vetor (O(1)).
int buscaBinaria(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; // elemento encontrado
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; //nao encontrou
}

int main(){
    int arr[10], n = 10, key, index;

    //testando o bubble sort
    printf("Digite 10 numeros:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //testando a busca
    printf("Digite o numero que quer buscar: ");
    scanf("%d", &key);

    index = buscaSequencial(arr, n, key);
    if (index != -1) {
        printf("Busca sequencial: Elemento %d encontrado no indice %d\n", key, index);
    } 
    
    else {
        printf("Busca sequencial: Elemento %d nao encontrado\n", key);
    }

    //testando busca binaria
    index = buscaBinaria(arr, n, key);
    if (index != -1) {
        printf("Busca binaria: Elemento %d encontrado no indice %d\n", key, index);
    } else {
        printf("Busca binária: Elemento %d nao encontrado\n", key);
    }

    //fim
    
    return 0;
}