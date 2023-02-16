#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE]; //큐에 들어가는 data를 구조체로(int타입 -> element형)
}QueueType;

//오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//큐 초기화 함수 : front, rear 모두 -1일 때
void init_queue(QueueType* q)
{
	q->rear = -1;
	q->front = -1;
}

//큐 출력 함수
void queue_print(QueueType* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear) //i가 front와 rear를 벗어날 때
			printf(" | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

//공백 상태 함수
int is_empty(QueueType* q)
{
	if (q->front == q->rear) //front, rear가 같은 자리일 때
		return 1;
	else
		return 0;
}

//포화 상태 함수
int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1) //rear가 마지막 자리일 때
		return 1;
	else
		return 0;
}

//삽입 함수
void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		error("큐 포화상태");
		return;
	}
	q->data[++(q->rear)] = item; //rear먼저 증가하고 item 그 자리에 넣기
}
//삭제 함수
int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("큐 공백 상태");
		return -1;
	}
	int item = q->data[++(q->front)]; //front를 하나 뒤로 옮기고, 원래 front 자리의 요소는 반환
	return item;
}

//피크함수 : 현재 요소 나타내는 함수
element peek(QueueType* q)
{
	if (is_empty(q)) {
		error("큐 공백상태");
		return -1;
	}
	else
		return q->data[++(q->front)];
}

int main(void)
{
	int item = 0;
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	return 0;
}