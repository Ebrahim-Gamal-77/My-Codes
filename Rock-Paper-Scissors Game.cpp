
#include <iostream>
#include <cmath>
#include <string>
#include <ctime>



int main()
{

	char computer, player;

	std::cout << "\n****** Rock-Paper-Scissors Game ******\n";
	std::cout << "**************************************\n\n";

	std::cout << "'r' for Rock\n";
	std::cout << "'p' for Paper\n";
	std::cout << "'s' for Scissors\n";
	
	player = playerChoice();
	computer = computerChoice();
	chooseWinner(player , computer);

}



char computerChoice() {

	srand(time(0));

	char choice;

	int num = rand() % 3 + 1;

	if (num == 1) {
		choice = 'r';
	}
	else if (num == 2) {
		choice = 'p';
	}
	else {
		choice = 's';
	}

	switch (choice) {

	case 'r':
		std::cout << "Computer choice is: Rock\n";
		break;
	case 'p':
		std::cout << "Computer choice is: paper\n";
		break;
	case 's':
		std::cout << "Computer choice is: Scissors\n";
		break;
	default:
		std::cout << "Invalid letter!\n";
	}

	return choice;

}

char playerChoice() {

	char choice;

	do {

		std::cout << "Choose a letter: ";
		std::cin >> choice;

		switch (tolower(choice)) {

		case 'r':
			std::cout << "\nYour choice is: Rock\n";
			break;
		case 'p':
			std::cout << "\nYour choice is: paper\n";
			break;
		case 's':
			std::cout << "\nYour choice is: Scissors\n";
			break;
		default:
			std::cout << "\nInvalid letter!\n";
		}

	} while (choice != 'r' && choice != 'p' && choice != 's');

	return choice;

}

void chooseWinner(char player , char computer) {

	if (player == 'r' && computer == 'r') {
		std::cout << "\nIt's a tie!\n";
	}
	else if (player == 'r' && computer == 'p') {
		std::cout << "\nYou lose!\n";
	}
	else if (player == 'r' && computer == 's') {
		std::cout << "\nYou win!\n";
	}
	else if (player == 'p' && computer == 'r') {
		std::cout << "\nYou lose!\n";
	}
	else if (player == 'p' && computer == 'p') {
		std::cout << "\nIt's a tie!\n";
	}
	else if (player == 'p' && computer == 's') {
		std::cout << "\nYou lose!\n";
	}
	else if (player == 's' && computer == 'r') {
		std::cout << "\nYou lose!\n";
	}
	else if (player == 's' && computer == 'p') {
		std::cout << "\nYou win!\n";
	}
	else if (player == 's' && computer == 's') {
		std::cout << "\nIt's a tie!\n";
	}


}

