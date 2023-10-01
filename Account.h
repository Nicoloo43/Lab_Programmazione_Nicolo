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
    void deleteTransaction(const Transaction& transaction);
    void modifyTransaction(const Transaction& transaction);//eliminare e modificare transazioni
    //modificare calculateBalance così che rimanga aggiornato
    bool saveToFile(const std::string& filename) const ;
    bool loadFromFile(const std::string& filename);
    void printTransactions() const;
    double getBalance() const;
private:
    std::vector<Transaction> transactions;
    double balance=0;
};
#endif //UNTITLED3_ACCOUNT_H
