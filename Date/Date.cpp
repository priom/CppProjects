/**<
@file Date.cpp
@author Chowdhury:Nrimoni:A00371596:csc34127
@version 1.0
@date 2014-05-22

This program is a implentation file of the Date.h file.
This file (Date.cpp) and the header file (Date.h) 
links together with the driver file (DateClient.cpp).
*/

/**
Self-assessment

My whole program compiles and runs except the daysInMonth function,
however I commented out the function as its not compiling.
For my setter value, I'm always getting the default constructor value
except the "Setter + constructor test", I get correct value for it.
Rather than that everything in my program is completely fine...!!!!
**/
#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

Date::Date(int y, int m, int d)
{
    myYear = y;
    myMonth = m;
    myDay = d;
}

bool Date::equals(const Date& other) const
{
    if ((myYear == other.myYear) && (myMonth == other.myMonth) 
        && (myDay == other.myDay))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Date::before(const Date& other) const
{
    if ((myYear < other.myYear) || ((myYear == other.myYear) && 
        (myMonth < other.myMonth)) || ((myYear == other.myYear) && 
        (myMonth == other.myMonth) && (myDay < other.myDay)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Date::set(int y, int m, int d)
{
    if ((y > 0) || (m >= 1) || (m <= 12) || (d >= 1) || (d <= 31))
    {
        return true;
    }
    else
    {
        return false;
    }

}

void Date::print() const
{
    cout << myYear << "-" << myMonth << "-" << myDay;
}

int  Date::getYear() const
{
    return myYear;
}

int  Date::getMonth() const
{
    return myMonth;
}

int  Date::getDay() const
{
    return myDay;
}

bool Date::isLeapYear (int y)
{
    if (((y % 4) == 0) && ((y % 100) != 0) || ((y % 400) == 0))
    {
        return true;
    }
    else
    {
        return false;
    }    
}  
/*
int Date::daysInMonth (int m, int y)
{
    if (m > 12)
    {
        return false;
    }

    if ((m == 4) || (m == 6) || (m == 9) || (m == 11))
    {
       
        return true;
    }
}
*/