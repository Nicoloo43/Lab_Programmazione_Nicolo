//
// Created by Nicolò on 03/08/2023.
#include <gtest/gtest.h>
#include "../Transaction.h"
#include "../Account.h"
class AccountFixture : public ::testing::Test {
protected:
    void SetUp() override {
        Transaction transaction(Transaction::Type::DEPOSIT, 1000.0, "deposit1", Date(1, 1, 2020));
        account.addTransaction(transaction);
        transaction = Transaction(Transaction::Type::WITHDRAW, 200.0, "withdraw1", Date(2, 1, 2020));
        account.addTransaction(transaction);
        transaction = Transaction(Transaction::Type::DEPOSIT, 500.0, "deposit2", Date(3, 1, 2020));
        account.addTransaction(transaction);
    }
    Account account;
};
TEST_F(AccountFixture, TestAddTransaction) {
    Transaction transaction(Transaction::Type::WITHDRAW, 300.0, "withdraw1", Date(2, 1, 2020));
    account.addTransaction(transaction);
    for(Transaction T : account.getTransaction()){
        if(T==transaction){
            ASSERT_TRUE(true);
        }
    }
}
TEST_F(AccountFixture, TestDeleteTransaction) {
    Transaction transaction(Transaction::Type::WITHDRAW, 300.0, "withdraw1", Date(2, 1, 2020));
    account.addTransaction(transaction);
    account.deleteTransaction(transaction);
    bool equal = false;
    for(Transaction T : account.getTransaction()){
        if(T==transaction){
            equal=true;
        }
    }
    ASSERT_FALSE(equal);
}
TEST_F(AccountFixture, TestModifyTransaction) {
Transaction oldTransaction(Transaction::Type::WITHDRAW, 300.0, "withdraw1", Date(2, 1, 2020));
    account.addTransaction(oldTransaction);
    Transaction newTransaction = Transaction(Transaction::Type::DEPOSIT, 1000.0, "deposit3", Date(1, 1, 2020));
    account.modifyTransaction(oldTransaction, newTransaction);
    bool equal = false;
    for(Transaction T : account.getTransaction()){
        if(T==newTransaction){
            equal=true;
        }
    }
    ASSERT_TRUE(equal);
}
TEST_F(AccountFixture, TestSaveToFile) {
    Transaction transaction(Transaction::Type::WITHDRAW, 300.0, "withdraw1", Date(2, 1, 2020));
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
