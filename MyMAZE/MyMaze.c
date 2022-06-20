#include <stdio.h>
#include <stdlib.h>

//迷路中の１つのブロック
enum MazeKind {PATH, WALL, START, GOAL};  //ブロックの種類
enum MazeFlag {TRUE, FALSE};              //ブロックの存在
enum MazeDirection {UP, DOWN, LEFT, RIGHT, Invalid};

//ブロックの構造体作成
typedef struct {
  enum MazeKind kind;
  enum MazeFlag flag;
}MazeBlock;

//プレイヤー
typedef struct{
  int row;
  int column;
}MazePlayer;
//プレイヤーの位置初期化
int MazePlayerInit(int *playerRow, int *playerColumn, MazeBlock *maze, int mazeRow, int mazeColumn){
  int i,j;

  for(i=0; i<mazeRow; i++){
    for(j=0; j<mazeColumn; j++){
      if(maze[mazeColumn * i + j].kind == START){
        *playerRow = i;
        *playerColumn = j;
        return 0;
      }
    }
  }
  printf("スタートがありません。");
  return -1;
}
//プレイヤーの移動関数
void MazePlayerMove(int *playerRow, int *playerColumn, MazeBlock *maze, int mazeRow, int mazeColumn){
  char buf[100];
  int direction = -1;

  printf("%d:上\n",UP);
  printf("%d:下\n",DOWN);
  printf("%d:左\n",LEFT);
  printf("%d:右\n",RIGHT);
  printf("数字を入力してください。：");

  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &direction);

  while(direction < 0 || direction > (Invalid-1)){
    printf("入力が不正です。再入力してください。:");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &direction);
  }

  switch(direction){
    //上移動
  case UP:
  {
    if(*playerRow - 1 >= 0) //迷路の範囲外でないことを確認
    {
      maze[mazeColumn * ((*playerRow) - 1)+(*playerColumn)].flag = TRUE; //ブロックの種類が判明

      if(maze[mazeColumn * ((*playerRow) - 1)+(*playerColumn)].kind != WALL) //壁かどうか確認
      {
        *playerRow -= 1; //移動
        printf("\n上に移動しました。\n");
      }
      else
      {
        printf("\n壁です。\n");
      }
    }
    else
    {
      printf("\n範囲外です\n");

    }
  }
  break;

  //下移動
  case DOWN:
  {
    if(*playerRow + 1 < mazeRow)
    {
      maze[mazeColumn * ((*playerRow) + 1)+(*playerColumn)].flag = TRUE;

      if(maze[mazeColumn * ((*playerRow) + 1)+(*playerColumn)].kind != WALL)
      {
        *playerRow += 1;
        printf("\n下に移動しました。\n");
      }
      else
      {
        printf("\n壁です。\n");
      }
    }
    else
    {
      printf("\n範囲外です\n");

    }
  }
  break;

  //左移動
  case LEFT:
  {
    if(*playerColumn - 1 >= 0)
    {
      maze[mazeColumn * (*playerRow)+((*playerColumn) - 1)].flag = TRUE;

      if(maze[mazeColumn * (*playerRow)+((*playerColumn) - 1)].kind != WALL)
      {
        *playerColumn -= 1;
        printf("\n左に移動しました。\n");
      }
      else
      {
        printf("\n壁です。\n");
      }
    }
    else
    {
      printf("\n範囲外です\n");

    }
  }
  break;

  //右移動
  case RIGHT:
  {
    if(*playerColumn + 1 < mazeColumn)
    {
      maze[mazeColumn * (*playerRow)+((*playerColumn) + 1)].flag = TRUE;

      if(maze[mazeColumn * (*playerRow)+((*playerColumn) + 1)].kind != WALL)
      {
        *playerColumn += 1;
        printf("\n右に移動しました。\n");
      }
      else
      {
        printf("\n壁です。\n");
      }
    }
    else
    {
      printf("\n範囲外です\n");

    }
  }
  break;
  }

}

int MazeGoalCheck(int playerRow, int playerColumn, MazeBlock *maze, int mazeColumn){
  if(maze[mazeColumn * playerRow + playerColumn].kind == GOAL){
    printf("ゴール！\n");
    return 1;
  }
  return 0;
}

//タイトル画面
enum MazeMenu{GAMESTART, EXIT};

int MazeTitle(){
  char buf[100];
  int menu = -1;

  printf("\n\n＊＊＊迷路ゲーム＊＊＊\n\n");
  printf("メニュー\n");
  printf("%d:ゲーム開始\n",GAMESTART);
  printf("%d:終了\n",EXIT);
  printf("メニューを選択してください:");

  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &menu);

  while(menu < 0 || menu > EXIT){
    printf("入力が不正です。再入力してください。\n");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &menu);
  }

  return menu;
}


//迷路の表示
void MazeDraw(int playerRow, int playerColumn, MazeBlock *maze, int mazeRow, int mazeColumn){
  int i,j;

  for(i=0; i<mazeRow; i++){              //行
    for(j=0; j<mazeColumn; j++){         //列
      if(i == playerRow && j == playerColumn){  //プレイヤー位置
        printf("P");
      }else if(maze[mazeColumn * i + j].flag == FALSE){       //ブロック判定
          printf("？");
        }else{
          switch(maze[mazeColumn * i + j].kind){
            case GOAL:
            printf("G"); break;     //ゴール＝G
            case WALL:
            printf("□"); break;     //壁＝□
            default:
            printf("　"); break;     //道、スタート＝空白
          }
        }
      }
      printf("\n");
    }

}




void MazeGame(void){

char fileName[100];
char buf[100];
FILE* fp;
int i, kind;
int goalcheck = 0;
int mazeRow, mazeColumn;
//プレイヤー
  MazePlayer player;
//迷路
  MazeBlock *maze;

//ファイルの読み込み
printf("ファイル名を入力してください。:");
fgets(fileName, sizeof(fileName), stdin);

//改行を終端文字に書き換え
for(i=0; i<100; i++){
  if(fileName[i] == '\n'){
    fileName[i] = '\0';
  }
}

fp = fopen(fileName, "r");

if(fp == NULL){
  printf("ファイルが見つかりませんでした。");
  return;
}

//迷路サイズを取得
if(fgets(buf, sizeof(buf), fp) != NULL){
  if(sscanf(buf, "%d/%d", &mazeRow,&mazeColumn) != 2){
    printf("サイズが読み込めません。\n");
    fclose(fp);
    return;
  }
}else{
  printf("データ数がありません。\n");
  fclose(fp);
  return;
}

maze = (MazeBlock *)malloc(sizeof(MazeBlock) * mazeRow * mazeColumn);

if(maze == NULL){
  printf("メモリの確保に失敗しました。\n");
  fclose(fp);
  return;
}

//迷路の初期化
for(i=0; i<mazeRow*mazeColumn; i++){
  if(fgets(buf, sizeof(buf), fp) != NULL){
    if(sscanf(buf, "%d", &kind) == 1){
      switch(kind){
        case PATH:
        case WALL:
         maze[i].kind = kind;
         maze[i].flag = FALSE;
         break;

        case GOAL:
         goalcheck = 1;
        case START:
          maze[i].kind = kind;
          maze[i].flag = TRUE;
          break;

        default:
        printf("不正なデータが存在します。\n");
        fclose(fp);
        free(maze);
        return;
        break;
      }
    }else{
      printf("不正なデータが存在します。\n");
      fclose(fp);
      free(maze);
      return;
    }
  }else{
    printf("データが足りません。\n");
    fclose(fp);
    free(maze);
    return;
  }
}

fclose(fp);

if(goalcheck == 0){
  printf("ゴールが存在しません。\n");
  free(maze);
  return;
}

// {
//   {//STAGE0
//     {{START, TRUE}, {PATH, FALSE}, {PATH, FALSE}, {PATH, FALSE}, {PATH, FALSE}},
//     {{WALL, FALSE}, {WALL, FALSE}, {PATH, FALSE}, {WALL, FALSE}, {WALL, FALSE}},
//     {{WALL, FALSE}, {PATH, FALSE}, {PATH, FALSE}, {PATH, FALSE}, {PATH, FALSE}},
//     {{PATH, FALSE}, {PATH, FALSE}, {WALL, FALSE}, {WALL, FALSE}, {WALL, FALSE}},
//     {{WALL, FALSE}, {PATH, FALSE}, {PATH, FALSE}, {PATH, FALSE}, {GOAL, TRUE}},
//   },
//   {//STAGE1
//     {{START, TRUE}, {PATH, FALSE}, {PATH, FALSE}, {PATH, FALSE}, {PATH, FALSE}},
//     {{PATH, FALSE}, {WALL, FALSE}, {PATH, FALSE}, {WALL, FALSE}, {WALL, FALSE}},
//     {{PATH, FALSE}, {WALL, FALSE}, {PATH, FALSE}, {PATH, FALSE}, {PATH, FALSE}},
//     {{PATH, FALSE}, {WALL, FALSE}, {PATH, FALSE}, {WALL, FALSE}, {PATH, FALSE}},
//     {{PATH, FALSE}, {PATH, FALSE}, {PATH, FALSE}, {WALL, FALSE}, {GOAL, TRUE}},
//   }
// };

if(MazePlayerInit(&player.row, &player.column, maze, mazeRow, mazeColumn) == -1){
  return;
}

while(MazeGoalCheck(player.row, player.column, maze, mazeColumn) != 1){
  MazeDraw(player.row, player.column, maze, mazeRow, mazeColumn);
  MazePlayerMove(&player.row, &player.column, maze, mazeRow, mazeColumn);
}

MazeDraw(player.row, player.column, maze, mazeRow, mazeColumn);
free(maze);

}

int main(void){
  int menu;
  int stage;

  while(1){
      //メニュー選択画面
    menu = MazeTitle();
    if(menu == EXIT){
      break;
    }

    MazeGame();
  }




  return 0;
}
