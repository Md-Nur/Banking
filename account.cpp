#include "account.h"

bool account::withdraw(double amount)
{
    if (principal < amount)
    {
        return false;
    }
    else
    {
        principal -= amount;
        transactions++;
        return true;
    }
}
