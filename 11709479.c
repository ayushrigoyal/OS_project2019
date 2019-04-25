
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
	
	
}
