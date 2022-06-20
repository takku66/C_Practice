#include <stdio.h>

int main(void){

  int x,y,z;

  puts("整数を入力してください。");
  printf("整数A：");      scanf("%d",&x);
  printf("整数B：");      scanf("%d",&y);
  printf("整数C：");      scanf("%d",&z);

  // int min = x;
  //
  // if(x>y){
  //   min = y;
  // }
  // if(x>z){
  //   min = z;
  // }
  printf("最小値は%dです。",(x<y) ? (x<z)?x:z : (y<z)?y:z);

  return 0;
}
