
#include <iostream>
#include <cmath>
#include <string>


int main() {

	std::string questions[] = {
		"1. What is the religion of the god?"
		,"2. Who is the last prophet?"
		,"3. How many prayers in Islam?"
		,"4. Is Hajj obligatory in Islam?" };

	std::string options[][4] = {
		{"A. Judaism" , "B. Christianity" , "C. Islam" , "D. Hinduism"},
		{"A. Moses" , "B. Muhammed" , "C. Jesus" , "D. Joseph"},
		{"A. Just one" , "B. Three" , "C. Four" , "D. Five"},
		{"A. Obligatory for those who can afford it" , "B. It is forbidden" , "C. It is permissible" , "D. It is disliked"}
	};

	char answers[] = { 'C' , 'B' , 'D' , 'A' };

	int questionsSize = sizeof(questions) / sizeof(questions[0]);
	char guess;
	int score = 0;

	// printing questions
	for (int i = 0; i < questionsSize; i++) {

		std::cout << "\n*********************************\n";
		std::cout << questions[i] << "\n";
		std::cout << "*********************************\n";

		for (int j = 0; j < sizeof(options[0]) / sizeof(options[0][0]); j++) {
			std::cout << options[i][j] << std::endl;
		}

		std::cout << "Your answer: ";
		std::cin >> guess;
		guess = toupper(guess);

		while (guess != 'A' && guess != 'B' && guess != 'C' && guess != 'D') {
				
			std::cout << "\nYou have to choose between these letters: A , B , C , D\n";
			std::cout << "Your answer: ";
			std::cin >> guess;
			guess = toupper(guess);

		}

		if (answers[i] == guess) {
			std::cout << "\nCORRECT\n";
			score++;
		}
		else {
			std::cout << "\nWRONG\nAnswer is: " << answers[i] << std::endl;
		}

	}

	std::cout << "\n*********************************\n";
	std::cout << "*            RESULTS            *\n";
	std::cout << "*********************************\n";
	std::cout << "CORRECT ANSWERS: " << score << std::endl;
	std::cout << "NUMBER OF QUESTIONS: " << questionsSize << std::endl;
	std::cout << "SCORE: " << (double)score / questionsSize * 100 << "%\n";

}


