#include "tsp.h"

//adj[4][4]={{0,210,260,110},{210,0,440,280},{260,440,0,150},{110,280,150,0}};
void result(int n,int city[][n+1],int *dist,int count,int (*adj)[N])
{
    int sum=0;
    for (int p = 0; p < count; ++p)
    {
        sum=0;
        for (int q = 0; q < (n+1); ++q)
        {
            sum = sum + adj[city[p][q]-1][city[p][q+1]-1];
        }
        dist[p]=sum;
        if (DEBUG)
            printf("Sum %d: %d\n",p,sum );
    }

}
