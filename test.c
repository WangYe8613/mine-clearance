#define _CRT_SECURE_NO_WARNINGS -1

#include "game.h"

void game()
{
	int x = 0;
	int y = 0;
	int win = 0;//�ж���Ӯ�����״���
	int select = 0;//������Ϸ���ܵı���
	char mine[ROWS][COLS] = { 0 };//���׵����飨���̣�
	char show[ROWS][COLS] = { 0 };//չʾ�����飨���̣�

	InitBoard(show, ROWS, COLS, '*');//չʾ�����飨���̣���ʼ��Ϊ'*'
	InitBoard(mine, ROWS, COLS, '0');//���׵����֣����̣���ʼ��Ϊ'0'

	SetBoard(mine, ROW, COL, EASY_COUNT);//����
	DisplayBoard(show, ROW, COL);//��ӡ����
	
	while (win<(ROW*COL-EASY_COUNT))//�����׵Ĵ������������׸��������̸��� �� ������ʱ��ֹͣ����
	{
		printf("��ѡ���ܣ�\n1 for ���ף�2 for ��� 3 for ȡ����� 4 for ����һ��\n");
		scanf("%d", &select);
		fflush(stdin);//������뻺���������������ɵ�Ӱ��
		if (select == 1)//1 for ����
		{
			printf("���������꣺\n");
			scanf("%d%d", &x, &y);
			fflush(stdin);//������뻺���������������ɵ�Ӱ��
			if (x >= 1 && x <= ROW&&y >= 1 && y <= COL)//���������Ƿ�Ϸ�
			{
				if (mine[x][y] == '1')//�����ѡλ�����ף��ж��Ƿ�Ϊ��һ������
				{
					if (win != 0)//������ǵ�һ�����ף�������Ϸ����
					{
						DisplayBoard(mine, ROW, COL);//����ʧ�ܺ��ӡһ���׵ķֲ�
						printf("�㱻ը���ˣ�\n");
						return;
					}
					else//����ǵ�һ�����ף��������ת�Ƶ�����λ�ã���֤��һ�β����ŵ���
					{
						mine[x][y] = '0';
						SetBoard(mine, ROW, COL, 1);
						expend(mine, show, x, y, &win);
					}
				}
				else//�����ѡλ��û���ף�������չʽ����
				{
					expend(mine, show, x, y, &win);
				}
				DisplayBoard(show, ROW, COL);//��ӡ���׺������
			}
			else
			{
				printf("�������꣺\n");
			}
		}
		else if (select==2)//2 for ���
		{
			printf("���������꣺\n");
			scanf("%d%d", &x, &y);
			fflush(stdin);//������뻺���������������ɵ�Ӱ��
			sign(show,x,y);
			DisplayBoard(show,ROW,COL);
		}
		else if (select==3)//3 for ȡ�����
		{
			printf("���������꣺\n");
			scanf("%d%d", &x, &y);
			fflush(stdin);//������뻺���������������ɵ�Ӱ��
			unsign(show, x, y);
			DisplayBoard(show, ROW, COL);
		}
		else if (select==4)//4 for ������Ϸ
		{
			return;
		}
	
	}
	printf("���׳ɹ���\n");
}

void menu()
{
	int num = 0;
	srand((unsigned int)time(NULL));//����������ӣ������������
	do
	{
		printf("*********1.play           0.exit**********");
		printf("��ѡ��\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (num);
	
}

void test()
{
	menu();
}

int main()
{
	test();
	return 0;
}