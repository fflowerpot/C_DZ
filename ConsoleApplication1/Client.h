#pragma once
#include<iostream>
#include"Account.h"
class Client : public Account {

    friend class Transaction;  // �� ���� ��� processTransaction ���� �������� �� ������ Transaction
    void processTransaction(double amount) override {
        balance += amount;
    }

public:
    Client(int account, double initialBalance) : Account(account, initialBalance) {}
};




