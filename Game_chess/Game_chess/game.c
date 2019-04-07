#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ROW 3
#define MAX_COL 3
 int Menu(){
	printf("=========================\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("=========================\n");
	printf("请输入您的选择:");
	int choose = 0;
	scanf("%d", &choose);
	return choose;
}
 char chess_board[MAX_ROW][MAX_COL];
 void InitChess(){
	 for (int row = 0; row < MAX_ROW; row++){
		 for (int col = 0; col < MAX_COL; col++){
			 chess_board[row][col] = ' ';
		 }
	 }
 }
 void Print(){
	 for (int row = 0; row < MAX_ROW; row++){
		 printf("| %c | %c | %c |\n", chess_board[row][0], chess_board[row][1],chess_board[row][2]);
		 if (row != MAX_ROW-1){
			 printf("|---|---|---|\n");
		 }
	 }
 }
 void MovePlayer(){
	 printf("玩家落子:\n");
	 while (1){
		 printf("请输入一组坐标(row, col)\n");
		 int row = 0;
		 int col = 0;
		 scanf("%d %d", &row, &col);
		 if (row >= MAX_ROW || row < 0 || col >= MAX_ROW || col < 0){
			 printf("您的输入非法!\n");
			 continue;
		 }
		 if (chess_board[row][col] != ' '){
			 printf("您输入的坐标已有棋子,请重新输入!\n");
			 continue;
		 }
		 chess_board[row][col] = 'x';
		 break;
	 }
 }
 void MoveCp(){
	 while (1){
		 int row = rand() % MAX_ROW;
		 int col = rand() % MAX_COL;
		 if (chess_board[row][col] != ' '){
			 continue;//已有棋子,重新随机
		 }
		 chess_board[row][col] = 'o';
		 break;
	 }
 }
 //函数返回1为棋盘满了,返回0为没满
 int IsFull(){
	 for (int row = 0; row <= MAX_ROW; row++){
		 for (int col = 0; col <= MAX_COL; col++){
			 if (chess_board[row][col] == ' '){
				 return 0;
			 }
		 }
	 }
	 return 1;
 }
 //返回'x'为人胜利
 //返回'o'为电脑胜利
 //返回'q'为和局
 //返回' '继续游戏
 char CheckGameOver(){
	 for (int row = 0; row < MAX_ROW; row++){
		 if (chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2]){
			 return chess_board[row][0];
		 }
	 }
     for (int col = 0; col < MAX_COL; col++){
		 if (chess_board[0][col] == chess_board[1][col] && chess_board[0][col] == chess_board[2][col]){
				 return chess_board[0][col];
			 }
		 }
			 if (chess_board[0][0] == chess_board[1][1] && chess_board[0][0] == chess_board[2][2]){
				 return chess_board[0][0];
			 }
			 if (chess_board[0][2] == chess_board[1][1] && chess_board[0][2] == chess_board[2][0]){
				 return chess_board[0][2];
			 }
			 if (IsFull()){
				 return 'q';
			 }
			 return ' ';
		 }
 void Game(){
	 char winner=' ';
	 InitChess();                 //初始化棋盘
	 while (1){
		 system("cls");
		 Print();                 //打印棋盘
		 MovePlayer();            //玩家落子
		 winner = CheckGameOver(); //判断胜负
		 if (winner !=' '){
			 break;               //未分出胜负
		 }
		 MoveCp();                //电脑落子
		 winner = CheckGameOver(); //判断胜负
		 if (winner != ' '){
			 break;               // 未分出胜负
		 }
	 }
		 if (winner == 'x'){
			 system("cls");
			 printf("您胜利了!\n");
			 Print();
		 }
		 else if (winner == 'o'){
			 printf("弱爆了,电脑都下不过!\n");
		 }
		 else if (winner == 'q'){
			 printf("菜鸡,和电脑五五开!\n");
		 }
		 else{
			 printf("出错了~~~\n");
		 }
 }
 int main(){
	 while (1){
		 int choose = Menu();
		 if (choose == 1){
			 Game();
		 }
		 else if(choose==0){
			 printf("goodbye!\n");
			 break;
		 }
		 else{
			 printf("您的输入有误!\n");
		 }
	 }
	 system("pause");
	 return 0;
}