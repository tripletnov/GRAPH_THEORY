#include<stdio.h>
#include"method_edge_list.c"

int MARK[500], p[500], pi[500];

void mooredijkstra(Graph *g, int s)
{
	int it,i,u,v,w;

	for(i=1;i<=g->n;i++)
	{
		p[i]=-1;
		pi[i]=99999999;
	}

	for(it=1;it<g->n;it++)
	{

		for(i=0;i<g->m;i++)
		{
			u=g->edges[i].u;
			v=g->edges[i].v;
			w=g->edges[i].w;
			if(pi[u]+w < pi[v])
			{
				pi[v]=pi[u]+w;
				p[v]=u;

			}
		}
	}
}

int main()
{
	return 0;
}
