#include<stdio.h>
#include"method_adjency_matrix.c"

#define no_color 0
#define blue 1
#define red 2

int color[500];
int conflict;

void colorize(Graph *g, int u, int c)
{
	color[u]=c;

	int i;
	for(i=1;i<=g->n;i++)
	{
		if(adj(g,u,i))
		{
			if(color[i]==no_color)
				colorize(g,i,3-c);
			else if(color[i]==color[u])
				conflict=1;
		}
	}
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
		color[i]=no_color;
	colorize(&G,1,red);
	if(conflict)
		printf("NO");
	else
		printf("YES");
	return 0;
}
