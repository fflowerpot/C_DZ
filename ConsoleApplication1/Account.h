#pragma once
class Account {
protected:
    int accountNumber;
    double balance;

public:
    Account(int account, double initialBalance) {
        accountNumber = account;
        balance = initialBalance;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }
    //в завданні було завдання використати наслідування і віртуальні функції тож я вирішив що тут це буде найкраще хоч мож було і без них обійтися для цеї задачі
    
    //обробляє транзакції
    virtual void processTransaction(double amount) = 0;
};
