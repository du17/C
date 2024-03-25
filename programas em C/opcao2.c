/*#include <stdio.h>
#include <stdlib.h>

#define L 2
#define C 2

int i, j;

void le(float m[][C], int l, int c) {
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("Posicao da matriz [%d][%d]: ", i, j);
            scanf("%f", &m[i][j]);
        }
    }
}

void imprime(float m[][C], int l, int c) {
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("%.2f\t", m[i][j]);
        }
        printf("\n");
    }
}

void sominha(float m1[][C], float m2[][C], float r[][C], int l, int c) {
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            r[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void multiplicao(float m1[][C], float m2[][C], float r[][C], int l, int c) {
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            r[i][j] = m1[i][j] * m2[i][j];
        }
    }
}

int main() {
    float m1[L][C];
    float m2[L][C];
    float soma[L][C];
    float multiplicacao[L][C];

    system("cls");

    printf("Matriz 1:\n");
    le(m1, L, C);

    printf("\nMatriz 2:\n");
    le(m2, L, C);

    printf("\nMatriz 1:\n");
    imprime(m1, L, C);

    printf("\nMatriz 2:\n");
    imprime(m2, L, C);

    sominha(m1, m2, soma, L, C);
    printf("\nSoma das Matrizes:\n");
    imprime(soma, L, C);

    multiplicao(m1, m2, multiplicacao, L, C);
    printf("\nProduto das Matrizes:\n");
    imprime(multiplicacao, L, C);

    return 0;
}*/