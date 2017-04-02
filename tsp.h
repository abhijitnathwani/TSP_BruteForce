#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define DEBUG 0
#define N 10

extern int adj[N][N];//={{0,210,260,110},{210,0,440,280},{260,440,0,150},{110,280,150,0}};

struct message {
    int val;
    const char *msg;
};

void sort(int *,int *,int);
void result(int n,int city[][n+1],int *dist,int count,int (*adj)[N]);
void generateAdjMatrix(int *n,int *num,int (*adj)[N]);
int fact(int n);