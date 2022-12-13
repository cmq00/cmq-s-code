#include <stdio.h>  

#include <stdlib.h>  

#include <conio.h>  

#include <string.h>  

#include <time.h>  

char GameMap[20][60];   

int  key;  //按键保存  

int  sum = 1, over = 0;  //蛇的长度, 游戏结束(自吃或碰墙)  

int  dx[4] = {0, 0, -1, 1};  //左、右、上、下的方向  

int  dy[4] = {-1, 1, 0, 0};  

struct Snake   //蛇的每个节点的数据类型  

{  

 int x, y;  //左边位置  

 int now;   //保存当前节点的方向, 0,1,2,3分别为左右上下  

}Snake[H*L];  

const char Shead = '@';  //蛇头  

const char Sbody = '#';  //蛇身  

const char Sfood = '*';  //食物  

const char Snode = '.';  //'.'在地图上标示为空  

void Initial();  //地图的初始化  

void Create_Food(); //在地图上随机产生食物  

void Show();   //刷新显示地图  

void Button();  //取出按键,并判断方向  

void Move();   //蛇的移动  

void Check_Border();  //检查蛇头是否越界  

void Check_Head(int x, int y);   //检查蛇头移动后的位置情况  

int main()   

{  

 Initial();  

 Show();  

 return 0;  

}  

void Initial()  //地图的初始化  

{  

 int i, j;  

 int hx, hy;  

 system("title 贪吃蛇");  //控制台的标题  

 memset(GameMap, '.', sizeof(GameMap));  //初始化地图全部为空'.'  

 system("cls");  

 srand(time(0));   //随机种子  

 hx = rand()%H;    //产生蛇头  

 hy = rand()%L;  

 GameMap[hx][hy] = Shead;  

 Snake[0].x = hx;  Snake[0].y = hy;  

 Snake[0].now = -1;  

 Create_Food();   //随机产生食物  

 for(i = 0; i < H; i++)   //地图显示  

 {   

  for(j = 0; j < L; j++)  

   printf("%c", GameMap[i][j]);  

  printf("\n");  

 }  

     

 printf("\nC语言小游戏贪吃蛇\n");  

 printf("按任意方向键开始游戏\n");  

    

 getch();   //先接受一个按键,使蛇开始往该方向走  

 Button();  //取出按键,并判断方向  

}  

void Create_Food()  //在地图上随机产生食物  

{  

 int fx, fy;  

 while(1)  

 {  

  fx = rand()%H;  

     fy = rand()%L;  

     

  if(GameMap[fx][fy] == '.')  //不能出现在蛇所占有的位置  

  {   

   GameMap[fx][fy] = Sfood;  

      break;  

  }  

 }  

}  

void Show()  //刷新显示地图  

{  

 int i, j;  

 while(1)  

 {    

  _sleep(500); //延迟半秒(1000为1s),即每半秒刷新一次地图  

  Button();   //先判断按键在移动  

  Move();  

  if(over)  //自吃或碰墙即游戏结束  

  {   

   printf("\n**游戏结束**\n");  

   printf("     >_<\n");  

   getchar();  

      break;  

  }  

  system("cls");   //清空地图再显示刷新