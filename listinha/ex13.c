#include <stdio.h>
#include <stdlib.h>


int potencia(int k, int n) {

    if (n == 0) {
        return 1;
    }

    else if (n % 2 != 0) {
        return k * potencia(k, n - 1);
    }

    else {
        int var = potencia(k, n / 2);
        return var * var;
    }
}

int main() {
    int k, n, result;

    printf("Digite o valor de k: ");
    scanf("%d", &k);

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    result = potencia(k, n);

    printf("%d elevado a %d é igual a %d\n", k, n, result);

    return 0;
}