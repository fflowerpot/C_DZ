#pragma once
#include <algorithm>
class InsufficientBalanceException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Insufficient balance.";
    }
};
class InsufficientCashException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Insufficient cash in ATM.";
    }
};


