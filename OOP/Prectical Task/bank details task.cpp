
#include <iostream>
using namespace std;

class Bank
{
private:
    int balance;

public:
    void getData()
    {
        cout << "Enter initial Balance: ";
        cin >> balance;
    }

    void deposit()
    {
        int amount;
        cout << "\nEnter Deposit Amount: ";
        cin >> amount;

        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully";
        }
    }

    void withdraw()
    {
        int amount;
        cout << "\n\nEnter withdrawal amount: ";
        cin >> amount;

        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully";
        }
    }

    void display()
    {
        cout << "\n\nFinal Balance: " << balance;
    }
};

int main()
{
    Bank b;

    b.getData();
    b.deposit();
    b.withdraw();
    b.display();

    return 0;
}

