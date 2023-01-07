#include <iostream>
#include <include/polynomial.hpp>
#include <Eigen/Dense>
#include <vector>
#include <fstream>
#include <include/solution.hpp>

int main(int argc, char const *argv[])
{  

   if (argc != 2 ){

    std::cout << "Useage: " << "\n";
    std::cout << " `$ bin/solution 0 ` for constant area solution   " << "\n";
    std::cout << " `$ bin/solution 1 ` for variable area solution   " << "\n";

    std::cout << "\n" << "---------------------------" << "\n";
    std::cout << "Define the problem manually: " << std::endl;
    sol::manualSolution();
    return 0;
   } 
    
   if (atoi(argv[1]) == 0)
   {
    sol::constantsolution(16);
   } else if (atoi(argv[1]) == 1)
   {
    sol::variableSolution(16);
   }

    return 0;
}
