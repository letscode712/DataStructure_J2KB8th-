#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

/*3.1_����ü ���� �� �ʱ�ȭ

typedef struct studentTag { //typedef struct(����Ÿ�� student�� ������) studentTag(����ü��)
	char name[10]; //���ڹ迭�� �� �̸� //���1
	int age; //���� ������ //���2
	double gpa; //������� �Ǽ��� //���3
}student; //����ü ����

int main(void)
{
	student a = { "kim", 20, 4.3 };
	student b = { "park", 22, 4.2 };
	return 0;
}*/

//�л��� �̸�, �߰�, �⸻ ���� ����ϱ�
struct student {
	char name[20];
	int mid, final;
};

int main(void)
{
	struct student aStudent;
	struct student* sp = &aStudent; //sp�� aStudent�� ����Ű�� �Ѵ�

	printf("Enter student name: ");
	scanf("%s", sp->name); //(*sp).name

	printf("Enter mid and final score: ");
	scanf("%d %d", &sp->mid, &sp->final); //(*sp).mid, (*sp).final

	printf("\n�̸�\t�߰�\t�б⸻\n");
	printf("%s\t%d\t%d\n", sp->name, sp->mid, sp->final); //(*sp).name,mid,final
}