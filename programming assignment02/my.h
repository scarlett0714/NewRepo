//202110547, Ȳ����, 0452, my.h, 2021/05/21
#include <stdio.h> //������Լ� ���� ���� �������
#include <stdlib.h> //srand, rand�Լ� ���� ���� �������
#include <time.h> //time�Լ� ���� ���� �������

#define PENALTY 5 //arithGame.c���� ���Ǵ� ���� 5�ʸ� ��ȣ����� �����Ѵ�.

void arithGame(); //�ٸ� �ҽ����Ͽ��� ���Ǵ� �Լ� ���� ����
void findSecret();
int addition(int max);
int subtraction(int max);
int multiplication(int max);

