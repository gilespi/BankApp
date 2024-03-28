#include "BankAccount.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


string BankAccount::getAccName() const
{
	return name;
}

int BankAccount::getAccNum() const
{
	return accNum;
}

double BankAccount::getBalance() const
{
	return balance;
}

void BankAccount::deposit(double amount)
{
	balance += amount;
}

bool BankAccount::withdraw(double amount)
{
	if (balance >= amount) {
		balance -= amount;
		return true;
	}

	return false;

}

void BankAccount::display() const
{
	cout << "Name: " << name << "\tAcc No: " << accNum << "\tBalance: $" 
		<< fixed << setprecision(2) << balance << endl;
}