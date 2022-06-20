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

  unsigned set(unsigned x, int pos){
    int i=int_bits()-1-pos;



  }
  unsigned reset(unsigned x, int pos){}
  unsigned inverse(unsigned x, int pos){}



int main(void){

  float x;
  double y;
  long double z;

  printf("float型の数字："); scanf("%f",&x);
  printf("\ndouble型の数字："); scanf("%f",&y);
  printf("\nlong double型の数字："); scanf("%Lf",&z);

  printf("\nfloat型の数字：%u",(unsigned)sizeof(x));
  printf("\ndouble型の数字：%u",(unsigned)sizeof(y));
  printf("\nlong double型の数字：%lu",(unsigned)sizeof(z));


  return 0;
}
