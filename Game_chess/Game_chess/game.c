#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ROW 3
#define MAX_COL 3
 int Menu(){
	printf("=========================\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("=========================\n");
	printf("����������ѡ��:");
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
	 printf("�������:\n");
	 while (1){
		 printf("������һ������(row, col)\n");
		 int row = 0;
		 int col = 0;
		 scanf("%d %d", &row, &col);
		 if (row >= MAX_ROW || row < 0 || col >= MAX_ROW || col < 0){
			 printf("��������Ƿ�!\n");
			 continue;
		 }
		 if (chess_board[row][col] != ' '){
			 printf("�������������������,����������!\n");
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
			 continue;//��������,�������
		 }
		 chess_board[row][col] = 'o';
		 break;
	 }
 }
 //��������1Ϊ��������,����0Ϊû��
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
 //����'x'Ϊ��ʤ��
 //����'o'Ϊ����ʤ��
 //����'q'Ϊ�;�
 //����' '������Ϸ
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
	 InitChess();                 //��ʼ������
	 while (1){
		 system("cls");
		 Print();                 //��ӡ����
		 MovePlayer();            //�������
		 winner = CheckGameOver(); //�ж�ʤ��
		 if (winner !=' '){
			 break;               //δ�ֳ�ʤ��
		 }
		 MoveCp();                //��������
		 winner = CheckGameOver(); //�ж�ʤ��
		 if (winner != ' '){
			 break;               // δ�ֳ�ʤ��
		 }
	 }
		 if (winner == 'x'){
			 system("cls");
			 printf("��ʤ����!\n");
			 Print();
		 }
		 else if (winner == 'o'){
			 printf("������,���Զ��²���!\n");
		 }
		 else if (winner == 'q'){
			 printf("�˼�,�͵������忪!\n");
		 }
		 else{
			 printf("������~~~\n");
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
			 printf("������������!\n");
		 }
	 }
	 system("pause");
	 return 0;
}