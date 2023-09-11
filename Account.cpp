#include "Account.h"

//
// Created by Nicolò on 02/08/2023.
bool Account::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    transactions.clear();

    int typeInt;
    double amount;

    while (file >> typeInt >> amount) {
        Transaction::Type type = static_cast<Transaction::Type>(typeInt);
        Transaction transaction(type, amount);
        transactions.push_back(transaction);
    }

    file.close();
    return true;
}
bool Account::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout<<"Errore nel salvataggio su file."<<std::endl;
        return false;
    }

    for (const Transaction& transaction : transactions) {
        file << static_cast<int>(transaction.getType()) << " " << transaction.getAmount() << "\n";
    }

    file.close();
    return true;
}
double Account::calculateBalance() const {
    double balance = 0.0;
    for (const Transaction& transaction : transactions) {
        if (transaction.getType() == Transaction::Type::DEPOSIT) {
            balance += transaction.getAmount();
        } else {
            balance -= transaction.getAmount();
        }
    }
    return balance;
}

void Account::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}

void Account::printTransactions() const {
    std::string type;
    for (const Transaction& transaction : transactions) {
        if(static_cast<int>(transaction.getType())==1){
            std::cout << "Deposit :" << " " << transaction.getAmount() << std::endl;
        }else{
            std::cout << "Withdraw :" << " " << transaction.getAmount() << std::endl;
        }

    }
}

//
