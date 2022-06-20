#include <stdio.h>

int main(void){

  int x,y,z;

  printf("正方形を作ります。\n何段ですか：");  scanf("%d",&x);

  for(y=1; y<=x; y++){
    for(z=1; z<=x; z++){
    putchar('*');
  }
  printf("\n");
  }

  return 0;
}
