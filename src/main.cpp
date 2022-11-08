#include <iostream>
#include <include/polynomial.hpp>
#include <Eigen/Dense>
#include <vector>
#include <fstream>
#include <include/solution.hpp>

int main(int argc, char const *argv[])
{   
    
   if (atoi(argv[1]) == 0)
   {
    sol::constantsolution(16);
   } else if (atoi(argv[1]) == 1)
   {
    sol::variableSolution(16);
   } else
   {
     sol::manualSolution();
   }
   
   
    return 0;
}
