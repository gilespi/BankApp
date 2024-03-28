#ifndef BANK_H
#define BANK _H

#include "BankAccount.h"

#include <vector>
#include <string>

using namespace std;

class Bank {

	public:
		Bank(string filename) : filename(filename) 
{
	loadAcc();
}
		void createAcc(string name, int accNum, double balance);
		void readAcc(int accNum);
		void displayAllAcc() const;
		void deleteData(int accNum);
		void deposit(int accNum, double amount);
		void withdraw(int accNum, double amount);
		void saveData() const;
		void loadAcc();
		

	private:
		vector<BankAccount> accounts;
		string filename;
		
		

};


#endif
