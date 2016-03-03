/**
@file Date.h
@author Chowdhury:Nrimoni:A00371596:csc34127
@version 1.0
@date 2014-05-22
@brief
This is c++ header file, Date.h which consists of a year,a 
month and a day which is represented in integers.
*/

/*
Author self-assessment statement:
This class specifies the members to implement a date.
And by the way, note that this is a C++ but non-doxygen comment,
so it will not appear in the HTML displays produced by doxygen.
*/

//#ifndef DATE_H
//#define DATE_H

#include <iostream>
#include <vector>
using namespace std;
typedef int ItemType;

class Date
{
public:

    bool equals(const Date& other) const;

	bool before(const Date& other) const;

      bool set(int y, int m, int d);
      /**<
        @return bool true or false
        @param 
        @post y = year, m = month, d = date 
      */

      void print() const;
      /**<
        @return void
        @param no parameters
        @post 
      */

      int  getYear() const;
      /**<
        @return int myYear
        @param no parameters
        @post myYear
      */

      int  getMonth() const;
      /**<
        @return int myMonth
        @param no parameters
        @post myMonth
      */

      int  getDay() const;
      /**<
        @return int myDay
        @param no parameters
        @post myDay
      */

      
      static bool isLeapYear (int y);
      /**<
        @return int myDay
        @param int y
        @post myYear
      */

      static int daysInMonth (int m, int y);
      /**<
        @return int myDay
        @param int m, int y
        @post myMonth, myYear
      */

      Date(int y = 2014, int m = 01, int d = 01);   

private:
      int myYear;
      int myMonth;
      int myDay;

};
