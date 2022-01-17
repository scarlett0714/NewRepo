//202110547, 황윤선, 0452, my.h, 2021/05/21
#include <stdio.h> //입출력함수 등을 위한 헤더파일
#include <stdlib.h> //srand, rand함수 등을 위한 헤더파일
#include <time.h> //time함수 등을 위한 헤더파일

#define PENALTY 5 //arithGame.c에서 사용되는 벌점 5초를 기호상수로 정의한다.

void arithGame(); //다른 소스파일에서 사용되는 함수 원형 선언
void findSecret();
int addition(int max);
int subtraction(int max);
int multiplication(int max);

