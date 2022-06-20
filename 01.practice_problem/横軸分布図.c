#include <stdio.h>
#define NUMBER 100

int main(void){

  int x,y;
  int num;
  int score[NUMBER];
  int area[11] = {0};

// 入力エリア

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

// グラフエリア

  int max=0;//分布の最大値
  for(x=0; x<num; x++){
    if(max<area[x]){
      max = area[x];
    }
  }

// printf("%d",max);テストok

  for(x=max; x>0; x--){
    for(y=0; y<=10; y++){
      if(area[y]==x){
        printf("   *");
      }else if(area[y]==max){
        printf("   *");
      }else{
        printf("    ");
      }
    }
    putchar('\n');
  }

      for(x=0; x<=10; x++){
        printf("----");
      }
    putchar('\n');
      for(x=0; x<=10; x++){
        printf("%4d",x*10);
      }






/*
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
*/
  return 0;
}
