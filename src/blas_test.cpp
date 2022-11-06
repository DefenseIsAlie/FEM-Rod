#include <cblas.h>
#include <iostream>
#include <chrono>


int main(int argc, char **argv){
    
    double *A = new double[1024*1024];
    double *B = new double[1024*1024];

    double *C = new double[1024*1024];

    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1024, 1024, 1024, 1, A, 1024, B, 1024, 1, C, 1024);
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

    double mul_time = std::chrono::duration<double, std::milli>(end - start).count();
    std::cout << "Time take for multiplication is "<< mul_time << " ms" << std::endl;

    return 0;
}