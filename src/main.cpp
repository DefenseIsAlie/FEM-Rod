#include <iostream>
#include <include/polynomial.hpp>

int main(int argc, char const *argv[])
{   
    polynomial *p = new polynomial({1,1}, {1});

    std::cout << p->getPx(.5) << "\n";
    
    return 0;
}
