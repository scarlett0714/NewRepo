//202110547, Ȳ����, 0452, arithGame.c, 2021/05/21
#include "my.h"
extern int score; //pa2.c���� ������ score���� ���
void arithGame()
{
	int a_menu; //arithGame �޴��Է�
	int max; // �Է¹޴� �ִ�
	int i, j; //�ݺ�����
	int t1, t2; //�ҿ�ð� ����� ���� ���۽ð�, ���ð�
	float T; //���������� �ʿ��� �ð�
	int penalty_T; //���� Ƚ��
	int score1; //arithGame������ score

	do {
		printf("\n1) ���ϱ� �ҷ�?\n");
		printf("2) ���� �ҷ�?\n");
		printf("3) ���ϱ� �ҷ�?\n");
		printf("�޴��� �����ϼ���:");
		scanf("%d", &a_menu);
		if (a_menu == 1 || a_menu == 2 || a_menu == 3)
		{
			do //1���� ���� ���� ���� ����ó��
			{
				printf("\n���ӿ� ����� �ִ� ���� ���� �� (1 �̻�)�� �Է��Ͻÿ�: ");
				scanf("%d", &max);
			} while (max < 1);
		}

		switch (a_menu)
		{
		case 1:
			t1 = time(NULL); //��� ���� ����ð� �����ϱ�
			penalty_T = addition(max);
			t2 = time(NULL);
			break;
		case 2:
			t1 = time(NULL);
			penalty_T = subtraction(max);
			t2 = time(NULL);
			break;
		case 3:
			t1 = time(NULL);
			penalty_T = multiplication(max);
			t2 = time(NULL);
			break;
		}
	} while (a_menu != 1 && a_menu != 2 && a_menu != 3);

	T = ((t2 - t1) + (PENALTY * penalty_T)) / 5.0; //���������� ���� T�� ���
	if (T < 1) //���� ���ؿ� ���� �������
		score1 = 10;
	for (i = 1, j = 9; i < 9; i++, j--)
	{
		if (T >= i && T < (i + 1))
			score1 = j;
	}
	if (T >= 10)
		score1 = 0;
	printf("\n������ ��� %.2f���� �ð��� �ҿ�Ǿ�����, �̹� ������ ������ %d�Դϴ�.\n\n", T, score1); //��� �ɸ� �ð� :T�����
	score += score1; //�� ���������� ���� ���� ���� ���
}
int addition(int max) //���� ���� �Լ�
{
	int add_p1, add_p2; //������ ��µǴ� �� ����
	int i = 0;
	int add_in; //������ �ԷµǴ� ��
	int penalty_T = 0; //���� Ƚ��
	for (i = 0; i < 5; i++)
	{
		srand(time(0));
		add_p1 = (rand() % max) + 1;
		add_p2 = (rand() % max) + 1;
		printf("%d + %d = ", add_p1, add_p2);
		scanf("%d", &add_in);
		if (!(add_in == (add_p1 + add_p2)))
		{
			printf("�����Դϴ�. ������ %d�Դϴ�. ���� %d�� �߰��˴ϴ�.\n", add_p1 + add_p2, PENALTY);
			penalty_T++;
		}
	}
	return penalty_T; //���� Ƚ�� ��ȯ
}
int subtraction(int max) //���� ���� �Լ�
{
	int sub_p1, sub_p2;
	int i = 0;
	int sub_in; //������ �ԷµǴ� ��
	int penalty_T = 0; //���� Ƚ��
	for (i = 0; i < 5; i++)
	{
		srand(time(0));
		sub_p1 = (rand() % max) + 1;
		sub_p2 = (rand() % max) + 1;
		printf("%d - %d = ", sub_p1, sub_p2);
		scanf("%d", &sub_in);
		if (!(sub_in == (sub_p1 - sub_p2)))
		{
			printf("�����Դϴ�. ������ %d�Դϴ�. ���� %d�� �߰��˴ϴ�.\n", sub_p1 - sub_p2, PENALTY);
			penalty_T++;
		}
	}
	return penalty_T;
}
int multiplication(int max) //���� ���� �Լ�
{
	int mul_p1, mul_p2;
	int i = 0;
	int mul_in; //������ �ԷµǴ� ��
	int penalty_T = 0; //���� Ƚ��
	for (i = 0; i < 5; i++)
	{
		srand(time(0));
		mul_p1 = (rand() % max) + 1;
		mul_p2 = (rand() % max) + 1;
		printf("%d * %d = ", mul_p1, mul_p2);
		scanf("%d", &mul_in);
		if (!(mul_in == (mul_p1 * mul_p2)))
		{
			printf("�����Դϴ�. ������ %d�Դϴ�. ���� %d�� �߰��˴ϴ�.\n", mul_p1 * mul_p2, PENALTY);
			penalty_T++;
		}
	}
	return penalty_T;
}