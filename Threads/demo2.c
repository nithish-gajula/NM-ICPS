#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    int thread_num = *(int*)arg;

    printf("Thread %d: Start\n", thread_num);

    for (int i = 0; i < 5; i++) {
        printf("Thread %d: Iteration %d\n", thread_num, i+1);
    }

    printf("Thread %d: End\n", thread_num);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    int thread_arg = 1;

 	for(int i=1;i<=5;i++){
 	
 	pthread_create(&thread, NULL, thread_function, &i);
 	pthread_join(thread, NULL);
 	
 	}

    return 0; 
}

