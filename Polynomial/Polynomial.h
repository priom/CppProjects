/**
@file Polynomial.h
@author Chowdhury:Nrimoni:A00371596:csc34127
@version 1.0
@date 2014-05-24
@brief
This is a polynomial header file which consists of all important
functions and constants.
*/

/*
Author self-assessment statement:
This class specifies the members to implement a date.
And by the way, note that this is a C++ but non-doxygen comment,
so it will not appear in the HTML displays produced by doxygen.
*/

#include <iostream>
#include <vector>
using namespace std;
typedef int ItemType;

class Polynomial
{
public:
    int degree();
    /**<
    @return int
    @param 
    @post 
    */

    double getCoefficient(int power) const;
    /**<
    @return void
    @param 
    @post 
    */

    double evaluateAt (double x) const;
    /**<
    @return double
    @param 
    @post 
    */

    void print() const;
    /**<
    @return int myMonth
    @param no parameters
    @post myMonth
    */

    double setCoefficient(double newCoefficient, int power);
    /**<
    @return int myDay
    @param no parameters
    @post myDay
    */

private:
    int pow;        //power
    int deg;        //degree
    int newCoef;
 
};
