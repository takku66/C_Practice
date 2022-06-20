#include <math.h>
#include <stdio.h>
enum sex{ Man, Woman };
enum season{ Spring, Summer, Autumn, Winter};
enum country{ Japan, America, China, Europe };

void print_sex(enum sex sex){
  switch(sex){
    case Man: printf("男"); break;
    case Woman: printf("女"); break;
  }
}

void print_season(enum season season){
  switch(season){
    case Spring: printf("春"); break;
    case Summer: printf("夏"); break;
    case Autumn: printf("秋"); break;
    case Winter: printf("冬"); break;
  }
}

void print_country(enum country country){
  switch(country){
    case Japan: printf("日本"); break;
    case America: printf("アメリカ"); break;
    case China: printf("中国"); break;
    case Europe: printf("ヨーロッパ"); break;
  }
}

enum sex sex_select(void){
  int tmp;
  do{
    printf("男...0, 女...1:");
    scanf("%d",&tmp);
  }while(tmp<Man || tmp>Woman);

  return (enum sex)tmp;
}

enum season season_select(void){
  int tmp;
  do{
    printf("春...0, 夏...1, 秋...2, 冬...3:");
    scanf("%d",&tmp);
  }while(tmp<Spring || tmp>Winter);

  return (enum season)tmp;
}

enum country country_select(void){
  int tmp;
  do{
    printf("日本...0, アメリカ...1, 中国...2, ヨーロッパ...3:");
    scanf("%d",&tmp);
  }while(tmp<Japan || tmp>Europe);

  return (enum country)tmp;
}

int main(void){

  enum sex your_sex;
  enum season your_season;
  enum country your_country;

  printf("あなたの性別は？"); your_sex = sex_select();
  printf("あなたの生まれた季節は？\n"); your_season = season_select();
  printf("あなたの生まれた国は？\n"); your_country = country_select();

  printf("あなたは");  print_sex(your_sex);
  printf("で、");
  print_season(your_season); printf("に");
  print_country(your_country); printf("に生まれたんですね。");


  return 0;
}
