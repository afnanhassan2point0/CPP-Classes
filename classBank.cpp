#include <iostream>
#include <string>
using namespace std;
class Bank
{
private:
    string accName, accNo, accType;
    double accBal;

public:
    Bank()
    {
        accBal = 0.0;
        accName = "Bank Property";
        accNo = "x.y.z";
        accType = "Banking";
    }
    void input()
    {
        cout << "\nEnter username : ";
        cin.ignore();
        getline(cin, accName);
        cout << "Enter account type : ";
        getline(cin, accType);
        cout << "Enter account number : ";
        getline(cin, accNo);
        cout << "\n Account created! \n Balance ~ 0.0 $\n";
        accBal = 0.0;
    }
    void deposit(float amount)
    {
        accBal += amount;
        cout << "\n Amount added ~ " << accBal << endl;
    }
    void withdraw(float amount)
    {
        if (accBal < amount)
            cout << "\n Error : low balance ~ " << accBal << endl;
        else
        {
            accBal -= amount;
            cout << "\n Amount deducted ~ " << amount;
            cout << "\n Remaining balance ~ " << accBal << " $\n";
        }
    }
    void display()
    {
        cout << endl
             << accNo << endl
             << accName << endl
             << accType << endl
             << accBal << " $\n";
    }
    bool operator+(Bank sec)
    {
        float amount;
        cout << "\nEnter amount : ";
        cin >> amount;
        if (amount > sec.accBal)
        {
            cout << "Error : low balance ~ " << sec.accBal << " $\n";
            return 0;
        }
        else
        {
            accBal += amount;
            sec.accBal = sec.accBal - amount;
            cout << "\nTransaction successful! \n";
            return 1;
        }
    }
};
int main()
{
    Bank bank, user;
    float dollar;
    char ch;
repeat:
    cout << "\n1. Create account \n2. Deposit amount \n3. Withdraw money \n4. Display details \n5. Money Transfer \n0. Exit program \n Enter choice : ";
    cin >> ch;
    if (ch == '0')
    {
        cout << "\nProgram exited successfully!\n\n";
        exit(0);
    }
    else if (ch == '1')
    {
        user.input();
        goto repeat;
    }
    else if (ch == '2')
    {
        cout << "\nEnter amount : ";
        cin >> dollar;
        user.deposit(dollar);
        goto repeat;
    }
    else if (ch == '3')
    {
        cout << "\nEnter amount : ";
        cin >> dollar;
        user.withdraw(dollar);
        goto repeat;
    }
    else if (ch == '4')
    {
        user.display();
        goto repeat;
    }
    else if (ch == '5')
    {
        bool task;
        task = bank + user;
        if (task)
        {
            cout << "The Receiver details:";
            bank.display();
            cout << "\nYour details:";
            user.display();
        }
        goto repeat;
    }
    else
    {
        cout << "\nError : invalid input! \n";
        goto repeat;
    }
    return 0;
}