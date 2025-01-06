#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    system("cls");
    setlocale(LC_ALL, "Portuguese");

    float *vet = malloc(10*sizeof(float));
    int i;

    if(!vet){
        printf("Espaço de memoria insuficiente.");
        return;
    }

    float *it = vet;

    for(i=0; i<5; i++){
        *it = 10+i;
        it++;
    }

    for(i=0; i<5; i++){
        printf("valor = %.2f\n", vet[i]);
        printf("endereço do valor : %p\n", &vet[i]);
    }
    
    return 0;
}