#include <stdio.h>
#define num 7

int main(void){

  int i,temp;
  int x[num];

  for(i=0; i<num; i++){
    printf("x[%d]:",i);
    scanf("%d",&x[i]);
  }
  for(i=0; i<num/2; i++){
    temp = x[i];
    x[i] = x[num-1-i];
    x[num-1-i] = temp;
  }

  printf("反転後\n");
  for(i=0; i<num; i++){
  printf("x[%d] = %d\n",i,x[i]);
  }

  return 0;
}
