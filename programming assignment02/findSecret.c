//202110547, Ȳ����, 0452, findSecret.c, 2021/05/21
#include "my.h"
extern int score; //pa2.c���� ������ score���� ���
void findSecret()
{
	int max; //�Է¹޴� �ִ�
	int c_secret; //��ǻ�� ��а�
	int u_secret; //������ �����ϴ� ��а�
	int try = 0; //�õ� Ƚ��
	int t1, t2; //�ҿ�ð� ����� ���� ���۽ð�, ���ð�
	int T; //���������� �ʿ��� �ð�
	int count; //�ִ� ���� ���� �ڸ� ��
	int i, j; //�ݺ�����
	int score2; //findSecret������ score
	do
	{
		printf("\n���ӿ� ����� �ִ� ���� ���� �� (1 �̻�)�� �Է��Ͻÿ�: ");
		scanf("%d", &max);
	} while (max < 1);

	srand(time(0));
	c_secret = (rand() % max) + 1;
	for (count = 0; max != 0; count++) //�Է¹��� max�� �ڸ��� ���ϱ�
	{
		max = max / 10;
	}
	t1 = time(NULL);
	while (1)
	{
		printf("��� ���� ������ ������: ");
		scanf("%d", &u_secret);
		if (c_secret != u_secret) //������ ����� ���� ���Ͽ� ������ �ٸ��� �ϱ�
		{
			if (c_secret > u_secret)
			{
				printf("�Է� ���� �ʹ� �۽��ϴ�.\n");
				try++;
			}

			if (c_secret < u_secret)
			{
				printf("�Է� ���� �ʹ� Ů�ϴ�.\n");
				try++;
			}
		}
		else
		{
			try++;
			break;
		}
	}
	t2 = time(NULL);
	printf("�����Դϴ�.\n�����մϴ�. �� %d�� ����, %d���� �õ��� �����Ͽ����ϴ�.\n", t2 - t1, try); //�� �ð�: t2-t1
	T = (t2 - t1) / (2 * count);
	if (T < 1)
		score2 = 10;
	for (i = 1, j = 9; i < 9; i++, j--)
	{
		if (T >= i && T < (i + 1))
			score2 = j;
	}
	if (T >= 10)
		score2 = 0;
	printf("�̹� ������ ������ %d�Դϴ�.\n", score2);
	score += score2; //�� ���������� ���� ���� ���� ���
}