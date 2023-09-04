#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mutex;

void* thread_function(void* args){
	pthread_mutex_lock(&mutex);
	
	printf("Thread %d Started\n",*(int*)args);
	
	for(int i=1;i<=5;i++){
		printf("thread %d, loop %d \n",*(int*)args, i);	
	}
	
	printf("Thread %d Ended\n",*(int*)args);
	
	pthread_mutex_unlock(&mutex);
	
	pthread_exit(NULL);
	
}

void main(){

	pthread_t threads[10];
	int argu[10];
	
	
	for(int i=1;i<=10;i++){
		argu[i-1] = i;
		pthread_create(&threads[i-1],NULL,thread_function,&argu[i-1]);
	}
	pthread_mutex_init(&mutex,NULL);
	for(int i=1;i<=10;i++){
		
		pthread_join(threads[i-1],NULL);
		
	}
	pthread_mutex_destroy(&mutex);


}


