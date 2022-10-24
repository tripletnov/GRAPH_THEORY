#include<stdio.h>
#include"method_adjency_matrix.c"
#include"stack.c"

int MARK[500];

void dfs(Graph *g, int s)
{
	int i;
	for(i=1;i<=g->n;i++)
		MARK[i]=0;

	Stack S;
	make_null_stack(&S);

//	MARK[s]=1;

	push(&S,s);

	while(!empty(&S))
	{
		int u=top(&S);
		pop(&S);

		if(MARK[u]!=0)
			continue;

		MARK[u]=1;

		printf("%d ",u);

		for(i=1;i<=g->n;i++)
		{
			if(MARK[i]==0 && g->A[u][i])
				push(&S,i);
		}
	};
}

int main()
{
	freopen("bfs.txt", "r", stdin);
        int n,m;
        scanf("%d %d", &n, &m);
        int i,j,u,v;

        Graph G;
        init_graph(&G,n);

        for(i=0;i<m;i++)
        {
                scanf("%d %d", &u,&v);
                add_edge(&G,u,v);
        }

        dfs(&G,1);
	return 0;
}

