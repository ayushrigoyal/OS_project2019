
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>//header for file operation calls if needed
#include<sys/types.h>//header for system calls 

int main()
{
	int i;//loop iterator
	int flag;//tracker for deadlock occurence
	int P,Q;// P for no of resources of same type, Q for number of processes 
	printf("\nEnter the number of resources of the same type\n");//we can have P resources of same type as given in question
	scanf("%d",&P);
	
	printf("\nEnter the number of processes\n");//Q number of processes sharing the resource
	scanf("%d",&Q);
	
	int pId[Q];//array for storing the process IDs with Q number of Processes
	int needs[Q];//corresponding array for maximum need of each Process
	
	for(i=0;i<Q;i++)
	{  /*
		if(flag==1)
		{
			--i;
			flag=0; //so that in the next iteration this block can be avoided
		}
		
		pid_t pid1 = fork();
		if(pid1 < 0)
		{
			flag=1; //tracker 
			continue;	
		}
		else if(pid1 > 0)
		{
			sleep(1);//we want the parent process to wait so that the child executes first
		}
		else // condition if pid1 == 0 for child process
		{
			pId[i] = getpid();
		}
		*/
		pId[i] = i+1;
	}//Processes created and their ids stored in pId array
	
	int need_total = 0; // variable for summation of maximum need
	flag=0;// tracker now being used to detect the failure of condition for necessary safe sequence
	int safe_sequence[Q];
	
	for(i=0;i<Q;i++)
	{
		printf("\n Enter the maximum need for process %d\n",pId[i]);
		scanf("%d",&needs[i]);
		
		if(needs[i]>P) //condition for "strict safe sequence" to fail  
		{
			flag=1; 
			break;
		}
		
		need_total+=needs[i];
		if(flag!=1) safe_sequence[i] = pId[i]; 
	}
	
	if(need_total>(P+Q))//another criteria given for deadlock to occur
	{
		flag=1;
	}
	
	if(flag==1)// in any way, i.e., by absence of "strict safe sequence" or by 2nd criteria deadlock occurs
	{
		printf("\nDEADLOCK OCCURENCE, safe sequence does not exist");
	}
	else
	{
		printf("Safe Sequence:\n");
		for(i=0;i<Q;i++)
		{
			printf("%d ",safe_sequence[i]);
		}// will always occur in the same sequence as process ids as otherwise deadlock condition has been made to satisfy
		 // in case of absence of "strict safe sequence"
		 
	}		
}
