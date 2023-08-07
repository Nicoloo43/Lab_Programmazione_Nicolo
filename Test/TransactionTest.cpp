//
// Created by Nicolò on 07/08/2023.
#include "../Transaction.h"
#include "../Account.h"
#include <gtest/gtest.h>//

TEST(Transaction, Test_transaction_type) {
    Transaction transaction(Transaction::Type::DEPOSIT, 1000.0);
    ASSERT_EQ(transaction.getType(), Transaction::Type::DEPOSIT);
}
TEST(Transaction, Test_transaction_amount) {
    Transaction transaction(Transaction::Type::DEPOSIT, 1000.0);
    ASSERT_EQ(transaction.getAmount(), 1000.0);
}
TEST(Account, Test_account_balance) {
    Account account;
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 1000.0));
    account.addTransaction(Transaction(Transaction::Type::WITHDRAW, 200.0));
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 500.0));
    double balance = account.calculateBalance();
    ASSERT_EQ(balance, 1300.0);
}
TEST(Account, Test_account_save) {
    Account account;
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 1000.0));
    account.addTransaction(Transaction(Transaction::Type::WITHDRAW, 200.0));
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 500.0));
    ASSERT_TRUE(account.saveToFile("transactions.txt"));
}
TEST(Account, Test_account_load) {
    Account account;
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 1000.0));
    account.addTransaction(Transaction(Transaction::Type::WITHDRAW, 200.0));
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 500.0));
    ASSERT_TRUE(account.loadFromFile("transactions.txt"));
}
