#include<vector>
#include<math.h>

class polynomial
{
private:
    std::vector<double> coeffxp;
    std::vector<double> coeffxn;
public:
    polynomial(std::vector<double> x, std::vector<double> y);
    ~polynomial();

    double getPx(double x);

    double getIntegral(double start, double end, int steps)
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
        for(int i = 0; i < this->coeffxn.size(); i++){
            ret += this->coeffxn[i]*pow(x, -(i+1));
        }
        for(int i = 0; i < this->coeffxp.size(); i++){
            ret += this->coeffxp[i]*pow(x, i);
        }

        return ret;
}

double polynomial::getIntegral(double start, double end, int steps){
    double step_size = (start - end)/steps;
    double ret = 0;

    for (size_t i = 0; i < steps; i++)
    {
        ret += this->getPx()*step_size;
    }
    

    return ret;
}