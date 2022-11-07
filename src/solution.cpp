#include<Eigen/Dense>
#include<vector>
#include<include/polynomial.hpp>

void solution(){
    int N = 128;
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
}