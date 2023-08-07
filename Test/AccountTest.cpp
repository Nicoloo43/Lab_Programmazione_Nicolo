
#include "googletest-main/googletest/include/gtest.h"
#include "../Transaction.h"
#include "../Account.h"
TEST(AccountTest, Test_account_balance) {
    Account account;
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 1000.0));
    account.addTransaction(Transaction(Transaction::Type::WITHDRAW, 200.0));
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 500.0));
    double balance = account.calculateBalance();
    ASSERT_EQ(balance, 1300.0);
}
TEST(AccountTest, Test_account_save) {
    Account account;
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 1000.0));
    account.addTransaction(Transaction(Transaction::Type::WITHDRAW, 200.0));
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 500.0));
    ASSERT_TRUE(account.saveToFile("transactions.txt"));
}
TEST(AccountTest, Test_account_load) {
    Account account;
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 1000.0));
    account.addTransaction(Transaction(Transaction::Type::WITHDRAW, 200.0));
    account.addTransaction(Transaction(Transaction::Type::DEPOSIT, 500.0));
    ASSERT_TRUE(account.loadFromFile("transactions.txt"));
}


//
