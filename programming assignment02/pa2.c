//202110547, 황윤선, 0452, pa2.c, 2021/05/21
#include "my.h"
int score = 0; //누적점수 변수 선언
int main(void)
{
	int n; //메뉴입력받기
	while (1) //사용자가 4를 입력할 때만 프로그램이 종료
	{
		do
		{
			printf("\n1) 산수가 좋아\n");
			printf("2) 비밀을 맞춰봐\n");
			printf("3) 점수 보기\n");
			printf("4) 끝내기\n");
			printf("메뉴를 선택하세요:");
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
				printf("\n총 점수: %d\n", score);
				break;
			case 4:
				return 0;
			}
		} while (n != 1 && n != 2 && n != 3 && n != 4);

	}
}
