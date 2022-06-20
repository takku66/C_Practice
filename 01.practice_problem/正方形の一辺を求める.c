#include <math.h>
#include <stdio.h>

double sq_side(double x){
  long double y;
  y = sqrt(x);
  return y;
}


int main(void){

  double x;

  printf("正方形の面積は？：");  scanf("%lf",&x);
  printf("\n一辺の長さは%fです。",sqrt(x));

  return 0;
}
