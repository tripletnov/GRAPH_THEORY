#define MAX_EDGE 500

typedef struct
{
	int u,v,w;
}Edge;

typedef struct
{
	Edge edges[MAX_EDGE];
	int n,m;
}Graph;

void init_graph(Graph *g, int n)
{
	g->n=n;
	g->m=0;
}

void add_edge(Graph *g, int u, int v, int w)
{
	g->edges[g->m].u=u;
	g->edges[g->m].v=v;
	g->edges[g->m].w=w;
	g->m+=1;
}
