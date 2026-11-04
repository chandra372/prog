
#include <stdio.h>

struct Router {
    int distance[10], nextHop[10];
} rt[10];

int main() {
    int cost[10][10], n, i, j, k, update;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) {
            scanf("%d", &cost[i][j]);
            rt[i].distance[j] = cost[i][j];
            rt[i].nextHop[j] = j;
        }

    do {
        update = 0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                    if(rt[i].distance[j] > cost[i][k] + rt[k].distance[j]) {
                        rt[i].distance[j] = cost[i][k] + rt[k].distance[j];
                        rt[i].nextHop[j] = k;
                        update = 1;
                    }
    } while(update);

    for(i=0;i<n;i++) {
        printf("\nRouting Table of Router %d\n", i+1);
        printf("Destination\tNext Hop\tDistance\n");
        for(j=0;j<n;j++)
            printf("%d\t\t%d\t\t%d\n", j+1,
                   rt[i].nextHop[j]+1, rt[i].distance[j]);
    }

    return 0;
}