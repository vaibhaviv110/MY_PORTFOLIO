#include <iostream>
#include <string>
using namespace std;


// Base Class
class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;


protected:
    void setBalance(double amount)
    {
        balance = amount;
    }


public:
    BankAccount(int no, string name, double bal)
    {
        accountNumber = no;
        accountHolderName = name;
        balance = bal;
    }


    virtual ~BankAccount() {}


    int getAccountNumber()
    {
        return accountNumber;
    }


    double getBalance()
    {
        return balance;
    }


    void deposit(double amount)
    {
        if(amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully!\n";
        }
        else
        {
            cout << "Invalid amount!\n";
        }
    }


    virtual void withdraw(double amount)
    {
        if(amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully!\n";
        }
        else
        {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }


    virtual double calculateInterest()
    {
        return 0;
    }


    virtual void displayAccountInfo()
    {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nAccount Holder: " << accountHolderName;
        cout << "\nBalance: Rs. " << balance << endl;
    }
};


// Derived Class 1: Savings Account
class SavingsAccount : public BankAccount
{
private:
    double interestRate;


public:
    SavingsAccount(int no, string name, double bal, double rate)
        : BankAccount(no, name, bal)
    {
        interestRate = rate;
    }


    double calculateInterest()
    {
        return getBalance() * interestRate / 100;
    }


    void displayAccountInfo()
    {
        cout << "\n--- Savings Account ---";
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};


// Derived Class 2: Checking Account
class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;


public:
    CheckingAccount(int no, string name, double bal, double limit)
        : BankAccount(no, name, bal)
    {
        overdraftLimit = limit;
    }


    void withdraw(double amount)
    {
        if(amount > 0 && amount <= getBalance() + overdraftLimit)
        {
            setBalance(getBalance() - amount);
            cout << "Amount withdrawn successfully!\n";
        }
        else
        {
            cout << "Overdraft limit exceeded or invalid amount!\n";
        }
    }


    bool checkOverdraft()
    {
        return getBalance() < 0;
    }


    void displayAccountInfo()
    {
        cout << "\n--- Checking Account ---";
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit: Rs. " << overdraftLimit << endl;
    }
};


// Derived Class 3: Fixed Deposit Account
class FixedDepositAccount : public BankAccount
{
private:
    int term;


public:
    FixedDepositAccount(int no, string name, double bal, int months)
        : BankAccount(no, name, bal)
    {
        term = months;
    }


    double calculateInterest()
    {
        // Assumed fixed interest rate: 6% per year
        return getBalance() * 6 * term / (100 * 12);
    }


    void displayAccountInfo()
    {
        cout << "\n--- Fixed Deposit Account ---";
        BankAccount::displayAccountInfo();
        cout << "Term: " << term << " months\n";
        cout << "Assumed Interest Rate: 6% per year\n";
    }
};


// Main Function
int main()
{
    BankAccount *accounts[100];
    int count = 0;
    int choice, no, months;
    double balance, amount, rate, limit;
    string name;


    do
    {
        cout << "\n===== BANKING SYSTEM =====";
        cout << "\n1. Create Savings Account";
        cout << "\n2. Create Checking Account";
        cout << "\n3. Create Fixed Deposit Account";
        cout << "\n4. Deposit Amount";
        cout << "\n5. Withdraw Amount";
        cout << "\n6. Display All Accounts";
        cout << "\n7. Calculate Interest";
        cout << "\n8. Check Overdraft";
        cout << "\n9. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;


        switch(choice)
        {
            case 1:
                if(count >= 100)
                {
                    cout << "Account list is full!\n";
                    break;
                }


                cout << "Enter Account Number: ";
                cin >> no;
                cout << "Enter Account Holder Name : ";
                cin >> name;
                cout << "Enter Initial Balance: ";
                cin >> balance;
                cout << "Enter Interest Rate (%): ";
                cin >> rate;


                if(balance < 0 || rate < 0)
                {
                    cout << "Invalid balance or interest rate!\n";
                    break;
                }


                accounts[count++] =
                    new SavingsAccount(no, name, balance, rate);
                cout << "Savings Account created successfully!\n";
                break;


            case 2:
                if(count >= 100)
                {
                    cout << "Account list is full!\n";
                    break;
                }


                cout << "Enter Account Number: ";
                cin >> no;
                cout << "Enter Account Holder Name (one word): ";
                cin >> name;
                cout << "Enter Initial Balance: ";
                cin >> balance;
                cout << "Enter Overdraft Limit: ";
                cin >> limit;


                if(balance < 0 || limit < 0)
                {
                    cout << "Invalid balance or overdraft limit!\n";
                    break;
                }


                accounts[count++] =
                    new CheckingAccount(no, name, balance, limit);
                cout << "Checking Account created successfully!\n";
                break;


            case 3:
                if(count >= 100)
                {
                    cout << "Account list is full!\n";
                    break;
                }


                cout << "Enter Account Number: ";
                cin >> no;
                cout << "Enter Account Holder Name (one word): ";
                cin >> name;
                cout << "Enter Initial Balance: ";
                cin >> balance;
                cout << "Enter Term in Months: ";
                cin >> months;


                if(balance < 0 || months <= 0)
                {
                    cout << "Invalid balance or term!\n";
                    break;
                }


                accounts[count++] =
                    new FixedDepositAccount(no, name, balance, months);
                cout << "Fixed Deposit Account created successfully!\n";
                break;


            case 4:
                cout << "Enter Account Number: ";
                cin >> no;


                for(int i = 0; i < count; i++)
                {
                    if(accounts[i]->getAccountNumber() == no)
                    {
                        cout << "Enter Deposit Amount: ";
                        cin >> amount;
                        accounts[i]->deposit(amount);
                        break;
                    }


                    if(i == count - 1)
                        cout << "Account not found!\n";
                }
                if(count == 0)
                    cout << "No accounts available!\n";
                break;


            case 5:
                cout << "Enter Account Number: ";
                cin >> no;


                for(int i = 0; i < count; i++)
                {
                    if(accounts[i]->getAccountNumber() == no)
                    {
                        cout << "Enter Withdrawal Amount: ";
                        cin >> amount;
                        accounts[i]->withdraw(amount);
                        break;
                    }


                    if(i == count - 1)
                        cout << "Account not found!\n";
                }
                if(count == 0)
                    cout << "No accounts available!\n";
                break;


            case 6:
                if(count == 0)
                    cout << "No accounts available!\n";


                for(int i = 0; i < count; i++)
                {
                    accounts[i]->displayAccountInfo();
                    cout << "-------------------------\n";
                }
                break;


            case 7:
                cout << "Enter Account Number: ";
                cin >> no;


                for(int i = 0; i < count; i++)
                {
                    if(accounts[i]->getAccountNumber() == no)
                    {
                        cout << "Interest Amount: Rs. "
                             << accounts[i]->calculateInterest() << endl;
                        break;
                    }


                    if(i == count - 1)
                        cout << "Account not found!\n";
                }
                if(count == 0)
                    cout << "No accounts available!\n";
                break;


            case 8:
                cout << "Enter Account Number: ";
                cin >> no;


                for(int i = 0; i < count; i++)
                {
                    if(accounts[i]->getAccountNumber() == no)
                    {
                        CheckingAccount *c =
                            dynamic_cast<CheckingAccount *>(accounts[i]);


                        if(c != NULL)
                        {
                            if(c->checkOverdraft())
                                cout << "Account is using overdraft.\n";
                            else
                                cout << "Account is not using overdraft.\n";
                        }
                        else
                        {
                            cout << "This is not a Checking Account.\n";
                        }
                        break;
                    }


                    if(i == count - 1)
                        cout << "Account not found!\n";
                }
                if(count == 0)
                    cout << "No accounts available!\n";
                break;


            case 9:
                cout << "Thank you for using Banking System!\n";
                break;


            default:
                cout << "Invalid choice! Try again.\n";
        }


    } while(choice != 9);


    for(int i = 0; i < count; i++)
    {
        delete accounts[i];
    }


    return 0;
}
