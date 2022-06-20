#include <math.h>
#include <stdio.h>

int main(void){

  int i;
  float x,y;
  float temp,temp2;

  for(x=0.0; x<=1.0; x+=0.01){
    temp += x;
  }

  for(i=0; i<=100; i++){
    y = i/100.0;
    temp2 += y;
  }

printf("浮動小数点数の累計：%f\n",temp);
printf("整数型繰り返しの累計：%f\n",temp2);

  return 0;
}
