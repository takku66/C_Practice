#include <stdio.h>

int main(void){

  int x,y,z,i;
  int sum=0;
  printf("何cmから:"); scanf("%d",&x);
  printf("何cmまで:"); scanf("%d",&y);
  printf("何cmごと:"); scanf("%d",&z);

  for(i=0; x<=y; i+=z){
    printf("%dcm   %.2fkg\n",x,(x-100)*0.9);
    x+=z;
  }

  return 0;
}
