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
	printf("���ϴ� ���ڸ� �Է��ϼ��� : ");
	scanf("%d", &input_no);
	result = calc(input_no);
	printf("0���� %d ���� ������ ���� ����� %d �Դϴ�.\n\a", input_no, result);
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