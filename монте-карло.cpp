#include <iostream>
#include <random>
#include <chrono>
#include <omp.h>

int main()
{
   
    const int N = 10000000;

    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(-1.0, 1.0);

   
    int num_threads = 8;

    
    auto start_time = std::chrono::steady_clock::now();

    
    double count = 0.0;
#pragma omp parallel num_threads(num_threads)
    {
        int id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        int chunk_size = N / num_threads;
        int start = id * chunk_size;
        int end = (id + 1) * chunk_size;
        double local_count = 0.0;

        for (int i = start; i < end; i++)
        {
            double x = dis(gen);
            double y = dis(gen);
            if (x * x + y * y <= 1.0)
            {
                local_count++;
            }
        }

#pragma omp atomic
        count += local_count;
    }

   
    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

   
    double pi = 4.0 * count / N;
    std::cout << "Pi = " << pi << std::endl;
    std::cout << "Elapsed time: " << elapsed_time << " ms" << std::endl;

    return 0;
}
