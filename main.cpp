#include <iostream>
#include "Account.h"
#include "Transaction.h"

int main() {
    Account account;
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 1000.0));
    account.addTransaction(Transaction(Transaction::Type::WITHDRAW, 200.0));
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 500.0));
    double balance = account.calculateBalance();
    std::cout << "Balance: " << balance << std::endl;
    account.saveToFile("transactions.txt");
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 1000.0));
    account.saveToFile("transactions.txt");
    account.loadFromFile("transactions.txt");
    balance = account.calculateBalance();
    std::cout << "Balance: " << balance << std::endl;
    account.printTransactions();
    return 0;
}
