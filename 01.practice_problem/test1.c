#include <math.h>
#include <stdio.h>
#include <ctype.h>

int main(void){
  int a;

  printf("aの値："); scanf("%d",&a);
  // printf("bの値："); scanf("%d",&b);
  // printf("cの値："); scanf("%d",&c);

  while(a>=0){
    printf("%d ",a);
    a-=1;
  }

  return 0;
}
