//
// Created by Nicolò on 02/08/2023.
//

#ifndef UNTITLED3_TRANSACTION_H
#define UNTITLED3_TRANSACTION_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Date.h"

class Transaction {
public:
    enum class Type { DEPOSIT, WITHDRAW };

    Transaction(Type type, double amount, const std::string& description, const Date& date): type(type), amount(amount), description(description), date(date) {}

    Type getType() const;
    bool operator==(const Transaction& transaction);
    double getAmount() const;

private:
    Type type;
    double amount;//non negativo
    std::string description;
    Date date; //data e descrizione
};

#endif //UNTITLED3_TRANSACTION_H
