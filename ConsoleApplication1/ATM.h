#pragma once
#include"Client.h"
#include"Exception.h"
    class ATM {
    private:
        double cashAmount;

    public:
        ATM(double initialCash) {
            cashAmount = initialCash;
        }

        double getCashAmount() const {
            return cashAmount;
        }

        void deposit(Account& account, double amount) {//Account& �� ���� ���� �� ���� ������ ����� �� �� ���������� ������ ��� ��� ������ ��������� � �� ����� processTransaction ��������� � Client � ��� �� �� ������� ��������� ������� � Account �� �� �� � ������
            account.processTransaction(amount);
            cashAmount += amount;
        }

        void withdraw(Account& account, double amount) {
            try {
                if (amount <= cashAmount) {
                    if (amount <= account.getBalance()) {
                        account.processTransaction(-amount);
                        cashAmount -= amount;
                    }
                    else {
                        throw InsufficientBalanceException();  // ������� ���� ������� ��� ����������� ������� ������ �� �������
                    }
                }
                else {
                    throw InsufficientCashException();  // ������� ���� ������� ��� ����������� ������� ������ � ��������
                }
            }
            catch (const InsufficientBalanceException& e) {
                std::cout << "Withdrawal failed: " << e.what() << std::endl;
            }
            catch (const InsufficientCashException& e) {
                std::cout << "Withdrawal failed: " << e.what() << std::endl;
            }
        }
    };

