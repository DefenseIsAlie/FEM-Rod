#include <cblas.h>


int main(int argc, char **argv){
    
    double *A = new double[1024*1024];
    double *B = new double[1024*1024];

    double *C = new double[1024*1024];
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1024, 1024, 1024, 1, A, 1024, B, 1024, 1, C, 1024);

    return 0;
}