/* Do Programming Project 2 on page 611. You may watch the video note for
 * Programming Project 1 on page 611 to get some idea. Then try to finish
 * independently by complete this sample file.
 *
 * Author:Katelyn Junker
 * Version:02/06/2022
 */

#include <iostream>
using namespace std;

class CDAccount
{
public:
    CDAccount();
    CDAccount(double new_balance, double new_interest_rate, int new_term);
    double get_initial_balance() const;
    double get_balance_at_maturity() const;
    double get_interest_rate() const;
    int get_term() const;
    void input(istream& in);
    void output(ostream& out);

private:
    int dollar;
    int cent;
    double interest_rate;
    int term; // months until maturity
};

int main()
{
    CDAccount newAccount;
    newAccount.input(cin); // gather all inputs
    newAccount.output(cout);// print out all information + balance at maturity
    return 0;
}

// Implement the class definition here. Notice that the interfaces are the
// same as in Programming Project 1. However, the implementation will be
// different since the private information balance is stored differently
// for example, the input function will only read the balance, itnerest rate
// and term from the user. So it should be modified as following
void CDAccount::input(istream& in)
{
    double balance;
    cout << "Please enter current balance." << endl;
    cin >> balance; // get initial balance from user
    // convert balance to dollars and cents since this is how balance stored
    dollar = (int)balance; // dollar is the interger part of balace
    cent = (int)((balance - dollar) * 100); // cent is the fraction part * 100
    cout << "Please enter the interest rate." << endl;
    cin >> interest_rate; // get interest rate from user
    cout << "Please enter the term length." << endl;
    cin >> term; // get term from user
    CDAccount newAccount(balance, interest_rate, term);
}
CDAccount::CDAccount()
{
    // Default constructor
    // Set default values

    dollar = 0;
    cent = 0;
    interest_rate = 0;
    term = 0;
}
CDAccount :: CDAccount(double new_balance, double new_interest_rate, int new_term)
{
    new_balance = dollar + (0.01 + cent);
    new_interest_rate = interest_rate;
    new_term = term;
}
double CDAccount :: get_initial_balance() const
{
    return (dollar + (cent * 0.01));
}
double CDAccount :: get_balance_at_maturity() const
{
    double matureBal;
    matureBal = (dollar + (cent * 0.01));
    return (matureBal + ((matureBal * interest_rate) * term)); // convert interest rate to a decimal
}
double CDAccount :: get_interest_rate() const
{
    return interest_rate;
}
int CDAccount :: get_term() const
{
    return term;
}
void CDAccount :: output(ostream& out) // print out all of the variables gathered and then the balance at maturity
{
    out.setf(ios::fixed);       // Set output to a fixed number of decimals
    out.precision(2);           // Set output precision to 2 decimals
    cout << "The balance entered was " << get_initial_balance() << endl;
    cout << "The interest rate entered was " <<get_interest_rate() << endl;
    cout << "The term length entered was " <<get_term() << endl;
    if ((dollar <= 0) || (interest_rate <= 0) || (term <= 0)) // check to ensure all variables entered are valid
    {
        cout << "Invalid entry detected." << endl;
        cout << "Please ensure all variables are above 0." << endl;
    }
    else
    {
        cout << "The new balance is " << get_balance_at_maturity() << endl;
    }
}