#include <Eigen/Dense>
#include <iostream>
#include <chrono>

int main(int argc, char **argv){
    Eigen::MatrixXd m = Eigen::MatrixXd::Random(1024,1024);
    Eigen::MatrixXd n = Eigen::MatrixXd::Random(1024,1024);

    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    Eigen::MatrixXd o = m*n;
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

    double mul_time = std::chrono::duration<double, std::milli>(end - start).count();
    std::cout << "Time take for multiplication is "<< mul_time << " ms" << std::endl;
    
    return 0;
}