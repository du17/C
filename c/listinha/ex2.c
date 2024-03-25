#include <stdio.h>
#include <stdlib.h>

void troca(int *A, int *B){
    int ax;
     ax = *A;
     *A = *B;
     *B = ax;
}

int main(){

    system("cls");

    int A, B;

    printf("Digite um valor : ");
    scanf("%d", &A);

    printf("digite outro valor : ");
    scanf("%d", &B);

    troca(&A,&B);

    printf("A = %d\n" , A);
    printf("B = %d\n", B);

}