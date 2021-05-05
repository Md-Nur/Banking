//Program Name: ATM calculator

/*	====	included header file	====	*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <list>
#include <map>
//user define including header files
#include "account.h"
#include "account.cpp"
/*	====	Stucture, Uninons, Predefine Marcos & namespaces	====	*/
using namespace std;

/*	====	Declaration of classes & Functions	====	*/

/*	====	Classes	====	*/

/*	====	Functions	====	*/

//Make a display Menu Function
void displayMenu()
{
    cout << "\n\n\t\t\tMENU\n\n"
         << "1. Display the account balance\n"
         << "2. Display the number of transactions\n"
         << "3. Display the interest earned for this period\n"
         << "4. Make a deposite\n"
         << "5. Make a withdrawl\n"
         << "6. Add interest for this period\n"
         << "7. Exit\n\n";
}

//Make a method fo choice
int getChoice(int max)
{
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    while (1 > choice || choice > max)
    {
        cout << "Your choice must be between 1 and " << max << endl
             << "Enter your choice: ";
        cin >> choice;
    }
    return choice;
}

// A deposite functioin
void makeDeposite(account &ac)
{
    double taka;
    cout << "Enter the amount of deposite: ";
    cin >> taka;
    cin.ignore();
    ac.deposite(taka);
}

// A withdrawl functioin
void makeWithdraw(account &ac)
{
    double taka;
    cout << "Enter the amount of withdraw: ";
    cin >> taka;
    cin.ignore();
    if (!ac.withdraw(taka))
    {
        cout << "ERROR! the ammount is invalid! or too large" << endl
             << endl;
    }
}
/*	+-+-+-+-+-+-+-+-+-+-+
        Main Function
    +-+-+-+-+-+-+-+-+-+-+	*/
int main()
{
    const int MAX_CHOICE = 7;
    account savings;
    int choice;
    cout << fixed << showpoint << setprecision(2) << endl;
    do
    {
        displayMenu();
        choice = getChoice(MAX_CHOICE);
        switch (choice)
        {
        case 1:
            cout << "Your balance is : " << savings.getPrincipal() << " taka" << endl;
            break;
        case 2:
            cout << "You have : " << savings.getTransactions() << "transaction" << endl;
            break;
        case 3:
            cout << "Your interest is : " << savings.getInterest() << " taka" << endl;
            break;
        case 4:
            makeDeposite(savings);
            break;
        case 5:
            makeWithdraw(savings);
            break;
        case 6:
            cout << "Your total interest is : ";
            savings.calculateInterest();
            break;

        default:
            break;
        }
    } while (choice != 7);

    return 0;
}