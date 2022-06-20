#include <stdio.h>
#define NUMBER 100

int main(void){

  int x,y;
  int num;
  int score[NUMBER];
  int area[11] = {0};

  printf("人数を入力してください。");
  do{
    scanf("%d",&num);
    if(num < 1 || num > NUMBER){
      printf("\a1~%dで入力してください:",NUMBER);
    }
  }while(num < 1 || num > NUMBER);

  printf("%d人の点数を入力してください:",num);
  putchar('\n');
  for(x=0; x<num; x++){
    printf("%d番:",x+1);
  do{
    scanf("%d",&score[x]);
    if(score[x] >100 || score[x] < 0){
      printf("\a0~100で入力してください:");
    }
  }while(score[x] >100 || score[x] < 0);
    area[score[x]/10]++;
  }

  printf("------分布グラフ------\n");

  for(x=0; x<10; x++){
    printf("%3d ～%3d:",x*10,x*10+9);
    for(y=0; y<area[x]; y++){
      putchar('*');
    }putchar('\n');
  }

  printf("      100:");
  for(y=0; y<area[10]; y++){
    putchar('*');
  }

  return 0;
}
