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
    //� ������� ���� �������� ����������� ����������� � �������� ������� ��� � ������ �� ��� �� ���� �������� ��� ��� ���� � ��� ��� ������� ��� �� ������
    
    //�������� ����������
    virtual void processTransaction(double amount) = 0;
};
