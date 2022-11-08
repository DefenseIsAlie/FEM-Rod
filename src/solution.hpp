#include<Eigen/Dense>
#include<vector>
#include<include/polynomial.hpp>
#include<fstream>

namespace sol
{

    void constantsolution(int n){
    int N = n;
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
        Kvalues[i][0] = Y*Ao/h;
        Kvalues[i][1] = -Y*Ao/h;
        Kvalues[i][2] = -Y*Ao/h;
        Kvalues[i][3] = Y*Ao/h;

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
    // newF(0,0) = P;
     Eigen::MatrixXd U = newK.inverse()*newF;

    Eigen::MatrixXd solution = Eigen::MatrixXd::Zero(N+1,2);
    for (int i = 0; i < N; i++)
    {
        solution(i,0) = i*h;
        solution(i,1) = U(i,0);
    }
    solution(N,0) = L;
    solution(N,1) = 0;

    // print solution to file.txt
    std::ofstream file;
    file.open("file.txt");
    file << "\t \t\tX , U(i)" << "\n";
    file << solution;
    file.close();
}

void variableSolution(int n){
    
    int N = n;
    // std::cout << "Enter N: ";
    // std::cin >> N;
    // if (N < 2)
    // {
    //     std::cout << "N must be greater than 2" << std::endl;
    //     return 0;
    // }

    double L = 0.5;
    // std::cout << "Enter L: ";
    // std::cin >> L;
    // if (L < 0)
    // {
    //     std::cout << "L must be greater than 0" << std::endl;
    //     return 0;
    // }

    double Ao = 12.5 * pow(10, -4);
    // std::cout << "Enter Ao: ";
    // std::cin >> Ao;
    // if (Ao < 0)
    // {
    //     std::cout << "Ao must be greater than 0" << std::endl;
    //     return 0;
    // }

    double Y = 70 * pow(10, 9);
    // std::cout << "Enter Y: ";
    // std::cin >> Y;
    // if (Y < 0)
    // {
    //     std::cout << "Y must be greater than 0" << std::endl;
    //     return 0;
    // }

    double P = -5000;
    // std::cout << "Enter P: ";
    // std::cin >> P;
    // if (P < 0)
    // {
    //     std::cout << "P must be greater than 0" << std::endl;
    //     return 0;
    // }

    std::vector<double> x(3);

    // std::cout << "Enter polynomial coefficients of Area polynomial(divided by A0): " << std::endl;
    // std::cout << "For example 1 2 for given question A0*(1+x/L) that is A0(1+2x) given L = 0.5" << std::endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     std::cout << "Enter coefficient of x^" << i << ": ";
    //     std::cin >> x[i];
    // }
    polynomial p1({1,2, 0},{0});



    double h = L/N;

    Eigen::MatrixXd K = Eigen::MatrixXd::Zero(N+1,N+1);
    Eigen::MatrixXd F = Eigen::MatrixXd::Zero(N+1,1);

    double xb, xa;

    std::vector<std::vector<double>> Kvalues(N,std::vector<double>(4));

    
    

    for (int i = 0; i < N; i++)
    {   
        double xa = i*h;
        double xb = (i+1)*h;
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
    Eigen::MatrixXd newK = K.block(0,0,N,N);
    Eigen::MatrixXd newF = F.block(0,0,N,1);
    Eigen::MatrixXd U = newK.inverse()*newF;

    //std::cout << K << "\n" << "\n" <<std::endl;
    //std::cout << newK << "\n" << "\n" <<std::endl;

    
    Eigen::MatrixXd solution = Eigen::MatrixXd::Zero(N+1,2);
    for (int i = 0; i < N; i++)
    {
        solution(i,0) = i*h;
        solution(i,1) = U(i,0);
    }
    solution(N,0) = L;
    solution(N,1) = 0;

    // print solution to file.txt
    std::ofstream file;
    file.open("file.txt");
    file << "\t \t\tX , U(i)" << "\n";
    file << solution;
    file.close();
    
}
    
} // namespace sol


