#pragma once
#include"Client.h"
class Transaction {
private:
    Account* fromAccount;
    Account* toAccount;
    double amount;

public:
    Transaction(Account* from, Account* to, double transactionAmount) {
        fromAccount = from;
        toAccount = to;
        amount = transactionAmount;
    }

    void execute() {
        try
        {
            if (fromAccount->getBalance() >= amount) {
                fromAccount->processTransaction(-amount);
                toAccount->processTransaction(amount);
            }
            else {
                throw std::runtime_error("Insufficient balance.");
            }
        }
        catch (const std::exception& e)
        {
            std::cout << "Transaction failed: " << e.what() << std::endl;
        }
       
    }
};

