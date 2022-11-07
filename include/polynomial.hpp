#include<vector>
#include<math.h>
#include<iostream>

#ifndef POLYNOMIAL
#define POLYNOMIAL
class polynomial
{
private:
    std::vector<double> coeffxp;
    std::vector<double> coeffxn;
public:
    polynomial(std::vector<double> x, std::vector<double> y);
    ~polynomial();

    double getPx(double x);

    double getIntegral(double start, double end, int steps);

    double getnaturalfx(double b, double a, double x);

    double twoPointGuassQuadratureIntegral(double b, double a);
};

polynomial::polynomial(std::vector <double> x, std::vector<double> y)
{
    this->coeffxp = x;
    this->coeffxn = y;
}

polynomial::~polynomial()
{
}

double polynomial::getPx(double x){
    double ret = 0;

        if (abs(x!=0)){
        for(int i = 0; i < this->coeffxn.size(); i++){
            ret += this->coeffxn[i]*pow(x, -(i+1));
        }
        }
        for(int i = 0; i < this->coeffxp.size(); i++){
            ret += this->coeffxp[i]*pow(x, i);
        }

        return ret;
}

double polynomial::getIntegral(double start, double end, int steps){
    double step_size = (end - start)/(double)steps;
    double ret = 0;
    double x_curr = start;
   
    for (int i = 0; i < steps; i++)
    {
        ret += getPx(x_curr)*step_size;
        x_curr += step_size;
    }

    return ret;
}

double polynomial::getnaturalfx(double b, double a, double x){
    double ret = 0;
    ret = polynomial::getPx((b-a)/2 *x + (b+a)/2);
    return ret;
}

double polynomial::twoPointGuassQuadratureIntegral(double b, double a){
    double ret = 0;

    ret = 1 * polynomial::getnaturalfx(b, a, 1/sqrt(3)) + 1 * polynomial::getnaturalfx(b, a, -1/sqrt(3));

    return ret * (b-a) / 2;
}

#endif