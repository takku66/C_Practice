#include <stdio.h>

int main(void){

  int x,y,i;

  printf("ピラミッドを作ります。\n何段ですか:");      scanf("%d",&x);
  // 空白=x-i個
  // *=2i-1

  for(i=1; i<=x; i++){
    for(y=1; y<=i-1; y++){
      putchar(' ');
    }
    for(y=1; y<=x*2-i*2+1; y++){
      printf("%d",i%10);
    }
    for(y=1; y<=i-1; y++){
      putchar(' ');
    }
    printf("\n");
  }


  return 0;
}
