#include <stdio.h>
#include <stdlib.h>

void mulplicacoResto(float *A, float *B){
    float m, r;

    m = *A  *  *B;

    r = (int)*A  %  (int)*B;

    printf("Produto : %.2f\nResto : %.2f\n", m, r);
}

int main(){

    system("cls");

    float a, b;

    printf("digite um numero :");
    scanf("%f", &a);

    printf("digite outro numero : ");
    scanf("%f", &b);

    mulplicacoResto(&a, &b);

    return 0;
}