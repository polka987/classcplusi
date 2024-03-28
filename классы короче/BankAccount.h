#pragma once

#include <iostream>
#include <iomanip>
using namespace std;


class BankAccount
{

private:
	int AccountNumber;//номер счета
	double balanceAcc;//баланс
	double InterestRate;//процентная ставка
public:
	BankAccount(int numberacc, double balance) {
		this->AccountNumber = numberacc;
		this->balanceAcc = balance;
		this->InterestRate = 0;
	}
	void deposit(double amount) {
		this->balanceAcc += amount;
	}
	void withdraw(double amount) {
		if (this->balanceAcc >= amount) {
			this->balanceAcc -= amount;
			cout << "Вывод средств $" << fixed << setprecision(2) << amount << " успешный" << endl;
		}
		else {
			cout << "Перевод не удалось осуществить. Недостаточно средств на счёте" << endl;
		}
	}

};

