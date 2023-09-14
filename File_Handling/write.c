#include <stdio.h>

int main()
{
	
	int num;
	printf("Enter num: ");
	scanf("%d",&num);
	
	FILE *fptr;
	fptr = fopen("write.txt","w");
	
	if(fptr==NULL){
		printf("something went wrong");
		return 1;
	}
	
	fprintf(fptr,"%d",num);
	fclose(fptr);
	
	return 0;
}
