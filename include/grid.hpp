#include <vector>
#include <domain.hpp>

/*
 TODO: 1.   2D Matrix as Coordinate Sys
       2.   Nodes
       3.   set Domain
       4.   setters and getters
*/

class grid
{
private:
    domain *d = NULL;
    int ndims;
public:
    grid(int ndims);
    ~grid();
};

grid::grid(int ndims)
{
    this->ndims = ndims;
}

grid::~grid()
{   
    if (d!=NULL)
    {
        delete d;
    }
    
}
