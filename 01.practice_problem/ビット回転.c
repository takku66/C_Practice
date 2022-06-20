#include <stdio.h>

  int count_bits(unsigned x){
    int bits=0;

    while(x){
      if(x&1U) bits++;

    x>>=1;
  }
    return bits;
  }

  int int_bits(void){
    return count_bits(~0U);
  }

  void print_bits(unsigned x){
    int i;
    for(i = int_bits()-1; i>=0; i--){
      putchar(((x>>i)&1U) ? '1':'0');
    }
  }

  unsigned rrotate(unsigned x,int n){
    int i;
    for(i=0; i<n; i++){
      if(x&1U){
        unsigned y = ~x;
        y>>=1;
        x = ~y;
      }else{
        x>>=1;
      }
    }
    return x;
  }


  unsigned lrotate(unsigned x,int n){
    int i;
    unsigned m=int_bits()-1;
    for(i=0; i<n; i++){
      if((x>>m)&1U){
        unsigned y = ~x;
        y<<=1;
        x = ~y;
      }else{
        x<<=1;
      }
    }
    return x;
  }



int main(void){

  unsigned a=5,b=4;
  int n = 5;

  printf("\na = ");print_bits(a);
  printf("\nb = ");print_bits(b);
/*
  int i;
  for(i=0; i<n; i++){
    if(a&1U){
      unsigned y = ~a;
      y>>=1;
      a = ~y;
    }else{
      a>>=1;
    }
  }
  printf("\na = ");print_bits(a);
*/


  printf("\na = ");print_bits(rrotate(a,n));
  printf("\na = ");print_bits(lrotate(a,n));


  printf("\nb = ");print_bits(rrotate(b,n));
  printf("\nb = ");print_bits(lrotate(b,n));


  return 0;
}
