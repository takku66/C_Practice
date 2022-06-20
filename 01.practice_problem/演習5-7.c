#include <stdio.h>
#define num 100

int main(void){

  int x,y;
  int i[num];


  printf("データ数:");    scanf("%d",&x);

  for(y=0; y<x; y++){
    printf("%d番：",y+1); scanf("%d",&i[y]);
  }

  putchar('{');
  for(y=0; y<x; y++){
    printf("%d",i[y]);
    if(y==x-1){
      break;
    }
    printf(", ");

  }
  putchar('}');


  return 0;
}
