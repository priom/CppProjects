/**<
@file scrambler.cpp
@auther CHOWDHURY:NRIMONI:A00371596:csc34127
@version 1.0
@date 2014-05-30
@brief
This is a program that scrambles and unscrambles 
lines of text using a simple, recursive method.
*/

/*
Self-assessment:
This program works perfectly fine without any error,
and wrong output. The document is fully formatted too.
*/

#include <iostream>
#include <iomanip>
#include "utilities.h"

using namespace std;
using namespace Scobey;
using Scobey::Menu;

string scrambles(const string txt);
/**<
@return scrambled text
@param const string line of text
@pre string
@post giving scrambled line of text as output
*/

string unscrambles(const string txt);
/**<
@return unscrambled text
@param const string line of text
@pre sting
@post giving unscrambled line of text as output
*/

void myMenu (Menu &menu);
/**<
@return null
@param menu
@pre Menu menu
@post prints out menu
*/

int main()
{
    DisplayOpeningScreen("Chowdhury:Nrimoni:A00371596:CSC34127",
        "This program scrambles and unscrambles lines of text");            
    int num;    
    do
    {
        Menu menu;
        myMenu(menu);        
        num = menu.getChoice();
        if (num == 1)               //quit
        {
            cout << "Goodbye!\n\n";
            Pause();
            exit(1);
        }
        else if(num == 2)           //scramble
        {
            string txt;
            cout << "Enter text to be scrambled below: \n";
            getline(cin, txt);
            while (!txt.empty())
            {
                cout << endl << endl;
                cout << "Scrambled:     \"" << scrambles(txt) << "\"\n\n";
                Pause();
                cout << endl;
                cout << "Enter more text to be scrambled, or "
                        "press enter to return to the menu: \n";
                getline(cin, txt);
            }
        }
        else if (num == 3)          //unscramble
        {       
            string txt;
            cout << "Enter text to be unscrambled below: \n";            
            getline(cin, txt);
            while (!txt.empty())
            {
                cout << endl << endl;
                cout << "Unscrambled:     \"" << unscrambles(txt) << "\"\n\n";
                Pause();
                cout << endl;
                cout << "Enter more text to be unscrambled, or "
                        "press enter to return to the menu: \n";
                getline(cin, txt);
            }
        }        
    } while (num > 0);
}   


void myMenu (Menu &menu)
{
    menu.setTitle("Choose Action:");
    menu.addOption("Quit");
    menu.addOption("Scramble Text");
    menu.addOption("Unscramble Text");
    menu.display();
}


string scrambles(const string txt)          //scrambling
{
    string upp, low;
    if (txt.length() > 1)
    {
        int mid = txt.length() / 2;
        low = scrambles(txt.substr(0, mid));
        upp = scrambles(txt.substr(mid+1));
        return txt[mid] + low + upp;
    }
    else
    {
        return txt;
    }
}


string unscrambles(const string txt)            //unscrambling
{
    string upp, low;
    if (txt.length() > 1)
    {
        int mid = txt.length() / 2;
        low = unscrambles(txt.substr(1, mid));
        upp = unscrambles(txt.substr(mid+1));
        return low + txt[0] + upp;
    }
    else
    {
        return txt;
    }
}

