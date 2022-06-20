#include <stdio.h>
#define NUMBER 6
#define FAILED -1

void mat_mul(const int a[4][3], const int b[3][4], int c[4][4]){
  int i,j;
  int mn=0;
  int k;

  for(i=0; i<4; i++){
    for(j=0; j<4; j++){
      for(mn=k=0; k<3; k++){
          mn+=a[i][k] * b[i][j];
      }
      c[i][j]=mn;
    }
  }
}

void mat_print(const int m[4][4]){
  int i,j;

  for(i=0; i<4; i++){
    for(j=0; j<4; j++){
      printf("%4d ",m[i][j]);
    }
    printf("\n");
  }
}



int main(void){
  int i,j;
  int num1[4][3] = { {1, 2, 3}, {4, 5, 6}, { 7, 8, 9}, {10, 11, 12} };
  int num2[3][4] = { {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
  int mul[4][4];

  mat_mul(num1,num2,mul);
printf("num1の数字\n");
  for(i=0; i<4; i++){
    for(j=0; j<3; j++){
      printf("%4d ",num1[i][j]);
    }
    printf("\n");
  }
      printf("\n");
      printf("num2の数字\n");
  for(i=0; i<3; i++){
    for(j=0; j<4; j++){
      printf("%4d ",num2[i][j]);
    }
    printf("\n");
  }
      printf("\n");
  mat_print(mul);

  return 0;
}
