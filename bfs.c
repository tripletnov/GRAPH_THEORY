#include<stdio.h>

//int O[500];
//#include"method_adjency_matrix.c"
//#include"queue.c"

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
//        if((empty(q)==0))
                return q->data[q->front];
}



int MARK[500];

//int O[500];

#define MAX_N 500

typedef struct
{
        int A[MAX_N][MAX_N];
        int n,m;
}Graph;

void init_graph(Graph *g, int n)
{
        g->n=n;
        g->m=0;
        int i,j;

        for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                        g->A[i][j]=0;
}

void add_edge(Graph *g, int u, int v)
{
        g->A[u][v]=1;
        g->A[v][u]=1;
        g->m+=1;
}

int adj(Graph *g, int u, int v)
{
	return g->A[u][v];
}

void bfs(Graph *g, int s)
{
	int i;
/*	for(i=1;i<=g->n;i++)
		MARK[i]=0;
*/
	Queue Q;
	make_null_queue(&Q);

//	MARK[s]=1;

	enqueue(&Q,s);

//	int k=0;
	while(!empty(&Q))
	{
		int u=front(&Q);
		dequeue(&Q);

		if(MARK[u]!=0)
			continue;

		MARK[u]=1;

//		k++;
//		O[k]=u;
		printf("%d\n",u);

		for(i=1;i<=g->n;i++)
		{
			if(MARK[i]==0 && adj(g,u,i))
			{
//				if(p[i]==-1)
//					p[i]=u;
				enqueue(&Q,i);
			}
		}
	};
}

int main()
{
	freopen("dt.txt", "r", stdin);
	int n,m;
	scanf("%d %d", &n, &m);
	int i,u,v;

	Graph G;
	init_graph(&G,n);

	for(i=0;i<m;i++)
	{
		scanf("%d %d", &u,&v);
		add_edge(&G,u,v);
	}

	for(i=1;i<=n;i++)
	{
//		O[i]=-1;
		MARK[i]=0;
	}

	bfs(&G,1);
	for(i=1;i<=n;i++)
		if(MARK[i]==0)
			bfs(&G,i);

//	for(i=1;i<=n;i++)
//		printf("%d\n",O[i]);
	return 0;
}

