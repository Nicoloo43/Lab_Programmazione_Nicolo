//
// Created by Nicolò on 02/08/2023.
//

#ifndef UNTITLED3_ACCOUNT_H
#define UNTITLED3_ACCOUNT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Transaction.h"

class Account {
public:
    void addTransaction(const Transaction& transaction) ;

    double calculateBalance() const ;

    bool saveToFile(const std::string& filename) const ;
    bool loadFromFile(const std::string& filename);
    void printTransactions() const;
private:
    std::vector<Transaction> transactions;
};
#endif //UNTITLED3_ACCOUNT_H
