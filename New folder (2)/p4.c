
#include <stdio.h>

#define INF 9999

int main() {
    int n, src, cost[10][10], dist[10], vis[10]={0};
    int i, j, u, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter starting vertex (0 to %d): ", n-1);
    scanf("%d", &src);

    for(i=0; i<n; i++)
        dist[i] = (i==src) ? 0 :
                  (cost[src][i]==0 ? INF : cost[src][i]);

    vis[src] = 1;

    for(i=1; i<n; i++) {
        min = INF;
        u = -1;

        for(j=0; j<n; j++)
            if(!vis[j] && dist[j]<min)
                min=dist[j], u=j;

        if(u==-1) break;

        vis[u]=1;

        for(j=0; j<n; j++)
            if(!vis[j] && cost[u][j]!=0 &&
               dist[u]+cost[u][j]<dist[j])
                dist[j]=dist[u]+cost[u][j];
    }

    printf("\nShortest distances from %d:\n", src);
    for(i=0; i<n; i++)
        if(dist[i]==INF)
            printf("%d -> %d = Unreachable\n",src,i);
        else
            printf("%d -> %d = %d\n",src,i,dist[i]);

    return 0;
}