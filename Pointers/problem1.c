#include <stdio.h>
void main(){
	
	char *c = "nithish";
	
	char **f = &c;
	
	printf("f = %s \n",*f);
}