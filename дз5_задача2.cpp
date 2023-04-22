#include <iostream>
#include <thread>

#define M 2000
#define N 2000
#define K 2000

int A[M][N];
int B[N][K];
int C[M][K];

void matrix_multiply(int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    std::cout << "Starting matrix multiplication with 64 threads..." << std::endl;


    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i + j;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            B[i][j] = i + j;
        }
    }

    std::thread threads[64];
    int block_size = M / 64;
    for (int i = 0; i < 64; i++) {
        int start = i * block_size;
        int end = start + block_size;
        threads[i] = std::thread(matrix_multiply, start, end);
    }


    for (int i = 0; i < 64; i++) {
        threads[i].join();
    }

    std::cout << "Matrix multiplication complete." << std::endl;
    return 0;
}

