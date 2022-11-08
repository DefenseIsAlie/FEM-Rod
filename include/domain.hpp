#include <include/polynomial.hpp>
#include <vector>

/*
    Todo:   Getters Setters
              
*/
#ifndef DOMAIN_
#define DOMAIN_

class domain
{
private:
    double Length;
    double YoungsModulus;
    polynomial *areaFunction;
    int numElements;
    std::vector<polynomial> boundary;
public:
    domain(double L, std::vector<double> areacoeff, double YoungsModulus, int numElements, std::vector<polynomial> boundary);
    ~domain();
};

domain::domain(double L, std::vector<double> areacoeff, double YoungsModulus, int numElements, std::vector<polynomial> boundary)
{   
    this->Length = L;
    this->areaFunction = new polynomial(areacoeff, {0.});
    this->YoungsModulus = YoungsModulus;
    this->numElements = numElements;
    this->boundary = boundary;
}

domain::~domain()
{
    delete this->areaFunction;
}



#endif