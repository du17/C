#include <stdio.h>
#include <stdlib.h>

int main(){
    int *pont1, x;
    float *pont2, y;
    char *pont3, letra;

    system("cls");
    
    x = 10;
    y = 15.3;
    letra = 'a';

    pont1 = &x;
    pont2 = &y;
    pont3 = &letra;

    printf(" x = %d\n", x);
    printf(" y = %f\n", y);
    printf(" letra = %c\n", letra);

    printf("\n");

    *pont1 = 4;

    *pont2 = 2;

    *pont3 = 'X';

    //apos modificar
    printf(" x = %d\n", x);
    printf(" y = %f\n", y);
    printf(" letra = %c\n", letra);    

    return 0;
}