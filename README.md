# Finite element analysis of a rod

## Stuation:

Consider a rod with cross sectional area A(x) and length L. The rod is subjected to a constant load P = 5000
N at x = 0. At x = L the rod is fixed. The length of the rod is 0.5 m and the Young’s modulus of the
material of the rod is 70 GPa. 

## Problems :
    1. The cross section of the rod is uniform with area A(x) = A0 = 12.5 ×10−4 m2.

    2. The cross sectional area is given by the formula A(x) = A0(1 + x/L). Here the cross section is not uniform, it increases linearly with x.

    3. Finite Element code to find the displacement at the nodal points 

# Solution:

Finite element method is used to find the elongation of rod. 


For detailed solution read report.pdf

# Installing dependencies and building:

***In linux environment***

Clone the repository using git clone cd to the project root


`$ make eigen `in project root to install Eigen in project root.

`$ make ` in project root to build the executable

# Usage


1.  `$ bin/solution 0 ` for constant area solution.

2.  `$ bin/solution 1 ` for variable area solution.

3.  `$ bin/solution   ` to define the constants like N and area manually.

This prints X, U(i) (which is elongation at X) in file.txt