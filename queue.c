#include<stdio.h>
#define MAX_ELEMENTS 500
typedef int ElementType;
typedef struct
{
	int front,rear;
	int data[MAX_ELEMENTS];
}Queue;

void make_null_queue(Queue *q)
{
	q->front=0;
	q->rear=-1;
}

int empty(Queue *q)
{
	return q->rear < q->front;
}

void enqueue(Queue *q, int x)
{
	q->rear+=1;
	q->data[q->rear]=x;
}

void dequeue(Queue *q)
{
	if((empty(q)==0))
		q->front+=1;
}

int front(Queue *q)
{
//	if((empty(q)==0))
		return q->data[q->front];
}

/*int main()
{
	Queue Q;
	make_null_queue(&Q);

	printf("Queue is Empty %d \n", empty(&Q));
	enqueue(&Q,10);
	printf("Queue is Empty %d \n", empty(&Q));
	printf("%d\n", front(&Q));

	dequeue(&Q);
	enqueue(&Q,10);
	printf("%d\n", front(&Q));
	dequeue(&Q);
	printf("%d\n", front(&Q));
	return 0;
}

*/
