#include <math.h>
#include <stdio.h>
#include <ctype.h>

#define x_NUMBER 10
#define y_NUMBER 128

void str_scan(char s[][y_NUMBER], int x){
  int i;
  for(i=0; i<x; i++){
    scanf("%s",s[i]);
      if(s[i][0]=='$' && s[i][1]=='$' && s[i][2]=='$' && s[i][3]=='$' && s[i][4]=='$'){
        break;
      }
  }
}


void put_strary(char s[][y_NUMBER], int x){
  int i;
  for(i=0; i<x; i++){
    if(s[i][0]=='$' && s[i][1]=='$' && s[i][2]=='$' && s[i][3]=='$' && s[i][4]=='$'){
      break;
    }
    printf("s[%d]=%s\n",i,s[i]);
  }
}

int main(void){
  int i;
  char str[x_NUMBER][y_NUMBER];

  str_scan(str,x_NUMBER);
    put_strary(str,x_NUMBER);
  printf("%sと入力されました。",str);

  return 0;
}
