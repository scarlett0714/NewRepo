//202110547, Ȳ����, 0452, pa2.c, 2021/05/21
#include "my.h"
int score = 0; //�������� ���� ����
int main(void)
{
	int n; //�޴��Է¹ޱ�
	while (1) //����ڰ� 4�� �Է��� ���� ���α׷��� ����
	{
		do
		{
			printf("\n1) ����� ����\n");
			printf("2) ����� �����\n");
			printf("3) ���� ����\n");
			printf("4) ������\n");
			printf("�޴��� �����ϼ���:");
			scanf("%d", &n);
			switch (n)
			{
			case 1:
				arithGame();
				break;
			case 2:
				findSecret();
				break;
			case 3:
				printf("\n�� ����: %d\n", score);
				break;
			case 4:
				return 0;
			}
		} while (n != 1 && n != 2 && n != 3 && n != 4);

	}
}
