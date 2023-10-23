#include <list>
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
    std::string description;
    std::string date;
    int iter=0;
    while (!file.eof()) {
        if (iter==0){
            file >> balance;
            iter++;
            continue;
        }
        file >> typeInt >> amount >> description >> date;
        Transaction::Type type = static_cast<Transaction::Type>(typeInt);
        Date newDate = Date::fromString(date);
        Transaction transaction(type, amount, description, newDate);
        transactions.push_back(transaction);
    }

    file.close();
    return true;
}
bool Account::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Errore nel salvataggio su file." << std::endl;
        return false;
    }
    file << balance << "\n";
    for (const Transaction& transaction : transactions) {

        file << static_cast<int>(transaction.getType()) << " " << transaction.getAmount() <<" "<< transaction.getDescription() << " "<< transaction.getDate() << "\n";
    }

    file.close();
    return true;
}

void Account::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
    if(static_cast<int>(transaction.getType())==1){
        balance -= transaction.getAmount();
    }else{
        balance += transaction.getAmount();
    }
}
void Account::modifyTransaction(const Transaction& transaction){
    bool trovato=false;
    int iter=0;
    for(Transaction t: transactions){
        if(t==transaction){
            trovato=true;
            if(static_cast<int>(t.getType())==1){
                balance -= t.getAmount();
            }else{
                balance += t.getAmount();
            }
            transactions.erase(transactions.begin()+iter);
            transactions.insert(transactions.begin()+iter,transaction);
            if(static_cast<int>(transaction.getType())==1){
                balance += t.getAmount();
            }else{
                balance -= t.getAmount();
            }
            break;
        }
        iter++;
    }
    if(!trovato){
        std::cerr << "Errore, impossibile modificare" << std::endl;
    }
}
void Account::printTransactions() const {
    std::string type;
    for (const Transaction& transaction : transactions) {
        if(static_cast<int>(transaction.getType())==1){
            std::cout << "Deposit with an amount of :" << " " << transaction.getAmount() << std::endl << "Description :" << transaction.getDescription() << " " << transaction.getDate() << std::endl<< std::endl;
        }else{
            std::cout << "Withdraw with an amount of :" << " " << transaction.getAmount() << std::endl << "Description :" << transaction.getDescription() << " " << transaction.getDate() << std::endl<< std::endl;
        }

    }
}
void Account::deleteTransaction(const Transaction& transaction){
    bool trovato=false;
    int iter=0;
    for(Transaction t: transactions){
        if(t==transaction){
            trovato=true;
            if(static_cast<int>(t.getType())==1){
                balance -= t.getAmount();
            }else{
                balance += t.getAmount();
            }
            transactions.erase(transactions.begin()+iter);
            break;
        }
        iter++;
    }
    if(!trovato){
        std::cerr << "Errore, impossibile rimuovere" << std::endl;
    }
}
double Account::getBalance() const {
    return balance;
}
//
