#define MAX_ELEMENTS 500
typedef int ElementType;
typedef struct
{
	int top;
	int data[MAX_ELEMENTS];
}Stack;

void make_null_stack(Stack *s)
{
	s->top=-1;
}

int empty(Stack *s)
{
	return s->top==-1;
}

void push(Stack *s, int x)
{
	s->top+=1;
	s->data[s->top]=x;
}

void pop(Stack *s)
{
	s->top-=1;
}

int top(Stack *s)
{
	if((empty(s)==0))
		return s->data[s->top];
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
