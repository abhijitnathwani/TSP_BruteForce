#include "tsp.h"

void generateAdjMatrix(int *n,int *num, int (*adj)[N])
{
	FILE *fp;
	fp = fopen("cities_num.csv","r+");
	char line[100];
	char cityn[100];
	
	// printf("Enter the number of cities: \n");
	// scanf("%d",n);
	int cityd[15][15];
	int cities[*n][*n];
	int cityp[*n];
	char *token;
	printf("Enter the preferences of cities\n");
	int j;
	for (int j = 0; j < *n; ++j)
	{
		scanf("%d",&num[j]);
	}
	//num[j]='\0';
	int count=0;
	for (int i = 0; i < *n; ++i)
	{
		while(count<=num[i])
		{
			fgets(line,100,fp);
			count++;
		}
		if(DEBUG)
			printf("Line: %d\n",num[i] );
		
		token=strtok(line,",");
		int k=0;
	
		while(token!=NULL)
		{
	
		
			cityd[i][k]= atoi(token);
				
			if(DEBUG)
				printf("%d \n",cityd[i][k]);
			token=strtok(NULL,",");
			k++;
		}
		for (int s = 0; s < *n; ++s)
		{
			for (int j = 0; j <*n ; ++j)
			{
				int m=num[j];				
				cities[s][j]=cityd[s][m];
				adj[s][j]=cityd[s][m];	
			}
			
		}
		rewind(fp);
		count=0;
	}
	printf("Adjacency Matrix: \n");
	for (int i = 0; i < *n; ++i)
		{
			for (int j = 0; j < *n; ++j)
			{
				printf("%d ",cities[i][j] );
				//printf("Adj: %d\n", adj[i][j] );
			}
			printf("\n");	
		}	
	fclose(fp);
}
