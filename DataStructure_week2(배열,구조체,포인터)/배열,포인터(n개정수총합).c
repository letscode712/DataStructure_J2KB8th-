#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define SIZE 5
//3.7_n���� ���� ����(�迭�� �Լ��� �Ű������� ���)

void get_int(int list[])
{
	printf("%d���� ������ �Է��ϼ���: ", SIZE);
	for (int i = 0; i < SIZE; i++)
		scanf("%d", &list[i]);
}

int cal_sum(int list[])
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
		sum += *(list + i); //sum += list[i]
	return sum;
}
int main(void)
{
	int list[SIZE];
	get_int(list); //�迭 �޾ƿ���
	printf("�� = %d\n", cal_sum(list));
	return 0;
}