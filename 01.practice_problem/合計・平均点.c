#include <stdio.h>
#define NUMBER 100

int main(void){

  int x,y;
  int sum[6]={0};
  double avr[6]={0};
  int kamoku_s[2]={0};
  double kamoku_a[2]={0};
  int score[6][2];

  printf("点数を入力してください:\n");
  for(x=0; x<6; x++){
    printf("%d番:",x+1);
    putchar('\n');
    for(y=0; y<2; y++){
      scanf("%4d",&score[x][y]);
// 学生の合計、平均点ー計算
      sum[x] += score[x][y];
      avr[x] = (double)sum[x]/(y+1);
    }
    putchar('\n');
  }

  // 科目別の合計、平均点ー計算

  for(y=0; y<2; y++){
    for(x=0; x<6; x++){
      kamoku_s[y] += score[x][y];
      kamoku_a[y] = (double)kamoku_s[y]/(x+1);
    }
  }

  // 学生の合計点,平均点
  for(x=0; x<6; x++){
    printf("合計%4d点/平均%4.1f点",sum[x],(double)avr[x]);
    putchar('\n');
  }

// 科目別の合計・平均点
  for(y=0; y<2; y++){
    printf("合計%4d点/平均%4.2f点",kamoku_s[y],(double)kamoku_a[y]);
    putchar('\n');
  }


  return 0;
}
