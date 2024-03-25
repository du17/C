#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"

int main(){
    int x, y,r;
    char o;

    printf("Escolha uma operacao matematica: \n");
    printf(" +  = soma\n");
    printf(" -  = subtracao\n");
    printf(" *  = multiplicacao\n");
    printf(" /  = divisao\n");
    printf(" Operacao: ");
    o = getchar();

    system("cls");

    printf("Digite um numero: ");
    scanf(" %i", &x);

    printf("Digite outro numero: ");
    scanf(" %i", &y);

    printf("\n");

    switch (o){
    case '+':
       r = soma(x,y);
        break;

    case '-':
        r = subtracao(x,y);
        break;

    case '*':
        r = produto(x,y);
        break;

    case '/':
        r = divisao(x,y);
        break;

    default:
        printf("Operacao invalida");
        break;
    }

    printf("Resultado = %i\n",r);

    system("pause");
    
    return 0;
}