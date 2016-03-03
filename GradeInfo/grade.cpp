/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/**
*
* @author PrioM
*/

#include <iostream>
#include <string>

using namespace std;

int main()
   {
        // TODO code application logic here
        cout << "Welcome to SMU GPA calculator: \n";
        cout << "Please enter your name: ";
        string name;
        cin >> name;
        cout << "Please enter your mark: ";       
        int mark;
        cin >> mark;

        cout << "Press enter to continue...";
        cin.ignore(100, '\n');
        cout << endl << endl;

        string grade;
        double gpa = 0.0;

        if ((mark < 0) || (mark > 100))
        {
            cout << "Sorry, mark must be from 0 to 100";
            return 0;
        }
        else if ((mark >= 90) && (mark <= 100))
        {
            grade = "A+";
            gpa = 4.3;
        }
        else if ((mark >= 85) && (mark <= 89))
        {
            grade = "A";
            gpa = 4.0;
        }
        else if ((mark >= 80) && (mark <= 84))
        {
            grade = "A-";
            gpa = 3.7;
        }
        else if ((mark >= 77) && (mark <= 79))
        {
            grade = "B+";
            gpa = 3.3;
        }
        else if ((mark >= 73) && (mark <= 76))
        {
            grade = "B";
            gpa = 3.0;
        }
        else if ((mark >= 70) && (mark <= 72))
        {
            grade = "B-";
            gpa = 2.7;
        }
        else if ((mark >= 67) && (mark <= 69))
        {
            grade = "C+";
            gpa = 2.3;
        }
        else if ((mark >= 63) && (mark <= 66))
        {
            grade = "C";
            gpa = 2.0;
        }
        else if ((mark >= 60) && (mark <= 62))
        {
            grade = "C-";
            gpa = 1.7;
        }
        else if ((mark >= 50) && (mark <= 59))
        {
            grade = "D";
            gpa = 1.0;
        }
        else
        {
            grade = "F";
            gpa = 0.0;
        }
        
       cout << "Your name is: " << name << endl;
       cout << "Your mark is: " << mark << endl;
       cout << "Your grade is: " << grade << endl;
       cout << "Your GPA is: " << gpa << endl;

       cout << "Press enter to continue...";
       cin.ignore(100, '\n');
       cout << endl << endl;
    
}
