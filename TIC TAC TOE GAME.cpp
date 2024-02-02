
#include <iostream>
#include <ctime>

void drawBoard(char* spaces);
void playerMove(char* spaces, char player);
void computerMove(char* spaces , char computer);
bool checkWinner_PC(char* spaces , char player);
bool checkWinner_Player(char* spaces, char player1);
bool checkTie(char* spaces);

int main() {

	int gameMode;

	std::cout << "********* TIC TAC TOE GAME *********\n\n";
	std::cout << "Game modes: 1 PLAYER      2 PLAYERS\n";

	do {
		std::cout << "Choose between (1,2): ";
		std::cin >> gameMode;
	} while (gameMode < 1 || gameMode > 2);

	std::cout << '\n';


	if (gameMode == 1) {

		char spaces[9];
		std::fill(spaces, spaces + 9, ' ');

		char player1 = 'X';
		char computer = 'O';
		bool running = true;

		drawBoard(spaces);
		std::cout << '\n';

		while (running) {

			std::cout << "Player 1 turn\n";
			playerMove(spaces, player1);
			drawBoard(spaces);
			std::cout << '\n';
			if (checkWinner_PC(spaces, player1)) {
				running = false;
				break;
			}
			else if (checkTie(spaces)) {
				running = false;
				break;
			}

			std::cout << "Computer turn\n";
			computerMove(spaces, computer);
			drawBoard(spaces);
			std::cout << '\n';
			if (checkWinner_PC(spaces, player1)) {
				running = false;
				break;
			}
			else if (checkTie(spaces)) {
				running = false;
				break;
			}

		}

		std::cout << "Thanks for playing!\n";

	}
	else {

		char spaces[9];
		std::fill(spaces, spaces + 9, ' ');

		char player1 = 'X';
		char player2 = 'O';
		bool running = true;

		drawBoard(spaces);
		std::cout << '\n';

		while (running) {

			std::cout << "Player 1 turn\n";
			playerMove(spaces, player1);
			drawBoard(spaces);
			std::cout << '\n';
			if (checkWinner_Player(spaces, player1)) {
				running = false;
				break;
			}
			else if (checkTie(spaces)) {
				running = false;
				break;
			}

			std::cout << "Player 2 turn\n";
			playerMove(spaces, player2);
			drawBoard(spaces);
			std::cout << '\n';
			if (checkWinner_Player(spaces, player1)) {
				running = false;
				break;
			}
			else if (checkTie(spaces)) {
				running = false;
				break;
			}

		}

		std::cout << "Thanks for playing!\n";

	}
	
}

void drawBoard(char* spaces) {

	std::cout << '\n';
	std::cout << "       |       |       " << '\n';
	std::cout << "   " << spaces[0] << "   |   " << spaces[1] << "   |   " << spaces[2] << "   " << '\n';
	std::cout << "_______|_______|_______" << '\n';
	std::cout << "       |       |       " << '\n';
	std::cout << "   " << spaces[3] << "   |   " << spaces[4] << "   |   " << spaces[5] << "   " << '\n';
	std::cout << "_______|_______|_______" << '\n';
	std::cout << "       |       |       " << '\n';
	std::cout << "   " << spaces[6] << "   |   " << spaces[7] << "   |   " << spaces[8] << "   " << '\n';
	std::cout << "       |       |       " << '\n';

}

void playerMove(char* spaces, char player) {

	int number;

	do {

		std::cout << "Enter a spot to place a marker (1-9): ";
		std::cin >> number;
		number--;

		while (spaces[number] == 'X' || spaces[number] == 'O') {
			std::cout << "This spot is taken , try again\n";
			std::cout << "Enter a spot to place a marker (1-9): ";
			std::cin >> number;
			number--;
		}

		if (spaces[number] == ' ') {
			spaces[number] = player;
			break;
		}

	} while (number > 8 || number < 0);

}

void computerMove(char* spaces, char computer) {

	int number;
	srand(time(0));

	while (true) {
		number = rand() % 9;
		if (spaces[number] == ' ') {
			spaces[number] = computer;
			break;
		}
	}

}

bool checkWinner_PC(char* spaces, char player) {

	if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {
		spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE\n";
	}
	else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {
		spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE\n";
	}
	else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
		spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE\n";
	}
	else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {
		spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE\n";
	}
	else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]) {
		spaces[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE\n";
	}
	else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]) {
		spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE\n";
	}
	else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
		spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE\n";
	}
	else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
		spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE\n";
	}
	else {
		return false;
	}
	return true;

}

bool checkWinner_Player(char* spaces, char player1) {

	if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {
		spaces[0] == player1 ? std::cout << "PLAYER 1 WINS!\n" : std::cout << "PLAYER 2 WINS\n";
	}
	else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {
		spaces[3] == player1 ? std::cout << "PLAYER 1 WINS!\n" : std::cout << "PLAYER 2 WINS\n";
	}
	else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
		spaces[6] == player1 ? std::cout << "PLAYER 1 WINS!\n" : std::cout << "PLAYER 2 WINS\n";
	}
	else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {
		spaces[0] == player1 ? std::cout << "PLAYER 1 WINS!\n" : std::cout << "PLAYER 2 WINS\n";
	}
	else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]) {
		spaces[1] == player1 ? std::cout << "PLAYER 1 WINS!\n" : std::cout << "PLAYER 2 WINS\n";
	}
	else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]) {
		spaces[2] == player1 ? std::cout << "PLAYER 1 WINS!\n" : std::cout << "PLAYER 2 WINS\n";
	}
	else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
		spaces[0] == player1 ? std::cout << "PLAYER 1 WINS!\n" : std::cout << "PLAYER 2 WINS\n";
	}
	else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
		spaces[2] == player1 ? std::cout << "PLAYER 1 WINS!\n" : std::cout << "PLAYER 2 WINS\n";
	}
	else {
		return false;
	}
	return true;

}

bool checkTie(char* spaces) {
	
	for (int i = 0; i < 9; i++) {
		if (spaces[i] == ' ') {
			return false;
		}
	}
	std::cout << "IT IS A TIE!\n";
	return true;

}
