
#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <iomanip>

class BankAccount{

private:
	double balance = 0;

public:

	BankAccount() {

	}

	BankAccount(double setBalance) {
		balance = setBalance;
	}

	double getBalance() {
		return balance;
	}

	void withdraw(double amount) {
		balance -= amount;
		if (balance < 0) {
			balance = 0;
		}
	}

	void deposit(double amount) {
		balance += amount;
	}

};


int main()
{

	// Make bank account again (30)

	BankAccount Acc1(50);
	
	std::cout << "***** Bank Masr *****";
	int choice;

	do {

		std::cout << "\n\n1. Withdraw money\n";
		std::cout << "2. Deposit money\n";
		std::cout << "3. Show balance\n";
		std::cout << "4. Exit\n";
		std::cout << "Choose a number: ";

		std::cin >> choice;

		switch (choice) {

		case 1:

			std::cout << "How many money do you want to withdraw: ";
			double amount;
			std::cin >> amount;
			Acc1.withdraw(amount);
			break;

		case 2:

			std::cout << "How many money do you want to deposit: ";
			std::cin >> amount;
			Acc1.deposit(amount);
			break;

		case 3:

			std::cout << "Your account balance: " << std::setprecision(2) << std::fixed << Acc1.getBalance() << "$";
			break;

		case 4:
			return 0;

		default:
			std::cout << "Wrong number! try again.";
			break;

		}


	} while (choice < 4 || choice > 1);

}


