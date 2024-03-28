
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class BankAccount {
private:
    int AccountNumber;
    double balance;
    double interestRate;
public:
	BankAccount(int accNum, double initBal) {//конструктор
		this->AccountNumber = accNum;
		this->balance = initBal;
		this->interestRate = 0;
	}

	void deposit(double amount) {//операция для внесения средств
		this->balance += amount;
        cout << "Операция проведена успешно."<<endl;
	}

    bool withdraw(double amount) {//снятие средств
        if (this->balance >= amount) {
            balance -= amount;
            return true;
        }
        std::cout << "Недостаточно средств для снятия." << std::endl;
        return false;
    }

    double getBalance() {//узнать баланс
        return this->balance;
    }

    double getInterest() {//расччитать процентную ставку
        double interest = this->balance * this->interestRate * (1.0/12.0)/100;
        return interest;
    }

    void setInterestRate(double rate) {//обновление(присваивание) процентной ставки
        this->interestRate = rate;
        cout << "Процентная ставка обновлена на " << fixed << setprecision(2) << rate << "%" << endl;
    }

    int getAccountNumber() {//Название счета
        return this->AccountNumber;
    }

    friend bool transfer(BankAccount& acc1, BankAccount& acc2, double amount);//дружественная :) функция
};

bool transfer(BankAccount& acc1, BankAccount& acc2, double amount) {//перевод вместе с условием
    if (acc1.balance < amount) {
        std::cout << "Недостаточно средств для перевода. Баланс не изменился" << endl;
        return false;
    }
    acc1.balance -= amount;
    acc2.balance += amount;
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian"); // локализация
    int numberacc1, numberacc2;
    double bal1, bal2, perevod, interestRate1, interestRate2;
    cout << "Введите номер первого счета и его изначальный баланс\n";
    cin >> numberacc1;
    cin >> bal1;
    cout << "Введите номер второго счета и его изначальный баланс\n";
    cin >> numberacc2;
    cin >> bal2;
    cout << "Введите процентную ставку первого счёта\n";
    cin >> interestRate1;
    cout << "Введите процентную ставку второго счёта\n";
    cin >> interestRate2;

	BankAccount Acc1(numberacc1, bal1);
	BankAccount Acc2(numberacc2, bal2);
    Acc1.setInterestRate(interestRate1);//обновляем процентные ставки
    Acc2.setInterestRate(interestRate2);
	cout << "Введите сколько перевести со счёта " << Acc1.getAccountNumber() << " на счёт " << Acc2.getAccountNumber() << endl;
	cin >> perevod;
    cout << "\n-----------------------------------------------------\n";
    cout << "Исходные балансы:\n";
	cout << "Банковский счёт номер " << Acc1.getAccountNumber() << ": $" << Acc1.getBalance() << endl;
	cout << "Банковский счёт номер " << Acc2.getAccountNumber() << ": $" << Acc2.getBalance() << endl;
    cout << "\n-----------------------------------------------------\n";
    cout << "После перевода:\n";
    transfer(Acc1, Acc2, perevod);
    cout << "Банковский счёт номер " << Acc1.getAccountNumber() << ": $" << Acc1.getBalance() << endl;
    cout << "Банковский счёт номер " << Acc2.getAccountNumber() << ": $" << Acc2.getBalance() << endl;
    cout << "\n-----------------------------------------------------\n";
    cout << "Проценты, полученные за последний месяц:\n";
    cout << "Банковский счёт номер " << Acc1.getAccountNumber() << ": $" << Acc1.getInterest() << endl;
    cout << "Банковский счёт номер " << Acc2.getAccountNumber() << ": $" << Acc2.getInterest() << endl;

	return 0;
    
}
