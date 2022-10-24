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
