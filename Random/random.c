#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS

double calc(int);
void wait(int);

int main(void)
{
	int input_no;
	int result;
	printf("원하는 숫자를 입력하세요 : ");
	scanf("%d", &input_no);
	result = calc(input_no);
	printf("0부터 %d 까지 수에서 뽑은 결과는 %d 입니다.\n\a", input_no, result);
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