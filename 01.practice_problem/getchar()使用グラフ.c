#include <math.h>
#include <stdio.h>


int main(void){
  int i,j,ch;
  int a[10]={0};

while((ch=getchar()) != EOF){
  if(ch>='0' && ch<='9'){
    a[ch-'0']++;
  }
}


printf("----------------------\n");
for(i=0; i<=9; i++){
  printf("%2d|",i);
  for(j=0; j<a[i]; j++){
    putchar('*');
  }
  printf("\n");
}

  return 0;
}
