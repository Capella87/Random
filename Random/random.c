/*

┏━━━━━━━━┓
┃ Random ┃
┗━━━━━━━━┛
Developed by Capella87

Copyright (c) 2018 Capella87

Random version : 1.1.0
Release date : Mar 22, 2018
First commit date : Feb 24, 2018
Initial version release date : Feb 22, 2018




━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS

double calc(int);
void wait(int);
void design(void);

int main(void)
{
	int input_no;
	int result;
	int ask;
start:
	design();
	printf("원하는 숫자를 입력하세요 >> ");
	scanf("%d", &input_no);
	result = calc(input_no);
	printf("0부터 %d 까지 수에서 뽑은 결과는 %d 입니다.\n\a", input_no, result);

	puts("다시 돌리고 싶으신가요?\n");
	printf("1 : 다시 돌리기  |  2 : 끝내기\n");
	printf(">> ");
	scanf("%d", &ask);

	switch (ask)
	{
		case 1 :
			printf("다시 돌립니다.\n");
			system("cls");
			goto start;
			break;

		case 2 :
			printf("프로그램을 끝냅니다.\n");
			break;
	}
	return 0;
}

double calc(int input)
{
	for (int n = 5; n > 0; n--)
	{
		printf("%d ", n);
		wait(1);
	}
	printf("\n");
	go:
	srand(time(NULL));
	int output = rand() % input + 1;
	if (output == 4)
	{
		goto go;
	}
	return output;
}

void wait(int sec)
{
	clock_t endwait;
	endwait = clock() + sec * CLOCKS_PER_SEC;
	while (clock() < endwait);
}

void design(void)
{
	puts("┏━━━━━━━━┓");
	puts("┃ Random ┃");
	puts("┗━━━━━━━━┛\n\n");
	printf("Developed by Capella87.\n");
	printf("1.1.0 | Mar 22, 2018\n");
	printf("Copyright (c) 2018 Capella87\n\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
}