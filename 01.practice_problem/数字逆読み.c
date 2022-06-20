#include <stdio.h>

int main(void){

  int x;

  do{
    printf("正の整数を入力してください：");
    scanf("%d",&x);

    if(x<0){
      printf("\a0 または負の数です。\n");
    }
  }while(x<=0);

  printf("%dを逆から読むと",x);
  while(x>0){
    printf("%d",x%10);
    x /= 10;
  }
  printf("です。");

  return 0;
}
