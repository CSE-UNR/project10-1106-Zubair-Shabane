//Shabane Zubair
//Date: 4/21/25
//Project 10

#include <stdio.h>

char prompt_user (char userGuesses[], int guessAttempts);
void lower_case_guess (char userGuesses[], int guessAttempts);
char check_validity (char userGuesses[], int guessAttempts);
char check_guess (char userGuesses[], int guessAttempts, char guessWord[], char displayGuesses[], char guessHint[][6]);

int main () {
	char guessWord[6] = "sound";
	char userGuesses[6];
	char guessHint[2][6];
	char displayGuesses[6];
	int guessAttempts;
	
	prompt_user (userGuesses, guessAttempts);
	check_guess (userGuesses, guessAttempts, guessWord, displayGuesses, guessHint);
	
	printf("%c", displayGuesses);
	
	switch(guessAttempts) {
		case 1: 
			printf("You won in 1 guess!\nGOATED!");
			break;
		case 2:
			printf("You won in 2 guesses!\nAmazing!");
			break;
		case 3: 
			printf("You won in 3 guesses!\nAmazing!");
			break;
		case 4:
			printf("You won in 4 guesses!\nNice!");
			break;
		case 5: 
			printf("You won in 5 guesses!\nNice!");
			break;
		case 6:
			printf("You won in 6 guesses!\n");
			break;
	}
	
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
	
	check_validity(userGuesses, guessAttempts);
}

char check_validity (char userGuesses[], int guessAttempts) {
printf(userGuesses);
	
	int isLetter = 1;
	int isFive = 0;
		
	for(int i = 0; userGuesses[i] != '\0'; i++) {
		isFive++;
		if(!(userGuesses[i] >= 65 && userGuesses[i] <= 90)) {
			isLetter = 0;
		}
	}
	
	if(isLetter == 0 && isFive != 5) {
		printf("Your guess must be 5 letters long.Your guess must contain only letters.\n");
		prompt_user (userGuesses, guessAttempts);
	}
	else if(isFive != 5) {		
		printf("Your guess must be 5 letters long.\n");
		prompt_user (userGuesses, guessAttempts);
	}
	else {
		return 0;
	}	
}

char check_guess (char userGuesses[], int guessAttempts, char guessWord[], char displayGuesses[], char guessHint[][6]) {
	int count;
	
	for(int i = 0; i < 5; i++) {
		if(userGuesses[i] == guessWord[i]) {
			count++;
			displayGuesses[i] == userGuesses[i];
			guessHint[1][i] = guessWord[i] - 32;
		}
		else {
			for(int j = 0; j < 5; j++) {
				if(i != j && userGuesses[i] == guessWord[j]) {
					guessHint[1][i] = userGuesses[i];
					guessHint[2][i] = '^';
				}
			}
		}
	}
	
	printf("%c", guessHint);
	
	if(guessAttempts == 6 && count != 5) {
		printf("You lost, better luck next time!");
		return 0;	
	}
	else {
		//
	}
}

//char display_message (_) {

	//check number of guesses to get right answer then use switch case for congrats message or lose message
//	printf("You won in 1 guess!\n");
//	printf("GOATED!");
	
//	printf("You won in 2 guesses!\n");
//	printf("Amazing!");
	
//	printf("You won in 3 guesses!\n");
//	printf("Amazing!");
	
//	printf("You won in 4 guesses!\n");
//	printf("Nice!");
	
//	printf("You won in 5 guesses!\n");
//	printf("Nice!");
	
//	printf("You won in 6 guesses!\n");
	
//	printf("You lost, better luck next time!");
//}

//use file io with mystery.txt once everything else works
