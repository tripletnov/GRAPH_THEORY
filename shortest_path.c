#include<stdio.h>
#include"method_adjency_matrix2.c"

int MARK[500], p[500], pi[500];

void mooredijkstra(Graph *g, int s)
{
	int it,i,u,v;

	for(i=1;i<=g->n;i++)
	{
		MARK[i]=0;
		p[i]=-1;
		pi[i]=99999999;
	}

	pi[s]=0;
	p[s]=-1;

	for(it=1;it<g->n;it++)
	{
		int min_pi=999999;
		for(i=1;i<=g->n;i++)
		{
			if(MARK[i]==0 && p[i]<min_pi)
			{
				min_pi=pi[i];
				u=i;
			}
		}

		MARK[u]=1;

		for(v=1;v<=g->n;v++)
			if(MARK[v]==0 && g->A[u][v]!=0)
				if(pi[u]+g->A[u][v] < pi[v])
				{
					pi[v]=pi[u]+g->A[u][v];
					p[v]=u;

				}
	}
}

int main()
{
        freopen("dt.txt", "r", stdin);
        int n,m;
        scanf("%d %d", &n, &m);
        int i,u,v,w;

        Graph G;
        init_graph(&G,n);

        for(i=0;i<m;i++)
        {
                scanf("%d %d %d", &u,&v,&w);
                add_edge(&G,u,v,w);
        }

	mooredijkstra(&G,1);
	for(i=1;i<=n;i++)
		printf("pi[%d]=%d p[%d]=%d\n",i,pi[i],i,p[i]);

	return 0;
}
