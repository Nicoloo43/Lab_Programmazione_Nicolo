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
std::string Transaction::getDescription() const {
    return description;
}
std::string Transaction::getDate() const {
    std::string dayStr = std::to_string(this->date.getDay());
    std::string monthStr = std::to_string(this->date.getMonth());
    std::string yearStr = std::to_string(this->date.getYear());

    // Assicura che le parti della data abbiano sempre due cifre (aggiungi lo zero iniziale se necessario)
    if (dayStr.length() == 1) {
        dayStr = "0" + dayStr;
    }
    if (monthStr.length() == 1) {
        monthStr = "0" + monthStr;
    }

    std::string formattedDate = dayStr + "/" + monthStr + "/" + yearStr;

    return formattedDate;
}
//
