#include <stdio.h>

int main(void){

  int x;
  int retry;

  do{

    printf("整数を入力してください:");   scanf("%d",&x);
    if(x%2 == 0){
      printf("偶数です。\n");
    }else{
      printf("奇数です。\n");
    }

    printf("続けますか？ Yes...[0]  No...[1]:");
    scanf("%d",&retry);
  }while(retry == 0);


  return 0;
}
