#define _CRT_SECURE_NO_WARNINGS -1

#include "game.h"

void InitBoard(char board[ROWS][COLS], int row, int col, char set)//��ʼ������
{
	memset(board,set,row*col*sizeof(board[0][0]));//����memset��ʼ����memset�÷����п���ѧϰ
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)//��ӡ����
{
	system("CLS");//ÿ�δ�ӡ����֮ǰ����һ��
	int i = 0;
	int j = 0;
	printf("   ");//Ϊ�˴�ӡ������ʱ����
	for (i = 1; i <= row; i++)
		printf("%d ", i);//��ӡ������1 2 3 4 5 6 7 8 9 10
	printf("\n");
	for (i = 1; i <=row; i++)
	{
		printf("%2d ", i);//��ӡ������1 2 3 4 5 6 7 8 9 10
		for (j = 1; j <=row; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetBoard(char board[ROWS][COLS], int row, int col,int count)//����
{
	int x = 0;
	int y = 0; 
	while (count)
	{
		x = rand() % row + 1;//��֤��������1��10֮��
		y = rand() % col + 1;//��֤��������1��10֮��
		if (board[x][y] == '0')//�жϸ�λ���Ƿ񲼹���
		{
			board[x][y] = '1';//��1����������
			count--;//��һ���ף�������һ
		}
	}
	
}

int GetCount(char board[ROWS][COLS], int x, int y)//ͳ������
{
	return board[x - 1][y] +
		board[x - 1][y - 1] +
		board[x][y - 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] +
		board[x][y + 1] +
		board[x - 1][y + 1] - 8 * '0';//����λ����Χ�˸�λ�õ�������Ƿ����ף�����
}

void expend(char board1[ROWS][COLS], char board2[ROWS][COLS], int x, int y, int *num)//��չʽ���ף��ݹ飩
{
	int i = 0;
	int j = 0;
	if (board2[x][y]=='*')//�����λ���ַ�Ϊ'*'�����λ����δ�Ź��ģ���������
	{
		(*num)++;//���״�����һ
		int count = GetCount(board1,x,y);//ͳ�Ƹ�λ����Χ������
		if (count != 0)//�����λ����Χ��������Ϊ0
		{
			board2[x][y] = count + '0';//��ʾ����,���λ�õ��ַ���Ϊ'*'���ɱ����´������ظ��ŵ���λ��
		}
		else//�����λ�õ�����Ϊ0����������Χ�˸�λ����չ����
		{
			board2[x][y] = '0';//��λ�õ��ַ���ʾΪ��0��
			for (i = -1; i <= 1; i++)
			{
				for (j = -1; j <= 1; j++)
				{
					if (x + i >= 1 && x + i <=ROW && y + j >= 1 && y + j <=COL)//�ķ���3��Сʱ����ʱ��Ĳ����۵�С���󣡣�����������
					{
						if (i != 0 || j != 0)//�����ظ��ŵ��Լ�
							expend(board1, board2, x + i, y + j, num);
					}
				}
			}
		}
	}
}

void sign(char board[ROWS][COLS], int x, int y)//�á�@�������
{
	if (board[x][y] == '*')
	{
		board[x][y] = '@';
	}
}

void unsign(char board[ROWS][COLS], int x, int y)//ȡ�����
{
	if (board[x][y] == '@')
	{
		board[x][y] = '*';
	}
}