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
            for (const auto& existingAccount : accounts) {//�������� �� ���� ��� ������ ������ ������� � ���
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
            }), accounts.end());//������� ����� remove_if ������� ������� �� ����� ��� �������� ����
    }

    void printClients() const {
        for (const auto& account : accounts) {
            std::cout << "Account Number: " << account->getAccountNumber()
                << ", Balance: " << account->getBalance() << std::endl;
        }
    }

    std::vector<Account*> findClients(std::function<bool(const Account*)> predicate) const {//��� ������ ������ �� ������ �볺���
        std::vector<Account*> matchingAccounts;
        for (const auto& account : accounts) {
            if (predicate(account.get())) {
                matchingAccounts.push_back(account.get());
            }
        }
        return matchingAccounts;
    }
    //��� ������ ����� ���� ������ ��������������� vector[0] ��� � �� ����� ���
    Account* findClient(std::function<bool(const Account*)> predicate) const {//��� ������ ������ �볺���
        for (const auto& account : accounts) {
            if (predicate(account.get())) {
                return account.get();
            }
        }
        return nullptr; //  ���� �� �������� ��������� �볺���
    }

};


