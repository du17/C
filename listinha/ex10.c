#include <stdio.h>

void calc_esfera(float R, float *area, float *volume){
  *area = 4 * 3.14 * R * 2;
  *volume = 4 / 3 * 3.14 * (R * R * R);
}

int main(void) {

  float area;
  float volume;
  float R;

  printf("Insira o Raio: ");
  scanf("%f", &R);
  
  calc_esfera(R, &area, &volume);

  printf("Area: %.2f\n", area);
  printf("Volume: %.2f", volume);
  return 0;
}