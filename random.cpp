#include <iostream>
using namespace std;

/**
 * Evaluates whether the guess was correct.
 * 
 * @param randomNumber the number that is to be guessed
 * @return whether the game should continue, stop, or restart.
*/
string evalGuess(int randomNumber) {
    string response;
    cin >> response;
    int responseInt;
    try {
        responseInt = stoi(response);
    } catch (std::invalid_argument) {
        cout << "Not a valid number! Try again!" << "\n";
        return "continue";
    }
    
    if (responseInt < randomNumber) {
        cout << "Too low!" << "\n";
    } else if (responseInt > randomNumber) {
        cout << "Too high!" << "\n";
    }  else {
        cout << "Correct! The number was " << response << "!\n";
        cout << "Want to play again? yes/<any key>" << "\n";
        string inpt;
        cin >> inpt;

        if (inpt == "yes") {
            return "restart";
        }
        return "quit";
    }
    return "continue";
}

/**
 * Generates a random number between 1 and 100.
 * 
 * @return the random number
*/
int randOneToOneHundred() {
    return rand() % 100 + 1;
}

/**
 * Prints the introductory prompt of the game to terminal.
*/
void gamePrompt() {
    cout << "\n" << "Let's play a guessing game!" << "\n";
    cout << "I'll think of a number, and you guess what it is." << "\n";
}

int main() {
    string userInput;
    int randomNumber = randOneToOneHundred();
    gamePrompt();
    while (userInput != "quit") {
        userInput = evalGuess(randomNumber);
        if (userInput == "restart") {
            randomNumber = randOneToOneHundred();
            gamePrompt();
        }
    }
    cout << "Bye bye! Hope you had fun :D" << "\n";
}
