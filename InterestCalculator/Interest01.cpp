/*
Assignment 1 by NRIMONI CHOWDHURY, A00371596
*/

#include <iostream>
using namespace std;

int main ()
{
    cout << "Chowdhury: Nrimoni: A00371596: CSCI2341" << endl;
    cout << "A01:Interest payments on loans" << endl;
    cout << endl;

    cout << "This program calculates payments on a consumer loan.  You enter" << endl
         << "the amount of the loan, the annual interest rate, and the" << endl
         << "amount of the monthly payment.  It reports month by month on" << endl
         << "how much interest you're charged, and the amount remaining on" << endl
         << "the loan.  At the end it reports how many months it took to" << endl
         << "repay the loan, and how much interest you paid in total." << endl;
    cout << endl << endl;

    cout << "Press enter to continue...";           //first pause
    cin.ignore(100, '\n');
    cout << endl << endl;    

    double loan, annualIntrst, mnthPymnt, mnthlyIntrst;
    int mnth = 1;    

    cout << "Enter amount of the loan: $";
    cin >> loan;
    cin.ignore(100, '\n');

    cout << "Enter the annual interest rate (in %): ";
    cin >> annualIntrst;
    cin.ignore(100, '\n'); 

    cout << "Enter your monthly payment: $";
    cin >> mnthPymnt;
    cin.ignore(100, '\n');
    cout << endl << endl;

    cout << "Press enter to continue...";           //2nd pause
    cin.ignore(100, '\n');
    cout << endl << endl;   

    cout << "Loan Amount:     $" << loan << endl;
    cout << "Monthly Payment: $" << mnthPymnt << endl;
    cout << "Annual Interest:  " << annualIntrst << "%" << endl;

    mnthlyIntrst = annualIntrst / 12;
    cout << "Monthly Interest:  " << mnthlyIntrst << "%" << endl;
    cout << endl;

    cout << "Press enter to continue...";           //3rd pause
    cin.ignore(100, '\n');
    cout << endl << endl;      
    
    double balnce = loan;
    double intrst = balnce * (mnthlyIntrst / 100);
    cout << "Month " << mnth << ", amount owed $" << balnce << ", interest charged $" << intrst << endl;
    double totlIntrst = intrst;
    
    while (balnce > 0)
    { 
        balnce = balnce + balnce * (mnthlyIntrst / 100) - mnthPymnt;
        intrst = balnce * (mnthlyIntrst / 100);        
        mnth++;
        cout << "Month " << mnth << ", amount owed $" << balnce << ", interest charged $" << intrst << endl;        
        totlIntrst += intrst;
        if (balnce < mnthPymnt)
        {
            balnce -= balnce;
        }
    }
    cout << endl;
    cout << "Press enter to continue...";           //4th pause
    cin.ignore(100, '\n');
    cout << endl;
    cout << endl;

    cout << "Load paid off in " << mnth << " months." << endl;
    cout << "Total interest paid was $" << totlIntrst << "." << endl;
    cout << endl;

    cout << "Press enter to finish...";           //last pause
    cin.ignore(100, '\n');
    cout << endl;
    cout << endl;
}