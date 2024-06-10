#include <iostream>
using namespace std;


string restartPrompt(int response) {
    cout << "Correct! The number was " << response << "!\n";
    cout << "Want to play again? yes/<any key>" << "\n" << ">> ";
    string inpt;
    cin >> inpt;

    if (inpt == "yes") {
        return "restart";
    }
    return "quit";
}

/**
 * Evaluates whether the guess was correct.
 * 
 * @param randomNumber the number that is to be guessed
 * @return whether the game should continue, stop, or restart.
*/
string evalGuess(int randomNumber) {
    string responseRaw;
    cin >> responseRaw;
    int response;
    try {
        response = stoi(responseRaw);
    } catch (std::invalid_argument) {
        cout << "Not a valid number! Try again!" << "\n" << ">> ";
        return "continue";
    }
    
    if (response < randomNumber) {
        cout << "Too low!" << "\n>>";
    } else if (response > randomNumber) {
        cout << "Too high!" << "\n>>";
    }  else {
        return restartPrompt(response);
    }
    return "continue";
}


string losePrompt(int correctNumber) {
    cout << "Sorry! You ran out of turns." << "\n";
    cout << "The correct number was " << correctNumber << "!\n";
    cout << "Want to play again? yes/<any key>" << "\n" << ">> ";
    string inpt;
    cin >> inpt;

    if (inpt == "yes") {
        return "restart";
    }
    return "quit";
}

/**
 * Reseeds the randomizer and generates a random number between 1 and 100.
 * 
 * @return the random number
*/
int randOneToOneHundred() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

int difficultySelect() {
    int turns;
    string difficulty;
    cin >> difficulty;
    if (difficulty == "yes") {
        cout << "How many turns would you like to be the limit?" << "\n" << ">> ";
        try {
            cin >> turns;
            cout << turns << " turns it is!" << "\n";
        } catch (std::invalid_argument) {
            turns = rand() % 10 + 4;
            cout << "Not a valid number. Let's go with " << turns << "." << "\n";
        }
    } else {
        cout << "I'll take that as a no." << "\n";
    }
    cout << "Alright, I've thought of my number, start guessing!" << "\n" << ">> ";
    return turns ?: 0;
}

/**
 * Prints the introductory prompt of the game to terminal.
*/
int gamePrompt() {
    cout << "\n" << "Let's play a guessing game!" << "\n";
    cout << "I'll think of a number, and you guess what it is." << "\n";
    cout << "Would you like to play with a limited number of guesses? yes/no" << "\n" << ">> ";
    bool hardmode = false;
    int turns = difficultySelect();
    return turns;
}

int main() {
    string userInput;
    int randomNumber = randOneToOneHundred();
    bool hardmode = false;
    int turns = gamePrompt();
    if (turns > 1) {
        hardmode = true;
    }

    while (userInput != "quit") {
        userInput = evalGuess(randomNumber);
        if (hardmode) {
            turns -= 1;
            if (turns == 0) {
                losePrompt(randomNumber);
            }
        }
        if (userInput == "restart") {
            randomNumber = randOneToOneHundred();
            turns = gamePrompt();
            hardmode = false;
            if (turns > 0) {
                hardmode = true;
            }
        }
    }
    cout << "Bye bye! Hope you had fun :D" << "\n";
}
