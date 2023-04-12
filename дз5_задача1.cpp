#include <iostream>
using namespace std;

int main()
{
    const int M = 3;
    const int N = 2;
    const int K = 4;


    int A[M][N] = { {1, 2}, {3, 4}, {5, 6} };
    int B[N][K] = { {1, 2, 3, 4}, {5, 6, 7, 8} };

   
    int C[M][K] = {};

   
    for (int i = 0; i < M; i++)
    {
        for (int k = 0; k < K; k++)
        {
            for (int j = 0; j < N; j++)
            {
                C[i][k] += A[i][j] * B[j][k];
            }
        }
    }

  
    for (int i = 0; i < M; i++)
    {
        for (int k = 0; k < K; k++)
        {
            cout << C[i][k] << " ";
        }
        cout << endl;
    }

    return 0;
}
