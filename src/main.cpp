#include <iostream>
#include <include/polynomial.hpp>

int main(int argc, char const *argv[])
{   
    polynomial *p = new polynomial({1,1}, {1});

    std::cout << p->getIntegral(0,15, 100000) << "\n";
    std::cout << p->twoPointGuassQuadratureIntegral(15, 0) << "\n";
    
    return 0;
}
