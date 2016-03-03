///////////////////////////////////////////////////////////////////////
// identification section
///////////////////////////////////////////////////////////////////////
/**
 *
 */

///////////////////////////////////////////////////////////////////////
// self-assessment section
///////////////////////////////////////////////////////////////////////
/*

*/

///////////////////////////////////////////////////////////////////////
// includes and usings section
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "utilities.h"

using namespace std;
using namespace Scobey;
typedef int ItemType;

///////////////////////////////////////////////////////////////////////
// constants section
///////////////////////////////////////////////////////////////////////
const double TOONIE  = 2.00;
const double LOONIE  = 1.00;
const double QUARTER = 0.25;
const double DIME    = 0.10;
const double NICKEL  = 0.05;


///////////////////////////////////////////////////////////////////////
// function prototypes section
///////////////////////////////////////////////////////////////////////

bool GetAmount
(
    double& amount     // out
);
/**<
 *  Gets the amount in dollars and cents (less than $5.00) from the user.
 *  @return <tt>true</tt> if the amount entered is positive; 
            <tt>false<tt> otherwise.
 *  @param  amount  the variable the amount entered is to be returned in.
 *  @pre    cin is not in a fail state.
 *  @post
 *   -# amount is a multiple of 0.01 (1 cent)
 *   -# cin is empty
 *   -# amount has been set to a value between 0.01 and 4.99 
          and <tt>true</tt> is returned
 *      OR amount is a value &lt;= 0.00 and <tt>false</tt> has been returned
 */

double roundTo
(
    double amount,  // in
    double factor   // in
);
/**<
 *  Returns amount rounded off to the nearest multiple of factor.
 *  @return amount rounded off to the nearest multiple of factor.
 *  @param  amount  the variable the amount entered is to be returned in.
 *  @pre    factor != 0.0
 *  @post   no side effects
 */

void ShowChange
(
    double amount   // in
);
/**<
/**<
 *  Prints a table showing the amount of coins required 
 *  to make the given amount in change.
 *  @param  amount  the amount of change to be made.
 *  @pre    none
 *  @post   a table has been printed as follows:
 *   - a title showing the amount to make change for (in dollars)
 *   - a line each for toonies, loonies, quarters, dimes, and nickels,
 *     showing the face value of the coin (in dollars),
 *     the number of that coin required,
 *     and the total value of those coins, and
 *   - a message reminding the user that change amounts are rounded 
 *     to the nearest 5 cents.
 */

void GetAndShowCoins
(
    double coinValue,   // in
    int&   coinCount,   // out
    double& amount      // in-out
);
/**<
 *  Calculates how many coins of the given value are required for change,
 *  and prints one line of a table showing the amount of coins required
 *  to make the given amount in change.
 *  @param  coinValue  the value of the coin to be used in making change.
 *  @param  coinCoint  a variable to hold the number of coins required.
 *  @param  amount     a variable tracking the amount of change required.
 *  @pre
 *   -# coinValue > 0.00
 *   -# amount >= 0.00
 *  @post
 *   -# coinCount has been set to the number of coinValue coins required 
 *      to make change for amount.
 *   -# amount has been reduced by the value of those coins.
 *   -# a formatted line has been printed
 *      showing the face value of the coin (in dollars),
 *      the number of that coin required,
 *      and the total value of those coins.
 */

void GetCoins
(
    double coinValue,   // in
    int&   coinCount,   // out
    double& amount      // in-out
);
/**<
 *  Calculates how many coins of the given value are required for change.
 *  @param  coinValue  the value of the coin to be used in making change
 *  @param  coinCoint  a variable to hold the number of coins required
 *  @param  amount     a variable tracking the amount of change required
 *  @pre
 *   -# coinValue > 0.00
 *   -# amount >= 0.00
 *  @post
 *   -# coinCount has been set to the number of coinValue coins 
 *      required to make change for amount
 *   -# amount has been reduced by the value of those coins
 */

void ShowCoins
(
    double coinValue,   // in
    int    coinCount    // in
);
/**<
 *  Prints one line of a table showing the amount of coins required
 *  to make the given amount in change
 *  @param  coinValue  the value of the coin used in making change
 *  @param  coinCoint  the number of coins used
 *  @pre
 *   -# coinValue > 0.00
 *  @post   a formatted line has been printed showing
 *      - the face value of the coin (in dollars),
 *      - the number of that coin required,
 *      - and the total value of those coins.
 */


///////////////////////////////////////////////////////////////////////
// main function
///////////////////////////////////////////////////////////////////////

int main()
{
        for (int i = 0; i < 11; i++)
        {
            cout << endl;
        }

        cout << "Chowdhury: Nrimoni: A00371596: CSC34127\n"
             << "A03: Coin Change Machine,\n"
             << "The main driver of this executable was built on "
             << "May 20 2014 at 22:22:22";

        for (int i = 0; i < 11; i++)
        {
            cout << endl;
        }
        Pause();
        cout << endl << endl;

        cout << "This program reports how much of each coin you need in "
             << "order to make up a \ngiven amount of change. The amount "
             << "must be between $0.01 and $4.99 inclusive.\n\n";
        Pause();

}

///////////////////////////////////////////////////////////////////////
// function definitions section
///////////////////////////////////////////////////////////////////////

