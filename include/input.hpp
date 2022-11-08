#ifndef TAKE_INPUT
#define TAKE_INPUT
#define INPUT_ERROR -1

#include <include/polynomial.hpp>
#include <iostream>
#include <sstream>

class input
{
private:
    int n_dims;
    int N;
    double L;
    double Ao;
    double Y;
    double h;
    double P;
    polynomial *areaFunction = NULL;
public:
    input();
    ~input();
    
    double getL();
    double getN();
    double getY();
    double get();
    double setVar();

    double getVar();
    double setVar();

    double getVar();
    double setVar();

    int takeInput();
};

int input::takeInput(){
    
}

input::input()
{
}

input::~input()
{   
    if (areaFunction != NULL){
        delete this->areaFunction;
    }
}



#endif