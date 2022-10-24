#include<stdio.h>
#include"method_adjency_matrix.c"

#define white 0
#define gray 1
#define black 2
int color[500];
int circle;

void dfs(Graph *g, int u)
{
	color[u]=gray;

	int i;
	for(i=1;i<=g->n;i++)
		if(adj(g,u,i))
		{
			if(color[i]==white)
				dfs(g,i);
			else if(color[i]==gray)
			{
				circle=1;
				printf("%d ",i);
			}
		}
	color[u]=black;

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

	dfs(&G,1);
	if(circle)
		printf("CIRCLE");
	else
		printf("NO CIRCLE");

	return 0;
}
