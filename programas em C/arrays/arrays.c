#include <stdio.h>
#include <stdlib.h>

int i, j;

float** matriz(int l, int c) {
    float **m = (float**) malloc(l * sizeof(float*));
    if (m == NULL) {
        printf("Erro ao alocar memória para a matriz.\n");
        exit(1);
    }

    m[0] = (float*) malloc(l * c * sizeof(float));
    if (m[0] == NULL) {
        printf("Erro ao alocar memória para a matriz.\n");
        free(m);
        exit(1);
    }

    for (i = 1; i < l; i++) {
        m[i] = m[0] + i * c;
    }

    return m;
}

void le(float **m, int l, int c) {
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%f", &m[i][j]);
        }
    }
}

void somar(float **m1, float **m2, float **resultado, int l, int c) {
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            resultado[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void multiplicacao(float **m1, float **m2, float **resultado, int l1, int c1, int c2) {
    for (i = 0; i < l1; i++) {
        for (j = 0; j < c2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                resultado[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void imprime(float **m, int l, int c) {
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("%.2f\t", m[i][j]);
        }
        printf("\n");
    }
}

void liberacao(float **m) {
    free(m[0]);
    free(m);
}

int main() {

    system("cls");

    int l, c;

    printf("Digite o numero de colunas das matrizes: ");
    scanf("%d", &c);

    printf("Digite o numero de linhas da matrizes: ");
    scanf("%d", &l);

    float **m1 = matriz(l, c);
    float **m2 = matriz(l, c);
    float **Soma = matriz(l, c);
    float **Produto = matriz(l, c);

    printf("Digite a matriz 1:\n");
    le(m1, l, c);
    printf("Digite a matriz 2:\n");
    le(m2, l, c);

    somar(m1, m2, Soma, l, c);
    printf("Soma das matrizes:\n");
    imprime(Soma, l, c);

    multiplicacao(m1, m2, Produto, l, c, c);
    printf("Produto das matrizes:\n");
    imprime(Produto, l, c);

    liberacao(m1);
    liberacao(m2);
    liberacao(Soma);
    liberacao(Produto);

    return 0;
}