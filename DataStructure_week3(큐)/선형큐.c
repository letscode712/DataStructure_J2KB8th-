#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE]; //ť�� ���� data�� ����ü��(intŸ�� -> element��)
}QueueType;

//���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//ť �ʱ�ȭ �Լ� : front, rear ��� -1�� ��
void init_queue(QueueType* q)
{
	q->rear = -1;
	q->front = -1;
}

//ť ��� �Լ�
void queue_print(QueueType* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear) //i�� front�� rear�� ��� ��
			printf(" | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

//���� ���� �Լ�
int is_empty(QueueType* q)
{
	if (q->front == q->rear) //front, rear�� ���� �ڸ��� ��
		return 1;
	else
		return 0;
}

//��ȭ ���� �Լ�
int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1) //rear�� ������ �ڸ��� ��
		return 1;
	else
		return 0;
}

//���� �Լ�
void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		error("ť ��ȭ����");
		return;
	}
	q->data[++(q->rear)] = item; //rear���� �����ϰ� item �� �ڸ��� �ֱ�
}
//���� �Լ�
int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("ť ���� ����");
		return -1;
	}
	int item = q->data[++(q->front)]; //front�� �ϳ� �ڷ� �ű��, ���� front �ڸ��� ��Ҵ� ��ȯ
	return item;
}

//��ũ�Լ� : ���� ��� ��Ÿ���� �Լ�
element peek(QueueType* q)
{
	if (is_empty(q)) {
		error("ť �������");
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