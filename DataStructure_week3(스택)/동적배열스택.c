#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

//스택 구조체 정의
typedef int element;
typedef struct {
	element* data; //data는 포인터
	int capacity; //현재 크기
	int top;
}StackType;

//스택 생성 함수
void init_stack(StackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element)); //1개 요소 공간 확보
}

//공백 상태 함수
int is_empty(StackType* s)
{
	return s->top == -1;
}

//포화 상태 함수
int is_full(StackType* s)
{
	return s->top == (s->capacity - 1); //현재 크기 -1
}

//삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)remalloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

//삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택공백에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int main(void)
{
	StackType s;
	init_stack(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	free(s.data);
	return 0;
}