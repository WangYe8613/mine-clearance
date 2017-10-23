#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



#define ROW 10//��������
#define COL 10//��������
#define ROWS ROW+2//���飨ʵ�ʣ�����
#define COLS COL+2//���飨ʵ�ʣ�����
#define EASY_COUNT 10//�����Ѷȵ�����

void InitBoard(char board[ROWS][COLS], int row, int col, char set);//��ʼ������
void DisplayBoard(char board[ROWS][COLS], int row, int col);//��ӡ����
void SetBoard(char board[ROWS][COLS], int row, int col, int count);//����
int GetCount(char board[ROWS][COLS], int x, int y);//ͳ������
void expend(char board1[ROWS][COLS], char board[ROWS][COLS], int x, int y,int *num);//��չʽ����
void sign(char board[ROWS][COLS], int x, int y);//��Ǻ�ͷ���ף�
void unsign(char board[ROWS][COLS], int x, int y);//ȡ�����

#endif//__GAME_H__