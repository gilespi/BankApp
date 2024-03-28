#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

using namespace std;

class BankAccount
{
	private:
		string name;
		int accNum;
		double balance;

	public:
		BankAccount(string name, int accNum, double balance) :
			name(name), accNum(accNum), balance(balance) {};

			string getAccName() const;
			int getAccNum() const;
			double getBalance() const;

			void deposit (double amount);
			bool withdraw (double amount);
			void display() const;

};

#endif
