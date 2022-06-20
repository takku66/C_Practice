#include <stdio.h>

int main(void){

  int x,y;
  int sum=0;
  int cnt;
  int z;

    puts("2つの整数を入力してください。");

    printf("整数A:");   scanf("%d",&x);
    printf("整数B:");   scanf("%d",&y);

    if(x>y){
      cnt = x-y;
    }else{
      cnt = y-x;
    }

    z = (x>y) ? y:x;

    do{

      sum = sum +z;
      cnt = cnt-1;
      z = z+1;

  }while(cnt >= 0);

  printf("%d以上、%d以下の整数値の合計は%dです。",x,y,sum);

  return 0;
}
