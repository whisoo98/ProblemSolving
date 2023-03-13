#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAX_QUEUE_SIZE 2'000'005

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

void init_queue(QueueType* q) {
	q->front = 0;
	q->rear = 0;
}

int is_full(QueueType* q) {
	if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front)
		return 1;
	else
		return 0;
}

int is_empty(QueueType* q) {
	if (q->rear == q->front) return 1;
	else return 0;
}

void enqueue(QueueType* q, int item) {
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		return -1;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	int item = q->data[q->front];
	return item;
}

int size(QueueType* q) {
	if (q->rear - q->front < 0) return -(q->rear - q->front);
	else return q->rear - q->front;
}

int main()
{
	QueueType q;
	init_queue(&q);
	int n;
	char a[6];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", a);
		if (strcmp(a, "push") == 0) {
			int num;
			scanf("%d", &num);
			enqueue(&q, num);
		}
		else if (strcmp(a, "pop") == 0) {
			printf("%d\n", dequeue(&q));
		}
		else if (strcmp(a, "size") == 0) {
			printf("%d\n", size(&q));
		}
		else if (strcmp(a, "empty") == 0) {
			printf("%d\n", is_empty(&q));
		}
		else if (strcmp(a, "front") == 0) {
			if (is_empty(&q) == 1) printf("%d\n", -1);
			else printf("%d\n", q.data[q.front + 1]);
		}
		else if (strcmp(a, "back") == 0) {
			if (is_empty(&q) == 1) printf("%d\n", -1);
			else printf("%d\n", q.data[q.rear]);
		}
	}
}