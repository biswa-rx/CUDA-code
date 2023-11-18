#include<stdio.h>
#include<stdlib.h>

void matrix_vector_product(float *A, float *v1,float *v2,int matrix_size) {
    for(int i = 0; i < matrix_size; i++) {
        float sum = 0.0f;
        for(int j = 0; j < matrix_size; j++) {
            sum += A[i*matrix_size + j] * v1[j];
        }
        v2[i] = sum;
    }
}

int main(int argc, char **argv) {
    float *A, *v1, *v2;
    int matrix_size = 4000;

    A  = (float *)malloc(matrix_size * matrix_size * sizeof(float));
    v1 = (float *)malloc(matrix_size * sizeof(float));
    v2 = (float *)malloc(matrix_size * sizeof(float));


    //initilization
    for(int i = 0; i < matrix_size; i++) {
        v1[i] = (float) i;
        for (int j = 0; j < matrix_size; j++)
        {
            A[i * matrix_size + j] = i*matrix_size + j;
        }
    }
    
    matrix_vector_product(A, v1, v2, matrix_size);

    for(int i = 0; i < matrix_size; i++) {
        printf("%.2f\n",v2[i]);
    }

    return 0;
}