#include <stdio.h>

int main()
{
	
	FILE *fptr;
	fptr = fopen("read.txt","r");
	if(fptr==NULL){
		printf("Something went wrong\n");
		return 1;
	}
	
	int temp;
	for(int i=0; i<10; i++){
		fscanf(fptr,"%d",&temp);
		printf("Loop %d : %d\n",i,temp);
	}
	
	return 0;
}
