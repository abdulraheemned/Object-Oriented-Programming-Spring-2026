#include <iostream>
using namespace std;

class BankAccount {
public:
    int balance;
    int transactions;

    BankAccount() {
        balance = 0;
        transactions = 0;
    }

    void deposit(int amount) {
        balance += amount;
        transactions++;
    }

    void withdraw(int amount) {
        balance -= amount;
        transactions++;
    }

    void showBalance() {
        cout << "Balance: " << balance << endl;
    }

    void showTransactions() {
        cout << "Transactions: " << transactions << endl;
    }
};

int main() {
    BankAccount acc;

    acc.deposit(5000);
    acc.deposit(300);
    acc.withdraw(4000);

    acc.showBalance();
    acc.showTransactions();

    return 0;
}

