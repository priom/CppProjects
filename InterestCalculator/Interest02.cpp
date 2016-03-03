/*
    Assignment 2 by NRIMONI CHOWDHURY, A00371596
*/

#include <iostream>
#include <iomanip>
#include "utilities.h"
using namespace std;
using namespace Scobey;

int main ()
{
    cout << "Chowdhury: Nrimoni: A00371596: CSCI2341" << endl
         << "A01:Interest payments on loans" << endl << endl;         

    cout << "This program calculates payments on a consumer loan. You enter\n"
         << "the amount of the loan, the annual interest rate, and the\n"
         << "amount of the monthly payment.  It reports month by month on\n"
         << "how much interest you're charged, and the amount remaining on\n"
         << "the loan.  At the end it reports how many months it took to\n"
         << "repay the loan, and how much interest you paid in total.\n"
         << endl << endl;

    Pause();                       //first pause
    cout << endl;

    double loan, annualIntrst, mnthPymnt, mnthlyIntrst;
    int mnth = 1;    

    ReadDouble ("Enter amount of the loan: $", loan);
    ReadDouble ("Enter the annual interest rate (in %): ", annualIntrst);
    ReadDouble ("Enter your monthly payment: $", mnthPymnt);   
    cout << endl << endl;

    Pause();                        //2nd pause
    cout << endl;

    mnthlyIntrst = annualIntrst / 12;

    cout << "Loan Amount:      $" << fixed << setprecision(2) << right 
         << setw(10) << loan << endl
         << "Monthly Payment:  $" << fixed << setprecision(2) << right
         << setw(10) << mnthPymnt << endl
         << "Annual Interest:   " << fixed << setprecision(2) << right
         << setw(10) << annualIntrst << "%" << endl   
         << "Monthly Interest:  " << fixed << setprecision(2) << right
         << setw(10) << mnthlyIntrst << "%" << endl << endl;
   

    double balnce = loan;
    double intrst = balnce * (mnthlyIntrst / 100);
    double endAmt = balnce + intrst - mnthPymnt;
    cout << right << "Month" << setw(15) << right << "Start Amount" 
         << setw(15) << right <<  "Interest" << setw(15) << right
         << "Payment" << setw(15) << right << "End Amount" << endl;

    cout << fixed << right << setw(5) << mnth << setprecision(2) << setw(15) 
         << balnce << setw(15) << intrst << setw(15) << mnthPymnt << setw(15)
         << endAmt << endl;
     
    double totlIntrst = intrst;

    while (balnce > 0)
    { 
        balnce = balnce + balnce * (mnthlyIntrst / 100) - mnthPymnt;
        intrst = balnce * (mnthlyIntrst / 100);
        endAmt = balnce + intrst - mnthPymnt;
        mnth++;        
        cout << right << setw(5) << mnth << setprecision(2) << setw(15) 
             << balnce << setw(15) << intrst << setw(15) << mnthPymnt 
             << setw(15) << endAmt << endl;
        totlIntrst += intrst;
        
        if (mnth % 12 == 0)
        {
            cout << endl;
            Pause();
            cout << endl;
            cout << "Loan Amount:     $ " << fixed << setprecision(2) << right
                 << setw(10) << loan << endl
                 << "Monthly Payment: $ " << fixed << setprecision(2) << right
                 << setw(10) << mnthPymnt << endl
                 << "Annual Interest:   " << fixed << setprecision(2) << right
                 << setw(10) << annualIntrst << "%" << endl 
                 << "Monthly Interest:  " << fixed << setprecision(2) << right
                 << setw(10) << mnthlyIntrst << "%" << endl << endl;
        }
        if (balnce < mnthPymnt)
        {            
            balnce -= balnce; // balance = balance - balance
        }
    } 
    cout << endl;
    Pause();                        //3rd pause

    cout << "Load paid off in " << mnth << " months." << endl
         << "Total interest paid was $" << fixed << setprecision(2) 
         << totlIntrst << "." << endl << endl;        

    Pause();                        //last pause
}