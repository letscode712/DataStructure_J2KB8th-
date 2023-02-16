#include <stdio.h>
#include <stdlib.h>

//프4.3 동적 배열 스택 구현
#define MAX_STACK_SIZE 100

//스택 구조체 정의
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

//스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

//공백 상태 함수
int is_empty(StackType* s)
{
	return s->top == -1;
}

//포화 상태 함수
int is_full(StackType* s)
{
	return s->top == (MAX_STACK_SIZE - 1);
}

//삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택포화에러\n");
		return;
	}
	else s->data[++(s->top)] = item; //top먼저 하나 올리고, 배열에 item 삽입
}

//삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택공백에러\n");
		return;
	}
	else return s->data[(s->top)--];
}

//피크함수:현재 상태 나타내는 함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택공백에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

int main(void)
{
	StackType* s;
	s = (StackType*)malloc(sizeof(StackType)); //스택을 동적으로 할당하기
	init_stack(s);
	
	push(s, 1);
	push(s, 2);
	push(s, 3);
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	free(s);
}