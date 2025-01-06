#include <stdio.h>
#include <stdlib.h>

int somas(int *a, int *b){
    int result;

    *a = *a + *a;

    *b = *b + *b;

    result = *a + *b;

    return result;
}

int main(){
    system("cls");

    int a, b, r;

    printf("Digite um numero : ");
    scanf("%d", a);

    printf("digite outro numero : ");
    scanf("%d", b);

    r = somas(&a, &b);

    printf("resultado : %d", r);
}