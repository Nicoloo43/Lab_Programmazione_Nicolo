#include "Transaction.h"

//
// Created by Nicolò on 02/08/2023.
Transaction::Type Transaction::getType() const {
    return type;
}
double Transaction::getAmount() const {
    return amount;
}
bool Transaction::operator==(const Transaction& transaction){
    if(this->type==transaction.type && this->amount==transaction.amount && this->description==transaction.description && this->date==transaction.date){
        return true;
    }else{
        return false;
    }
}
//
