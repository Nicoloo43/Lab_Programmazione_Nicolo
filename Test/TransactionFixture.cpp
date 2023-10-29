//
// Created by Nicolò on 07/08/2023.
#include "../Transaction.h"
#include "../Account.h"
#include <gtest/gtest.h>
class TransactionFixture : public ::testing::Test {
protected:
    void SetUp() override {
    }
    Account account;
};
TEST_F(TransactionFixture, TestAddTransaction) {
    Transaction transaction(Transaction::Type::WITHDRAW, 300.0, "withdraw1", Date(2, 1, 2020));
    account.addTransaction(transaction);
    ASSERT_EQ(account.getBalance(), -300.0);
}
TEST_F(TransactionFixture, TestDeleteTransaction) {
    Transaction transaction(Transaction::Type::WITHDRAW, 300.0, "withdraw1", Date(2, 1, 2020));
    account.addTransaction(transaction);
    account.deleteTransaction(transaction);
    ASSERT_EQ(account.getBalance(), 0.0);
}
TEST_F(TransactionFixture, TestModifyTransaction) {
    Transaction oldtransaction(Transaction::Type::WITHDRAW, 300.0, "withdraw1", Date(2, 1, 2020));
    account.addTransaction(oldtransaction);
    Transaction newtransaction = Transaction(Transaction::Type::DEPOSIT, 1000.0, "deposit3", Date(1, 1, 2020));
    account.modifyTransaction(oldtransaction, newtransaction);
    ASSERT_EQ(account.getBalance(), 1000.0);
}
