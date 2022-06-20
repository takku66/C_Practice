#include <math.h>
#include <stdio.h>
#define NUMBER 5

void bsort(int x[],int n){
  int i,j;

  for(i=0; i<n-1; i++){
    for(j=0; j<n-1; j++){
      if(x[j]>x[j+1]){
        int tmp = x[j];
        x[j] = x[j+1];
        x[j+1] = tmp;
      }
    }
  }
}

int main(void){
  int i;
  int height[NUMBER];

  printf("%d人の身長を入力してください。",NUMBER);
  for(i=0; i<NUMBER; i++){
    printf("\n%d人目：",i+1);
    scanf("%d",&height[i]);
  }

  bsort(height,NUMBER);

  printf("ソートしました。");
  for(i=0; i<NUMBER; i++){
    printf("\n一人目：%d",height[i]);
  }

  return 0;
}
