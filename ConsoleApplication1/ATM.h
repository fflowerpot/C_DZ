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

        void deposit(Account& account, double amount) {//Account& бо якби були ще якісь похідні класи то не доведеться робити для них окрему реалізацію і ще метод processTransaction приватний в Client а так як це публічна віртуальна функція в Account то до неї є доступ
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
                        throw InsufficientBalanceException();  // Власний клас винятку для недостатньої кількості грошей на рахунку
                    }
                }
                else {
                    throw InsufficientCashException();  // Власний клас винятку для недостатньої кількості грошей в банкоматі
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

