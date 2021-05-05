class account
{
private:
    double principal, interest, rate;
    int transactions;

public:
    // Constructor
    account(double p = 0, double r = 0.07)
    {
        principal = p;
        rate = r;
        interest = 0;
        transactions = 0;
    };
    // ~account();

    // make a function for deposite
    void deposite(double amount)
    {
        principal += amount;
        transactions++;
    }

    // make a method for withdraw
    bool withdraw(double amount); // this function will defined in main file

    void calculateInterest()
    {
        interest = principal + rate;
        principal += interest;
    }

    //Make a funtion for return trunscition in main
    int getPrincipal()
    {
        return principal;
    }
    int getTransactions()
    {
        return transactions;
    }
    int getInterest()
    {
        return transactions;
    }
};