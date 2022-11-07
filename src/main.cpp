#include <iostream>
#include <include/polynomial.hpp>
#include <Eigen/Dense>
#include <vector>

int main(int argc, char const *argv[])
{   
    
    /*
        TODO:   constants Definition
                K matrix
                F matrix

        Ao = 12.5 * 10^-4
        A(x) = Ao*(1+x/L)

        x=0,L
        L = 0.5m
        Y = 70 GPa
        N = 2,8,32,128
    */

    int N = 16;
    double L = 0.5;
    double Ao = 12.5 * pow(10,-4);
    double Y = 70 * pow(10,9);
    double h = L/N;
    double P = 5000;

    Eigen::MatrixXd K = Eigen::MatrixXd::Zero(N+1,N+1);
    Eigen::MatrixXd F = Eigen::MatrixXd::Zero(N+1,1);

    double xb, xa;

    std::vector<std::vector<double>> Kvalues(N,std::vector<double>(4));

    
    

    for (int i = 0; i < N; i++)
    {   
        double xa = i*h;
        double xb = (i+1)*h;
        polynomial p1({1,1/L},{0});
        double integral = ((Y*Ao)/ (h*h))*p1.twoPointGuassQuadratureIntegral(xb,xa);

        Kvalues[i][0] = integral;
        Kvalues[i][1] = -integral;
        Kvalues[i][2] = -integral;
        Kvalues[i][3] = integral;
    }
    

    for (int i = 0; i < N+1; i++)
    {
        for (int j = 0; j < N+1; j++)
        {
            if (i == 0 && j == 0)
            {
                K(i,j) = Kvalues[0][0];
            }
            else if(i == N  && j == N){
                K(i,j) = Kvalues[N-1][3];
            }
            else if (i == j)
            {
                K(i,j) = Kvalues[i-1][3] + Kvalues[i][0];
            }
            else if (i == j-1)
            {
                K(i,j) = Kvalues[i][1];
            }
            else if (i == j+1)
            {
                K(i,j) = Kvalues[i-1][2];
            }
        }
    }


    F(0,0) = P;

  // F.resize(N,1);
    Eigen::MatrixXd newK = K.block(0,1,N,N);
    Eigen::MatrixXd newF = F.block(0,0,N,1);
    Eigen::MatrixXd U = newK.inverse()*newF;

//     std::cout << newK << std::endl;
//     std::cout << newF << std::endl;
//     std::cout << F << std::endl;

     std::cout << U.reverse() << std::endl;

    polynomial test({1,1},{0});
    std::cout << test.twoPointGuassQuadratureIntegral(10,0) << std::endl;
    
    
    
    return 0;
}
