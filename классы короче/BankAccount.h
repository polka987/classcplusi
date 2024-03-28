#pragma once

#include <iostream>
#include <iomanip>
using namespace std;


class BankAccount
{

private:
	int AccountNumber;//����� �����
	double balanceAcc;//������
	double InterestRate;//���������� ������
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
			cout << "����� ������� $" << fixed << setprecision(2) << amount << " ��������" << endl;
		}
		else {
			cout << "������� �� ������� �����������. ������������ ������� �� �����" << endl;
		}
	}

};

