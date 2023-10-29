#include "../Transaction.h"
#include "../Account.h"
#include <gtest/gtest.h>

TEST(Account, TestAddTransaction) {
    Transaction transaction(Transaction::Type::DEPOSIT, 1000.0, "deposit1", Date(1, 1, 2020));
    Account account;
    account.addTransaction(transaction);
    for(Transaction T : account.getTransaction()){
        if(T==transaction){
            ASSERT_TRUE(true);
        }
    }
}
TEST(Account, TestDeleteTransaction) {
    Transaction transaction(Transaction::Type::DEPOSIT, 1000.0, "deposit1", Date(1, 1, 2020));
    Account account;
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
TEST(Account, TestModifyTransaction) {
    Transaction oldTransaction(Transaction::Type::DEPOSIT, 1000.0, "deposit1", Date(1, 1, 2020));
    Account account;
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
TEST(Account, TestSaveToFile) {
    Transaction transaction(Transaction::Type::DEPOSIT, 1000.0, "deposit1", Date(1, 1, 2020));
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