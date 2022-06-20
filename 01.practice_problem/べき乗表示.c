#include <stdio.h>

int main(void){

  int x,y;
  int i=2;

  printf("正の整数を入力してください。:");
  scanf("%d",&x);

  while(i<x){

    printf("%d ",i);
    i *= 2;
  }

  if(x>0){
    printf("\n");
  }

  return 0;
}
