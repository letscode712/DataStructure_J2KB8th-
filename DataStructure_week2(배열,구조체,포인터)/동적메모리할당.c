#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


/*3.8_malloc동적메모리할당
//SIZE 만큼 할당받고 출력하기

#define SIZE 10

int main(void)
{
	int* p;
	p = (int*)malloc(SIZE * sizeof(int));

	//널포인터
	if (p == NULL) {
		fprintf(stderr,"메모리부족,할당x\n");
		exit(1);
	}

	for (int i = 0; i < SIZE; i++)
		p[i] = i;

	for (int i = 0; i < SIZE; i++)
		print("%d ", p[i]);

	free(p);
	return 0;
}*/

//struct person(구조체 자료형) s(구조체 변수); 
//struct person(구조체 자료형) *ps(구조체 포인터 변수);
//(*ps).i == ps->i

//3.9_malloc동적메모리할당2
typedef struct studentTag {
	char name[10]; //문자배열로 된 이름
	int age; //나이 정수값
	double gpa; //평균평점 실수값
}student;

int main(void)
{
	student* s;
	s = (student*)malloc(sizeof(student));

	if (s == NULL) {
		fprintf(stderr, "메모리 부족으로 할당x\n");
		exit(1);
	}

	strcpy(s->name, "Kim"); //(*s).name
	s->age = 22; //(*s).age

	free(s);
	return 0;
}