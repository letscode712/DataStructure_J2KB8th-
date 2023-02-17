#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

//�����Լ�
void error(char* message)
{
	fprintf(stderr,"%s\n",message);
	exit(1);
}

//�ʱ�ȭ �Լ�
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

//���� ���� �Լ�
int is_empty(QueueType* q)
{
	return q->front = q->rear;
}

//��ȭ ���� �Լ�
int is_full(QueueType* q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front; //(rear +1)%ť ũ�� == front -> ��ȭ ����: front�� rear���� �ϳ� �տ� ����
}

//ť ��� �Լ�
void queue_print(QueueType* q)
{
	printf("QUEUE(front= %d rear = %d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE); //i�� front���� rear����
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

//���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť ��ȭ ����");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //rear �ڸ��� �ϳ� �ڷ� �̵�
	q->data[q->rear] = item; //�̵� �� �� �ڸ��� item ����
}

//���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť �������");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; //front �ڸ� �ϳ� �ڷ� �̵�
	return q->data[q->front]; //��� ��ȯ ��, front �ڸ��� ���ڸ� ��
}

//��ũ �Լ�
element peek(QueueType* q)
{
	if (is_empty(q))
		error("ť ���� ����");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void)
{
	QueueType queue;
	int element;

	init_queue(&queue);

	printf("--������ �߰�--\n");
	while (!is_full(&queue)) {
		printf("���� �Է�: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("ť ��ȭ ����\n\n");

	printf("--������ ����--\n");
	while (!is_empty(&queue)) {
		element = dequeue(&queue);
		printf("���� ����: %d\n", element);
		queue_printf(&queue);
	}
	printf("ť �������\n");
	return 0;
}