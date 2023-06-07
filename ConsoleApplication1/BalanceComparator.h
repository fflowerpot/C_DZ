#pragma once
#include<vector>
#include"Client.h"
class BalanceComparator {
public:
    bool operator()(const Account* account1, const Account* account2) const {
        return account1->getBalance() < account2->getBalance();
    }
};


