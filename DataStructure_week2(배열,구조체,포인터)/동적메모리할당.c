#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


/*3.8_malloc�����޸��Ҵ�
//SIZE ��ŭ �Ҵ�ް� ����ϱ�

#define SIZE 10

int main(void)
{
	int* p;
	p = (int*)malloc(SIZE * sizeof(int));

	//��������
	if (p == NULL) {
		fprintf(stderr,"�޸𸮺���,�Ҵ�x\n");
		exit(1);
	}

	for (int i = 0; i < SIZE; i++)
		p[i] = i;

	for (int i = 0; i < SIZE; i++)
		print("%d ", p[i]);

	free(p);
	return 0;
}*/

//struct person(����ü �ڷ���) s(����ü ����); 
//struct person(����ü �ڷ���) *ps(����ü ������ ����);
//(*ps).i == ps->i

//3.9_malloc�����޸��Ҵ�2
typedef struct studentTag {
	char name[10]; //���ڹ迭�� �� �̸�
	int age; //���� ������
	double gpa; //������� �Ǽ���
}student;

int main(void)
{
	student* s;
	s = (student*)malloc(sizeof(student));

	if (s == NULL) {
		fprintf(stderr, "�޸� �������� �Ҵ�x\n");
		exit(1);
	}

	strcpy(s->name, "Kim"); //(*s).name
	s->age = 22; //(*s).age

	free(s);
	return 0;
}