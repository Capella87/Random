/*

��������������������
�� Random ��
��������������������
Developed by Capella87

Copyright (c) 2018 Capella87

Random version : 1.1.0
Release date : Mar 22, 2018
First commit date : Feb 24, 2018
Initial version release date : Feb 22, 2018




����������������������������������������������������������������������������������������������������������������������������������������������
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
	printf("���ϴ� ���ڸ� �Է��ϼ��� >> ");
	scanf("%d", &input_no);
	result = calc(input_no);
	printf("0���� %d ���� ������ ���� ����� %d �Դϴ�.\n\a", input_no, result);

	puts("�ٽ� ������ �����Ű���?\n");
	printf("1 : �ٽ� ������  |  2 : ������\n");
	printf(">> ");
	scanf("%d", &ask);

	switch (ask)
	{
		case 1 :
			printf("�ٽ� �����ϴ�.\n");
			system("cls");
			goto start;
			break;

		case 2 :
			printf("���α׷��� �����ϴ�.\n");
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
	puts("��������������������");
	puts("�� Random ��");
	puts("��������������������\n\n");
	printf("Developed by Capella87.\n");
	printf("1.1.0 | Mar 22, 2018\n");
	printf("Copyright (c) 2018 Capella87\n\n");
	printf("����������������������������������������������������������������������������\n\n");
}