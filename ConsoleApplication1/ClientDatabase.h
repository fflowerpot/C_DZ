#pragma once
#include<vector>
#include <functional>
#include"Client.h"
#include"Exception.h"
class ClientDatabase {
private:
    std::vector<std::unique_ptr<Account>> accounts;

public:
   
    void addClient(std::unique_ptr<Account> account) {
        try
        {
            for (const auto& existingAccount : accounts) {//перевірка чи нема вже такого номеру акаунту в базі
                if (existingAccount->getAccountNumber() == account->getAccountNumber()) {
                    throw std::runtime_error("Client with the same account number already exists.");
                }
            }
            accounts.push_back(std::move(account));
        }
        catch (const std::exception& e) {
            std::cout << "Error adding client: " << e.what() << std::endl;
        }
        
    }


    void removeClient(int accountNumber) {
        accounts.erase(std::remove_if(accounts.begin(), accounts.end(),[accountNumber](const std::unique_ptr<Account>& account) {
                return account->getAccountNumber() == accountNumber;
            }), accounts.end());//цікавий метод remove_if переміщує елемент на кінець щоб видалити його
    }

    void printClients() const {
        for (const auto& account : accounts) {
            std::cout << "Account Number: " << account->getAccountNumber()
                << ", Balance: " << account->getBalance() << std::endl;
        }
    }

    std::vector<Account*> findClients(std::function<bool(const Account*)> predicate) const {//для пошуку быльше ніж одного клієнта
        std::vector<Account*> matchingAccounts;
        for (const auto& account : accounts) {
            if (predicate(account.get())) {
                matchingAccounts.push_back(account.get());
            }
        }
        return matchingAccounts;
    }
    //для одного можна було просто використовуваит vector[0] але я не хотыв так
    Account* findClient(std::function<bool(const Account*)> predicate) const {//для пошуку одного клієнта
        for (const auto& account : accounts) {
            if (predicate(account.get())) {
                return account.get();
            }
        }
        return nullptr; //  якщо не знайдено збігаючого клієнта
    }

};


