#include <stdio.h>
#include <stdlib.h>

void valores(float *v1, float *v2){
}

int main(){

    system("cls");

    float v1 = 5, v2 = 2;

    valores(&v1, &v2);


}

/*
void maiorMenor(float *a, float *b, float result[2]){
  float aux;
  for(int i = 0; i < 2; i++){
    if(*a < *b){
      aux = *a;
      *a = *b;
      *b = aux;
      result[0] = *a;
      result[1] = *b;

      printf("O maior valor é: %.2f\n", result[0]);
      printf("O menor valor é: %.2f\n", result[1]);
    }
  }
}

int main(void) {

  float v1, v2;

  printf("Digite o primeiro valor: ");
  scanf("%f", &v1);

  printf("Digite o segundo valor: ");
  scanf("%f", &v2);

  float result[2] = {v1, v2};

  maiorMenor(&v1, &v2, result);

  /*printf("O maior valor é: %.2f\n", v1);
  printf("O menor valor é: %.2f\n", v2);
  
  return 0;
}*/