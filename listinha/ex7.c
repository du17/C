#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int vet[5], result[5], i; 

    int *it = vet;

    for(i = 0; i < 5; i++){
        printf("Digite um valor :");
        scanf("%d", &it[i]);
    }
    
    for(i = 0; i < 5; i++){
        result[i] = it[i] * 2;
    }
    

    for(i = 0; i < 5; i++){
        printf("valor %d = %d\n", i +1, result[i]);
    }
    
    return 0;
}