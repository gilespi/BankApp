#include <iostream>
#include "Bank.h"
#include "BankAccount.h"

#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    Bank bank("customers.txt");

    string name;
    int accNum = 0;
    double amount = 0.0;
    double balance;
	int choice;

	do {
        cout <<endl << "=======================================" << endl;
		cout << "\tBank Management System" << endl;
        cout << "=======================================" << endl << endl;
		cout << "1. Create Account" << endl;
		cout << "2. Display account" << endl;
		cout << "3. Display all accounts" << endl;
		cout << "4. Delete account" << endl;
		cout << "5. Deposit" << endl;
        cout << "6. Withdraw" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "Enter account name: ";
            cin >> name;
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter initial balance: ";
            cin >> balance;
            bank.createAcc(name, accNum, balance);
            break;
        }
        
        case 2: {
            cout << "Enter account number: ";
            cin >> accNum;
            bank.readAcc(accNum);
            break;
        }
            case 3:
                bank.displayAllAcc();
                break;
            case 4: {
                cout << "Enter account number to delete: ";
                cin >> accNum;
                bank.deleteData(accNum);
                bank.saveData();
                cout << "Account number " << accNum << " successfully deleted." << endl;
                break;
            }
            case 5: {
                cout << "Enter account number to deposit: ";
                cin >> accNum;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                bank.deposit(accNum, amount);
                bank.saveData();
                bank.readAcc(accNum);
                break;
            }
            case 6:
                cout << "Enter account number to withdraw: ";
                cin >> accNum;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                bank.withdraw(accNum, amount);
                bank.saveData();
                bank.readAcc(accNum);
                break;
            default:
                cout << endl << "Wrong choice. Please try again." << endl;
    }

	} while (choice != 7);
	
	return 0;
}
