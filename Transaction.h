//
// Created by Nicolò on 02/08/2023.
//

#ifndef UNTITLED3_TRANSACTION_H
#define UNTITLED3_TRANSACTION_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Transaction {
public:
    enum class Type { DEPOSIT, WITHDRAW };

    Transaction(Type type, double amount)
            : type(type), amount(amount) {}

    Type getType() const;

    double getAmount() const;

private:
    Type type;
    double amount;
};

#endif //UNTITLED3_TRANSACTION_H
