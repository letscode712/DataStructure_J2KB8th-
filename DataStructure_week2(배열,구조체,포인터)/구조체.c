#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

/*3.1_구조체 선언 시 초기화

typedef struct studentTag { //typedef struct(변수타입 student로 재정의) studentTag(구조체명)
	char name[10]; //문자배열로 된 이름 //멤버1
	int age; //나이 정수값 //멤버2
	double gpa; //평균평점 실수값 //멤버3
}student; //구조체 변수

int main(void)
{
	student a = { "kim", 20, 4.3 };
	student b = { "park", 22, 4.2 };
	return 0;
}*/

//학생의 이름, 중간, 기말 성적 출력하기
struct student {
	char name[20];
	int mid, final;
};

int main(void)
{
	struct student aStudent;
	struct student* sp = &aStudent; //sp가 aStudent를 가리키게 한다

	printf("Enter student name: ");
	scanf("%s", sp->name); //(*sp).name

	printf("Enter mid and final score: ");
	scanf("%d %d", &sp->mid, &sp->final); //(*sp).mid, (*sp).final

	printf("\n이름\t중간\t학기말\n");
	printf("%s\t%d\t%d\n", sp->name, sp->mid, sp->final); //(*sp).name,mid,final
}