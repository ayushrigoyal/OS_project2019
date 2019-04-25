// 11709523
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h> 

int main()
{
	int i;
	int flag;
	int P,Q; 
	printf("\nEnter the number of resources of the same type\n");
	scanf("%d",&P);
	
	printf("\nEnter the number of processes\n");
	scanf("%d",&Q);
	
	int pId[Q];
	int needs[Q];
	
	for(i=0;i<Q;i++)
	{ 
		pId[i] = i+1;
	}
	
	int need_total = 0;
	flag=0;
	int safe_sequence[Q];
	
	for(i=0;i<Q;i++)
	{
		printf("\n Enter the maximum need for process %d\n",pId[i]);
		scanf("%d",&needs[i]);
		
		if(needs[i]>P) 
		{
			flag=1; 
			break;
		}
		
		need_total+=needs[i];
		if(flag!=1) safe_sequence[i] = pId[i]; 
	}
	
	if(need_total>(P+Q))
	{
		flag=1;
	}
	
	if(flag==1)
	{
		printf("\nDEADLOCK OCCURENCE, safe sequence does not exist");
	}
	else
	{
		printf("Safe Sequence:\n");
		for(i=0;i<Q;i++)
		{
			printf("%d ",safe_sequence[i]);
		}
		 
	}		
}
