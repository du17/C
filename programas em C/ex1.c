#include <stdio.h>
#include <stdlib.h>

int cavalo(int l, int c){
    int mp = 0, i, nl, nc;
    int m[8][2] = {{2, 1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}};

    for(i = 0; i < 8; i++){
        nl = l + m[i][0];
        nc = c + m[i][1];

        if((nl >= 1 && nl <= 8) && (nc >= 1 && nc <= 8)){
            mp++;
        }
    }

    return mp;
}

int main(){
    int l, c, r;

    printf("Digite linha: \n");
    scanf("%i", &l);

    printf("Digite coluna: \n");
    scanf("%i",&c);

    fflush(stdin);

    r = cavalo(l,c);

    system("cls");

    printf("movimentos possiveis: %i", r);

    return 0;
}