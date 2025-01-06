#include <stdio.h>
#include <stdlib.h>

void troca(float *v1, float *v2, float r[2]){
  float ax;
  for(int i = 0; i < 2; i++){
    if(*v1 < *v2){
      ax = *v1;
      *v1 = *v2;
      *v2 = ax;
      r[0] = *v1;
      r[1] = *v2;

      printf("O maior valor é: %.2f\n", r[0]);
      printf("O menor valor é: %.2f\n", r[1]);
    }
  }
}

int main(void) {

  system("cls");

  float v1, v2;

  printf("Digite o valor 1: ");
  scanf("%f", &v1);

  printf("Digite o valor 2: ");
  scanf("%f", &v2);

  float r[2] = {v1, v2};

  troca(&v1, &v2, r);
  
  return 0;
}