//
// Created by Nicolò on 07/08/2023.
#include "../Transaction.h"
#include "../Account.h"
#include <gtest/gtest.h>//
//ricontrollare test tipo rileggere file e controllare ci sia quello che c'è stato inserito
TEST(Transaction, TestAddTransaction) {
    Transaction transaction(Transaction::Type::WITHDRAW, 300.0, "withdraw1", Date(2, 1, 2020));
    Account account;
    account.addTransaction(transaction);
    ASSERT_EQ(account.getBalance(), -300.0);
}
TEST(Transaction, TestDeleteTransaction) {
    Transaction transaction(Transaction::Type::WITHDRAW, 300.0, "withdraw1", Date(2, 1, 2020));
    Account account;
    account.addTransaction(transaction);
    account.deleteTransaction(transaction);
    ASSERT_EQ(account.getBalance(), 0.0);
}
TEST(Transaction, TestModifyTransaction) {
    Transaction oldtransaction(Transaction::Type::WITHDRAW, 300.0, "withdraw1", Date(2, 1, 2020));
    Account account;
    account.addTransaction(oldtransaction);
    Transaction newtransaction = Transaction(Transaction::Type::DEPOSIT, 1000.0, "deposit3", Date(1, 1, 2020));
    account.modifyTransaction(oldtransaction, newtransaction);
    ASSERT_EQ(account.getBalance(), 1000.0);
}
TEST(Transaction, TestSaveToFile) {
    Transaction transaction(Transaction::Type::WITHDRAW, 300.0, "withdraw1", Date(2, 1, 2020));
    Account account;
    account.addTransaction(transaction);
    account.saveToFile("transactions.txt");
    account.loadFromFile("transactions.txt");
    bool equal = false;
    for(Transaction T : account.getTransaction()){
        if(T==transaction){
            equal=true;
        }
    }
    ASSERT_TRUE(equal);
}