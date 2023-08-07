//
// Created by Nicolò on 03/08/2023.
#include <gtest/gtest.h>
#include "../Transaction.h"
#include "../Account.h"
class AccountFixture : public ::testing::Test {
protected:
    void SetUp() override {
        account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 1000.0));
        account.addTransaction(Transaction(Transaction::Type::WITHDRAW, 200.0));
        account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 500.0));
    }
    Account account;
};
TEST_F(AccountFixture, Test_account_balance) {
    double balance = account.calculateBalance();
    ASSERT_EQ(balance, 1300.0);
}
TEST_F(AccountFixture, Test_account_save) {
    ASSERT_TRUE(account.saveToFile("transactions.txt"));
}
TEST_F(AccountFixture, Test_account_load) {
    ASSERT_TRUE(account.loadFromFile("transactions.txt"));
}
//
