#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

typedef struct
{
	int varFirst;
	int varSecond;
} Data ;



void* ThreadFunction1(void* args)
{

	Data* str = (Data*)args;
	printf("A * B = %d \n", str->varFirst * str->varSecond);
	printf("B / A = %d \n", str->varSecond / str->varFirst);
	pthread_exit(NULL);
}



void* ThreadFunction2(void* args)
{

	Data* str = (Data*)args;
	printf("A + B = %d \n", str->varFirst + str->varSecond);
	printf("A - B = %d \n", str->varFirst - str->varSecond);
	pthread_exit(NULL);
}

void* ThreadFunction3(void* a)
{
	int* b = (int*)a;
	printf("%d",*b);
	pthread_exit(NULL);
}



void main(){

	Data s1;
	pthread_t thread1,thread2;
	
	s1.varFirst = 255;
	s1.varSecond = 1785;
	
	int result_thread1 = pthread_create(&thread1,NULL,ThreadFunction1,(void*)&s1);
	//int result_thread2 = pthread_create(&thread2,NULL,ThreadFunction2,(void*)&s1);
	int result_thread2 = pthread_create(&thread2,NULL,ThreadFunction3,&s1.varFirst);
	
	if(result_thread1==0 && result_thread2==0)
	//if(result_thread2==0)
	{
		printf("Threads Created Successfully! \n");
	} 
	else 
	{
		printf("Threads Creation Failed !! \n");
	}
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);	

}
