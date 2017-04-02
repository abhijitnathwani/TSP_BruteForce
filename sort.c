#include "tsp.h"


void sort(int *dist,int *ans,int possiblepaths)
{
    int i,min,j;
    min=INT_MAX;
    for(i=0;i<possiblepaths;i++)
    {
        if(dist[i]<=min)
        {
            min=dist[i];        
        }
    }
    for(j=0;j<possiblepaths;j++)
    {
        if(dist[j]==min)
        {
            if(DEBUG)
                printf(" 1  %d  %d",dist[j],j);
            ans[j]=j;
            if (DEBUG)
                printf(" 1  %d  %d",ans[j],j);
        }
        else
        {
            if(DEBUG)
                printf("2  %d  %d",dist[j],j);
            ans[j]=0;
            if(DEBUG)
                printf(" 2  %d  %d",ans[j],j);
        }
    }
}