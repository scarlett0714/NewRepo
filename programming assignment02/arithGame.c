//202110547, 황윤선, 0452, arithGame.c, 2021/05/21
#include "my.h"
extern int score; //pa2.c에서 선언한 score변수 사용
void arithGame()
{
	int a_menu; //arithGame 메뉴입력
	int max; // 입력받는 최댓값
	int i, j; //반복변수
	int t1, t2; //소요시간 계산을 위한 시작시간, 끝시간
	float T; //점수산정에 필요한 시간
	int penalty_T; //벌점 횟수
	int score1; //arithGame에서의 score

	do {
		printf("\n1) 더하기 할래?\n");
		printf("2) 빼기 할래?\n");
		printf("3) 곱하기 할래?\n");
		printf("메뉴를 선택하세요:");
		scanf("%d", &a_menu);
		if (a_menu == 1 || a_menu == 2 || a_menu == 3)
		{
			do //1보다 작은 값에 대한 예외처리
			{
				printf("\n게임에 사용할 최대 양의 정수 값 (1 이상)을 입력하시오: ");
				scanf("%d", &max);
			} while (max < 1);
		}

		switch (a_menu)
		{
		case 1:
			t1 = time(NULL); //산수 게임 수행시간 측정하기
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

	T = ((t2 - t1) + (PENALTY * penalty_T)) / 5.0; //점수산정을 위한 T값 계산
	if (T < 1) //배점 기준에 따라 점수기록
		score1 = 10;
	for (i = 1, j = 9; i < 9; i++, j--)
	{
		if (T >= i && T < (i + 1))
			score1 = j;
	}
	if (T >= 10)
		score1 = 0;
	printf("\n문제당 평균 %.2f초의 시간이 소요되었으며, 이번 게임의 점수는 %d입니다.\n\n", T, score1); //평균 걸린 시간 :T값출력
	score += score1; //총 누적점수에 현재 얻은 점수 기록
}
int addition(int max) //덧셈 연산 함수
{
	int add_p1, add_p2; //문제에 출력되는 두 정수
	int i = 0;
	int add_in; //답으로 입력되는 수
	int penalty_T = 0; //벌점 횟수
	for (i = 0; i < 5; i++)
	{
		srand(time(0));
		add_p1 = (rand() % max) + 1;
		add_p2 = (rand() % max) + 1;
		printf("%d + %d = ", add_p1, add_p2);
		scanf("%d", &add_in);
		if (!(add_in == (add_p1 + add_p2)))
		{
			printf("오답입니다. 정답은 %d입니다. 벌점 %d초 추가됩니다.\n", add_p1 + add_p2, PENALTY);
			penalty_T++;
		}
	}
	return penalty_T; //벌점 횟수 반환
}
int subtraction(int max) //뺄셈 연산 함수
{
	int sub_p1, sub_p2;
	int i = 0;
	int sub_in; //답으로 입력되는 수
	int penalty_T = 0; //벌점 횟수
	for (i = 0; i < 5; i++)
	{
		srand(time(0));
		sub_p1 = (rand() % max) + 1;
		sub_p2 = (rand() % max) + 1;
		printf("%d - %d = ", sub_p1, sub_p2);
		scanf("%d", &sub_in);
		if (!(sub_in == (sub_p1 - sub_p2)))
		{
			printf("오답입니다. 정답은 %d입니다. 벌점 %d초 추가됩니다.\n", sub_p1 - sub_p2, PENALTY);
			penalty_T++;
		}
	}
	return penalty_T;
}
int multiplication(int max) //곱셈 연산 함수
{
	int mul_p1, mul_p2;
	int i = 0;
	int mul_in; //답으로 입력되는 수
	int penalty_T = 0; //벌점 횟수
	for (i = 0; i < 5; i++)
	{
		srand(time(0));
		mul_p1 = (rand() % max) + 1;
		mul_p2 = (rand() % max) + 1;
		printf("%d * %d = ", mul_p1, mul_p2);
		scanf("%d", &mul_in);
		if (!(mul_in == (mul_p1 * mul_p2)))
		{
			printf("오답입니다. 정답은 %d입니다. 벌점 %d초 추가됩니다.\n", mul_p1 * mul_p2, PENALTY);
			penalty_T++;
		}
	}
	return penalty_T;
}