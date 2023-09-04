#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_MATRIX_ROWS 3

int matrixA[NUM_MATRIX_ROWS][NUM_MATRIX_ROWS];
int matrixB[NUM_MATRIX_ROWS][NUM_MATRIX_ROWS];
int matrixC[NUM_MATRIX_ROWS][NUM_MATRIX_ROWS];

void* fillMatrices(void *arg) {
    int thread_id = *(int *)arg;
    int row = thread_id / NUM_MATRIX_ROWS; // gives integer which is 0 1 2
    int col = thread_id % NUM_MATRIX_ROWS; // gives reminder which is 0 1 2 
    
    matrixA[row][col] = rand() % 100; // random positive integer for matrix A
    matrixB[row][col] = rand() % 100; // random positive integer for matrix B
    
    pthread_exit(NULL);
}

void* computeElement(void* arg){
	
    int thread_id = *(int *)arg;
    int row = thread_id / NUM_MATRIX_ROWS; // gives integer which is 0 1 2
    int col = thread_id % NUM_MATRIX_ROWS; // gives reminder which is 0 1 2 
    
    matrixC[row][col] = 0;
    for (int k = 0; k < NUM_MATRIX_ROWS; k++) {
        matrixC[row][col] += matrixA[row][k] * matrixB[k][col];
    }
    
    pthread_exit(NULL);
}

void printMatrix(int matrix[NUM_MATRIX_ROWS][NUM_MATRIX_ROWS]) {
    for (int i = 0; i < NUM_MATRIX_ROWS; i++) {
        for (int j = 0; j < NUM_MATRIX_ROWS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {


    srand(time(NULL)); // seed the random number generator
    
    pthread_t threads[NUM_MATRIX_ROWS * NUM_MATRIX_ROWS];
    int thread_ids[NUM_MATRIX_ROWS * NUM_MATRIX_ROWS];
    
    // Create threads to fill matrices A and B
    for (int i = 0; i < NUM_MATRIX_ROWS * NUM_MATRIX_ROWS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, fillMatrices, &thread_ids[i]);
    }
    
    // Wait for all threads to complete
    for (int i = 0; i < NUM_MATRIX_ROWS * NUM_MATRIX_ROWS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    for (int i = 0; i < NUM_MATRIX_ROWS * NUM_MATRIX_ROWS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, computeElement, &thread_ids[i]);
    }
    for (int i = 0; i < NUM_MATRIX_ROWS * NUM_MATRIX_ROWS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print matrix A
    printf("Matrix A:\n");
    printMatrix(matrixA);
    
    printf("\n");
    
    // Print matrix B
    printf("Matrix B:\n");
    printMatrix(matrixB);
    
    printf("\n");
    
    // Print matrix C
    printf("Matrix C:\n");
    printMatrix(matrixC);
    
    return 0;
    
}

