#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define SIZE 5
//3.7_n개의 정수 총합(배열을 함수의 매개변수로 사용)

void get_int(int list[])
{
	printf("%d개의 정수를 입력하세요: ", SIZE);
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
	get_int(list); //배열 받아오기
	printf("합 = %d\n", cal_sum(list));
	return 0;
}