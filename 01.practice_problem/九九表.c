#include <stdio.h>

int main(void){

  int x,y,i,j;

  for(i=1; i<=2; i++){
    if(i==1){
    printf("   |");
    for(j=1; j<=9; j++){
      printf("%3d",j);
    }
  }else if(i==2){
    printf("---+");
    for(j=1; j<=9; j++){
      printf("---");
    }
  }
    printf("\n");
  }

  for(x=1; x<=9; x++){
    printf("%2d |",x);
    for(y=1; y<=9;y++){
      printf("%3d",x*y);
    }
    printf("\n");
  }

  return 0;
}
