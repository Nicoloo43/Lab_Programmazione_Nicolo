#include <iostream>
#include "Account.h"
#include "Transaction.h"

int main() {
    Account account;
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 1000.0, "deposit1", Date(1, 1, 2020)));
    account.addTransaction(Transaction(Transaction::Type::WITHDRAW, 300.0, "withdraw1", Date(2, 1, 2020)));
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 500.0, "deposit2", Date(3, 1, 2020)));
    std::cout << "First Balance: " << account.getBalance() << std::endl;
    account.saveToFile("transactions.txt");
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 1000.0, "deposit3", Date(1, 1, 2020)));
    account.saveToFile("transactions.txt");
    std::cout << "Second Balance: " << account.getBalance() << std::endl;
    account.loadFromFile("transactions.txt");
    std::cout << "Reading Transactions : " << std::endl;
    account.printTransactions();
    return 0;
}
