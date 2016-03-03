/**
@file TestPolynomial.cpp
@auther CHOWDHURY:NRIMONI:A00371596:csc34127
@version 1.0
@date 2014-05-27
@brief
This is a polynomial driver file.

*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>

#include "utilities.h"
#include "Polynomial.h"
using namespace std;

using std::cout;
using Scobey::Pause;

int main()
{    
    Polynomial p;

    //set coefficients
    p.setCoefficient(9, 0);
    p.setCoefficient(7, 2);
    p.setCoefficient(4, 5);
    p.setCoefficient(-1, 3);
    
    //examples
    p.degree();
    p.getCoefficient(3);
    p.getCoefficient(4);
    p.evaluateAt(0);
    p.evaluateAt(1);
    p.print();
    p.setCoefficient(-3, 7);
    
   

}