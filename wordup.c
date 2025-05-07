//Shabane Zubair
//Date: 4/21/25
//Project 10

#include <stdio.h>

char prompt_user (char userGuesses[], int guessAttempts);
void lower_case_guess (char userGuesses[], int guessAttempts);
char checkValidity (char userGuesses[], int guessAttempts);
char checkGuess (char userGuesses[], char guessWord[]);

int main () {
	char guessWord[6] = "sound";
	char userGuesses[5];
	//char wrongSpot[2][5];
	//char displayGuess[6];
	int guessAttempts;
	
	prompt_user (userGuesses, guessAttempts);
	checkGuess (userGuesses, guessWord);
	
	return 0;
}

char prompt_user (char userGuesses[], int guessAttempts) {
	guessAttempts++;
	
	if(guessAttempts > 6) {
		return 0;
	}
	
	printf("GUESS %d! Enter your guess: ", guessAttempts);
	fgets(userGuesses, 100, stdin);
	
	lower_case_guess (userGuesses, guessAttempts);
}

//converts any capital words in the user input to lowercase using ASCII table which has the lowercase version of each letter 32 places away from the capital version
void lower_case_guess (char userGuesses[], int guessAttempts) {
	for(int i = 0; i < 100; i++) {
		if(userGuesses[i] >= 'A' && userGuesses[i] <= 'Z') {
			userGuesses[i] = userGuesses[i] + 32;
		}
	}
	
	checkValidity(userGuesses, guessAttempts);
}

char checkValidity (char userGuesses[], int guessAttempts) {
printf(userGuesses);
	
	int isLetter = 1;
	int isFive = 0;
		
	for(int i = 0; userGuesses[i] != '\0'; i++) {
		isFive++;
		
		if(!(userGuesses[i] >= 'a' && userGuesses[i] <= 'z')) {
			isLetter = 0;
		}
	}
	
	if(isLetter == 0 && isFive != 5) {
		printf("Your guess must be 5 letters long.Your guess must contain only letters.\n");
		return prompt_user (userGuesses, guessAttempts);
	}
	else if(isFive != 5) {		
		printf("Your guess must be 5 letters long.\n");
		return prompt_user (userGuesses, guessAttempts);
	}
	else {
		return 0;
	}	
}

char checkGuess (char userGuesses[], int guessAttempts, char guessWord[]) {
	int count;
	
	for(int i = 0; i < 5; i++) {
		if(userGuesses[i] == guessWord[i]) {
			count++;	
		}
		else {
			printf("You lost, better luck next time!");
			return 0;
		}
	}
	
	if(guessAttempts == 6 && count != 5) {
		printf("You lost, better luck next time!");
		return 0;	
	}
	else {
		
	}
}
