#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

//오류함수
void error(char* message)
{
	fprintf(stderr,"%s\n",message);
	exit(1);
}

//초기화 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

//공백 상태 함수
int is_empty(QueueType* q)
{
	return q->front = q->rear;
}

//포화 상태 함수
int is_full(QueueType* q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front; //(rear +1)%큐 크기 == front -> 포화 상태: front가 rear보다 하나 앞에 있음
}

//큐 출력 함수
void queue_print(QueueType* q)
{
	printf("QUEUE(front= %d rear = %d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE); //i는 front부터 rear까지
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

//삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐 포화 상태");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //rear 자리를 하나 뒤로 이동
	q->data[q->rear] = item; //이동 후 그 자리에 item 삽입
}

//삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐 공백상태");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; //front 자리 하나 뒤로 이동
	return q->data[q->front]; //요소 반환 후, front 자리가 빈자리 됨
}

//피크 함수
element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐 공백 상태");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void)
{
	QueueType queue;
	int element;

	init_queue(&queue);

	printf("--데이터 추가--\n");
	while (!is_full(&queue)) {
		printf("정수 입력: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("큐 포화 상태\n\n");

	printf("--데이터 삭제--\n");
	while (!is_empty(&queue)) {
		element = dequeue(&queue);
		printf("꺼낸 정수: %d\n", element);
		queue_printf(&queue);
	}
	printf("큐 공백상태\n");
	return 0;
}