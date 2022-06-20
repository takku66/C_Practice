#include <stdio.h>
#define NUMBER 6

void rev_intary(int v[], int n){
  int i;

  for(i=0; i<NUMBER/2; i++){
    int temp = v[i];
    v[i] = v[NUMBER-1-i];
    v[NUMBER-1-i] = temp;
  }
}

void print_array(const int v[], int n){
  int i;
  printf("{ ");
  for(i=0; i<NUMBER; i++){
    printf("%d ",v[i]);
  }

  printf(" }");
}

int main(void){

  int x,y,z;
  int ary[NUMBER];

  printf("%d個の数字を入力：\n",NUMBER);
  for(x=0; x<NUMBER; x++){
    printf("[%d]:",x+1);  scanf("%d",&ary[x]);
  }

  rev_intary(ary, NUMBER);
  print_array(ary,NUMBER);

  return 0;
}
