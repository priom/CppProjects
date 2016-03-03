/**<
@file Polynomial.cpp
@auther CHOWDHURY:NRIMONI:A00371596:csc34127
@version 1.0
@date 2014-05-27
@brief
This is a program for calculating polynomial
*/

/*
Self Assessment
The program builds perfectly but after I run the program
it stops with a error which says vector out of range.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>
#include "Polynomial.h"
using namespace std;
vector <double> v;
int Polynomial::degree()
{    
    return deg;                  
}

double Polynomial::getCoefficient(int power) const
{
    return v[power];
}

double Polynomial::evaluateAt (double x) const
{    
    for (auto x = v.rbegin(); x != v.rend(); ++x)
    {
        cout << *x << " ";
    }
    return x;
}
     
void Polynomial::print() const
{
    for (auto x = v.rbegin(); x != v.rend(); ++x)
    cout << "\t" << *x << " "; 

}
    
double Polynomial::setCoefficient(double newCoefficient, int power)
{
    if (newCoef >= pow)
	{
		v[power] = newCoef;
        return v[power];
	}
	else
	{
		v.resize(power);
		v.push_back(newCoef);
	}
}