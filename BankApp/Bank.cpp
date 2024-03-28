#include "Bank.h"
#include "BankAccount.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void Bank::createAcc(string name, int accNum, double balance)
{
	BankAccount newAcc(name, accNum, balance);
	accounts.push_back(newAcc);
	saveData();
}

void Bank::readAcc(int accNum)
{
	for (const auto& account : accounts) {
		if (account.getAccNum() == accNum) {
			account.display();
			return;
		}
	}

	cout << endl << "Account not found." << endl;

}

void Bank::displayAllAcc() const
{
	cout << endl << "All Accounts: " << endl;
	for (const auto& account : accounts) {
		account.display();
	} 	
}

void Bank::deleteData(int accNum)
{
	for (auto item = accounts.begin(); item != accounts.end(); item++) {
		if (item->getAccNum() == accNum) {
			accounts.erase(item);
			saveData();
			cout <<endl << "Account deleted successfully." << endl;
			return;
		}
	}

	cout << endl << "Account not found." << endl;

}

void Bank::deposit(int accNum, double amount)
{
	for (auto& account : accounts) {
		if (account.getAccNum() == accNum) {
			account.deposit(amount);
			saveData();
			cout << endl << "Deposit successful." << endl;
			return;
		}
	}

	cout << endl << "Account not found." << endl;

}

void Bank::withdraw(int accNum, double amount)
{
	for (auto& account : accounts) {
		if (account.getAccNum() == accNum) {
			if (account.withdraw(amount)) {
				saveData();
				cout << endl << "Withdrawal successful." << endl;
			}
			else {
				cout << endl << "Insufficient funds." << endl;
			}

			return;

		}
	}

	cout << endl << "Account not found." << endl;

}

void Bank::saveData() const
{
	ofstream outFile("customers.txt");
	if (outFile.is_open()) {
		for (const auto& account : accounts) {
			outFile << account.getAccName() << " " << account.getAccNum()
				<< " " << account.getBalance() << endl;
		}
		outFile.close();
	}
	else {
		cout << endl << "Unable to open file for saving accounts." << endl;
	}
}

void Bank::loadAcc()
{
	ifstream inFile("customers.txt");
	if (inFile.is_open()) {
		string name;
		int accNum;
		double balance;
		while (inFile >> name >> accNum >> balance) {
			BankAccount account(name, accNum, balance);
			accounts.push_back(account);
		}
		inFile.close();
	}
	else {
		cout << endl << "Unable to open file for loading accounts." << endl;
	}
}