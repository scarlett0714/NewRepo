//202110547, 황윤선, 0452, findSecret.c, 2021/05/21
#include "my.h"
extern int score; //pa2.c에서 선언한 score변수 사용
void findSecret()
{
	int max; //입력받는 최댓값
	int c_secret; //컴퓨터 비밀값
	int u_secret; //유저가 추측하는 비밀값
	int try = 0; //시도 횟수
	int t1, t2; //소요시간 계산을 위한 시작시간, 끝시간
	int T; //점수산정에 필요한 시간
	int count; //최대 정수 값의 자리 수
	int i, j; //반복변수
	int score2; //findSecret에서의 score
	do
	{
		printf("\n게임에 사용할 최대 양의 정수 값 (1 이상)을 입력하시오: ");
		scanf("%d", &max);
	} while (max < 1);

	srand(time(0));
	c_secret = (rand() % max) + 1;
	for (count = 0; max != 0; count++) //입력받은 max의 자릿수 구하기
	{
		max = max / 10;
	}
	t1 = time(NULL);
	while (1)
	{
		printf("비밀 값을 추측해 보세요: ");
		scanf("%d", &u_secret);
		if (c_secret != u_secret) //변수에 저장된 값을 비교하여 수행결과 다르게 하기
		{
			if (c_secret > u_secret)
			{
				printf("입력 값이 너무 작습니다.\n");
				try++;
			}

			if (c_secret < u_secret)
			{
				printf("입력 값이 너무 큽니다.\n");
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
	printf("정답입니다.\n축하합니다. 총 %d초 동안, %d번의 시도로 성공하였습니다.\n", t2 - t1, try); //총 시간: t2-t1
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
	printf("이번 게임의 점수는 %d입니다.\n", score2);
	score += score2; //총 누적점수에 현재 얻은 점수 기록
}