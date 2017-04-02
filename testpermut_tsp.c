#include "tsp.h"

//#define N 10
 
int j=0;


// void print(int *num, int n,int (*city)[n+1],int j)
// {
//     int i;
//     for ( i = 0 ; i < n ; i++)
//     {
//         printf("%d ", num[i]);
//         city[j][i]=num[i];
//     }
//     city[j][i]=city[0][0];
//     printf("\n");
// }
int z=0;
void swap(int *a,int *b)
{
	int temp;
	temp=*b;
	*b=*a;
	*a=temp;
}
void printArr(int a[],int sizeofnum,int j,int n,int (*city)[n+1])
{
	int i;
	for (i=0; i<sizeofnum; i++)
	{
		printf("%d ",a[i]);
		city[j][i]=a[i];
	}
	city[j][i]=city[0][0];
	printf("\n");
	z++;
}
void heapPermutation(int a[], int size,int sizeofnum, int n,int (*city)[n+1])
{
	// if size becomes 1 then prints the obtained
	// permutation
	
	if (size == 1)
	{
		printArr(a, sizeofnum,j,n,city);
		j++;
		return;
	}

	for (int i=1; i<size; i++)
	{
		heapPermutation(a,size-1,sizeofnum,n,city);

		// if size is odd, swap first and last
		// element
		if (size%2==1)
			swap(&a[1], &a[size-1]);

		// If size is even, swap ith and last
		// element
		else
			swap(&a[i], &a[size-1]);
	}
}

int main()
{
    struct message messages[] = {
        {1, "Ahmedabad"},
        {2, "Rajkot"},
        {3, "Surat"},
        {4, "Vadodara"},
        {5, "Jamnagar"},
        {6, "Junagadh"},
        {7, "Mehsana"},
        {8, "Bhavnagar"},
        {9, "Kodinar"},
        {10, "Patan"},
    };

    
    
    int temp;
    int i, n, j;
    int adj[N][N];
    // printf("\nHow many number you want to enter: ");
    //     scanf("%d", &n);
    int possiblepaths;

    
    printf("Enter the number of cities: \n");
	scanf("%d",&n);
	int num[n];
    generateAdjMatrix(&n,num,adj);
    possiblepaths=fact(n-1);
    printf("%d\n", possiblepaths );
    int city[possiblepaths][n+1];
    int dist[possiblepaths];
    int ans[possiblepaths];
    int count=sizeof(dist)/sizeof(dist[0]);
    // printf("\nEnter a list of numbers to see all combinations:\n");
    // for (i = 0 ; i < n; i++)
    //     scanf("%d", &num[i]);
    printf("\n");
    int row;
    int sizeofnum = sizeof(num)/sizeof(num[0]);
    heapPermutation(num, sizeofnum, sizeofnum, n,city);
    // for (j = 2,row=0; j <= n; j++) {
    //     for (i = 1; i < n-1; i++,row++) {
    //         temp = num[i];
    //         num[i] = num[i+1];
    //         num[i+1] = temp;
    //         print(num, n, city,row);
	   // }
    // }
    printf("\n");
    printf("Count: %d\n",z );

    // for (int i = 0; i < possiblepaths; ++i)
    // {
    //     for (int j = 0; j < n+1; ++j)
    //     {
    //         printf("%d ",city[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("\n");
    result(n,city,dist,count,adj);
    if(DEBUG)
    {
        for (int i = 0; i<possiblepaths; ++i)
        {
            printf("%d \n", dist[i]);
        }
    }
    sort(dist,ans,possiblepaths);
    for (int i = 0; i<possiblepaths; ++i)
    {
        printf("%d \n", ans[i]);
    }
    printf("Optimal Path\n");			
    for (int i = 0; i < possiblepaths; ++i)
    {
    	for (int j = 0; j < n+1; ++j)
    	{
    	    if(ans[i]>0)
    	 		printf("%s -> ",messages[city[i][j]+1].msg );
    	 	else 
    	 		break;
    	}
    	printf("\n");

    }
    printf("\n");
    return 0;
}