#pragma once
#include"ClientDatabase.h"
#include"Transaction.h"
#include"BalanceComparator.h"
#include"ATM.h"
//не підключав using namespace std; як я розумію якщо використовується його обмежений функціонал то краще  використовувати  std::

std::vector<Account*> filterClientsByBalance(const std::vector<Account*>& accounts, double minBalance) {
    std::vector<Account*> filteredAccounts;
    std::copy_if(accounts.begin(), accounts.end(), std::back_inserter(filteredAccounts),
        [minBalance](const Account* account) {
            return account->getBalance() >= minBalance;
        });
    return filteredAccounts;
}


int main() {
    ClientDatabase clientDB;
    clientDB.addClient(std::make_unique<Client>(1001, 6000.0));
    clientDB.addClient(std::make_unique<Client>(1002, 7000.0));
    clientDB.addClient(std::make_unique<Client>(1003, 3000.0));
    //clientDB.addClient(std::make_unique<Client>(1003, 3000.0));
    
    clientDB.removeClient(1003);

    ATM atm(10000.0);

    std::cout << "Initial ATM Cash: " << atm.getCashAmount() << std::endl;
    //---Transaction---//
    Account* fromClient = clientDB.findClient([](const Account* account) {
        return account->getAccountNumber() == 1001;
        });

    Account* toClient = clientDB.findClient([](const Account* account) {
        return account->getAccountNumber() == 1002;
        });

    Transaction transaction(fromClient, toClient, 1000.0);
    transaction.execute();
    //---------------//
    //--- atm.withdraw ----//
    Account* matchingClient = clientDB.findClient([](const Account* account) {
        return account->getAccountNumber() == 1003;
        });

    if (matchingClient != nullptr) {//перевірка чи є клієнт в базі даних
        atm.withdraw(*matchingClient, 3500);
    }
    else {
        std::cout << "Client not found." << std::endl;
    }
    //-----------------//

    std::cout << "Updated ATM Cash: " << atm.getCashAmount() << std::endl;

    clientDB.printClients();

    std::vector<Account*> highBalanceClients = filterClientsByBalance(clientDB.findClients([](const Account* account) {
        return account->getAccountNumber() != 1002;
        }), 5000.0);

    std::cout << "Clients with high balance:" << std::endl;
    for (const auto& account : highBalanceClients) {
        std::cout << "Account Number: " << account->getAccountNumber()
            << ", Balance: " << account->getBalance() << std::endl;
    }

}
