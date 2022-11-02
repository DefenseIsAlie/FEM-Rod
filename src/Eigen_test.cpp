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


    
    start = std::chrono::high_resolution_clock::now();
    Eigen::MatrixXd transpose = o.transpose();
    end = std::chrono::high_resolution_clock::now();

    mul_time = std::chrono::duration<double, std::milli>(end - start).count();
    std::cout << "Time take for transpose is "<< mul_time << " ms" << std::endl;
    
    
    
    start = std::chrono::high_resolution_clock::now();
    Eigen::MatrixXd inverse = o.inverse();
    end = std::chrono::high_resolution_clock::now();

    mul_time = std::chrono::duration<double, std::milli>(end - start).count();
    std::cout << "Time take for inverse is "<< mul_time << " ms" << std::endl;



    std::cout << "Size of o matrix is " << o.size()/1024 << "\n";
    Eigen::VectorXd b = Eigen::VectorXd::Random(1024);
    std::cout << "Size of b is " << b.size() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    Eigen::VectorXd x = o.colPivHouseholderQr().solve(b);
    end = std::chrono::high_resolution_clock::now();

    mul_time = std::chrono::duration<double, std::milli>(end - start).count();
    std::cout << "Solved ox = b in "<< mul_time << " ms" << std::endl;

    std::cout << "Size of x is " << x.size() << std::endl;

    return 0;
}