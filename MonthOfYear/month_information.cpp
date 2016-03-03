/**<
@file month_information.cpp
@auther CHOWDHURY:NRIMONI:A00371596:csc34127
@version 1.0
@date 2014-06-04
@brief
This is a simple program that gives information about the 
months of the year (in our western (Gregorian) calendar).
*/

/*
Self-assessment:
This program works perfectly fine without any error,
and wrong output. The document is fully formatted too.
*/

#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include "utilities.h"

using namespace std;
using namespace Scobey;


int MonthNameToNumber(string name);
/**<
@return number of month
@param string name of the month
@pre string
@post giving output the number of the month
      converting it from string to int
*/

int daysInMonth(int month, bool isLeapYear = false);
/**<
@return number of days in a month
@param int mnumber of month, and boolean leap year
@pre int, bool
@post giving output the number of days in a month
      checking if its a leap year or not.
*/


int main()
{
    DisplayOpeningScreen("Chowdhury:Nrimoni:A00371596:CSC34127",
        "This program scrambles and unscrambles lines of text");
    string name;       
    cout << endl;
            cout << "Enter the name of a month: ";
            getline(cin, name);
            cout << endl;

    while (!name.empty())
    {
        try
        {
            cout << name << " is month #" << MonthNameToNumber(name)
                 << " in our calendar.\n";

            if (MonthNameToNumber(name) == 2)
            {
                cout << "It has "
                     << daysInMonth(MonthNameToNumber(name), false)
                     << " days in a regular year, and  " 
                     << daysInMonth(MonthNameToNumber(name), true) 
                     << " days in a leap year.\n\n";
            }

            else
            {
                cout << "It has " 
                     << daysInMonth(MonthNameToNumber(name), false)
                     << " days.\n\n";
            }
            cout << "Enter the name of a month, or press enter to quit: ";                
        }
            
        catch(const invalid_argument e)
        {
            cout << e.what() << "'" << name << "' isn't the name of a month"
                 << endl << endl;
            cout << "Enter the name of a month, or press enter to quit: ";            
        }        
        getline(cin, name);        
    }
    Pause();
}


int MonthNameToNumber(string name)
{    
    if (name == "January")
    {
        return 1;
    }

    else if (name == "February")
    {
        return 2;
    }

    else if (name == "March")
    {
        return 3;
    }

    else if (name == "April")
    {
        return 4;
    }

    else if (name == "May")
    {
        return 5;
    }

    else if (name == "June")
    {
        return 6;
    }

    else if (name == "July")
    {
        return 7;
    }

    else if (name == "August")
    {
        return 8;
    }

    else if (name == "September")
    {
        return 9;
    }

    else if (name == "October")
    {
        return 10;
    }

    else if (name == "November")
    {
        return 11;
    }

    else if (name == "December")
    {
        return 12;
    }

    else
    {
        throw invalid_argument ("");
    }
}


int daysInMonth(int month, bool isLeapYear)
{
    if ((month == 1) || (month == 3) || (month == 5) || (month == 7) 
        || (month == 8) || (month == 10) || (month == 12))
    {
        return 31;
    }

    else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))         
    {
        return 30;
    }

    else
    {
        if (isLeapYear == true)
        {
            return 29;
        }
            return 28;        
    }    
}
