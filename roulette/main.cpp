#include <iostream>
#include <string>
#include <unistd.h>
#include "util.h"

using namespace std;

/**
 * Prints some intro text with the rules
 */
void intro() {
    cout << "Welcome to Roulette!" << "\n";
    cout << "On the wheel there are 37 numbers, ranging from 1-36." << "\n";
    cout << "Black numbers are even, and red numbers are odd." << "\n";
    cout << "You will be able to bet on a number, or a colour." << "\n";
    cout << "If you lose, you will lose your bet." << "\n";
    cout << "If you win a number bet, you will receive your bet times ten." << "\n";
    cout << "If you win a colour bet, you will receive double your bet." << "\n";
    cout << "You can only bet 100kr, 300kr, or 500kr." << "\n";
    cout << "Your starting balance is 1000kr." << "\n";
    cout << "You may enter 'q' at any time to quit and withdraw your money." << "\n";
    cout << "That's it! Good luck and happy spinning!" << "\n";
    cout << "------------------------------------------------------------" << endl;
}

/**
 * Returns true if the generated number is in the colour the user bet on
 * 
 * @param number The generated number
 * @param colour The colour the user guessed the number would be
 * 
 * @return true if the generated number is in the colour the user bet on, else false
 */
bool checkNumberColour(int number, string colour) {
    if (colour == "red" && number % 2 == 1) {
        return true;
    } else if (colour == "black" && number % 2 == 0) {
        return true;
    }
    return false;
}


/**
 * Prompts the user for a bet and checks if it is valid
 * 
 * @param allowedBets An pointer to the array containing the allowed bets
 * @param balance A reference to the user's current balance
 * 
 * @return The user's bet, or 0 if the user wants to quit
 */
int promptBet(int (*allowedBets)[3], int& balance) {
    string bet;
    int betNumber = 0;
    cout << "\n" << "Please enter how much you would want to bet." << "\n";
    while (betNumber < 1) {
        cout << ">> ";
        // Try to interpret the user's input as a number
        try {
            cin >> bet;
            betNumber = stoi(bet);
            // If the number was not a valid bet
            if (!boolFindIntArray(betNumber, *allowedBets, 3)) {
                cout << "Not a valid bet. You may only bet " << allowedBets[0][1] << "kr, "
                     << allowedBets[1][1] << "kr, or " << allowedBets[2][1] << "kr. Please try again." << "\n";
                betNumber = 0;
                continue;
            }
            // If it was valid, but the user doesn't have that much money
            if (balance < betNumber) {
                cout << "Insufficient funds. Your current balance is: " << balance << "kr." << "\n";
                betNumber = 0;
                continue;
            }
        // If the input could not be interpreted as a number
        } catch (const invalid_argument& e) {
            if (bet == "q") {
                return 0;
            }
            cout << "Not a number! Try again." << "\n";
            // Clear the buffer so we can get a new input and avoid an infinite loop
            cin.clear();
            cin.ignore();
            continue;
        } catch (const out_of_range& e) {
            cout << "That number is too large! Try again." << "\n";
            cin.clear();
            cin.ignore();
            continue;
        }
    }
    // Decrease the player's balance by their bet
    balance -= betNumber;
    return betNumber;
}

/**
 * Prints some information and sleeps to ensure a new seed can be used,
 * then generates a random number between 1 and 36
 * 
 * @return The generated number
 */
int spin() {
    cout << "Spinning the wheel.";
    for (int i = 0; i < 3; i++) {
        // Flush so we can keep printing during the sleep
        cout << ".." << flush;
        sleep(1);
    }
    cout << "\n" << endl;
    // Set the seed to the current time after waiting 3 seconds
    srand(time(0));
    return rand() % 36 + 1;
}

/**
 * Prompts the user to enter a deposit until a valid number is entered
 * or the user quits with 'q'.
 * 
 * @param balanceRef A reference to the player's current balance
 */
void promptDeposit(int& balanceRef) {
    // Variable to store the input we're about to get
    string depositAmountStr;
    while (true) {
        // Try-catch block to catch whether the input was a valid number
        try {
            cout << "\n" << ">> " << "\n";
            cin >> depositAmountStr;
            int depositAmount = stoi(depositAmountStr);
            if (depositAmount < 100) {
                cout << "You must deposit at least 100kr." << "\n";
                continue;
            } else if (depositAmount > 5000) {
                cout << "You may only deposit 5000kr at a time." << "\n";
                continue;
            }
            balanceRef = depositAmount;
            break;
            // Input was not a number
        } catch (const invalid_argument& e) {
            // If the user enters an invalid input that was not 'q'
            if (depositAmountStr != "q") {
                cout << "Not a number! Try again." << "\n";
                // Clear the input buffer to prevent an infinite output loop
                cin.clear();
                cin.ignore();
                balanceRef = 0;
                continue;
            }
            // If 'q', exit the function
            balanceRef = 0;
            break;
        } catch (const out_of_range& e) { // Input was too large
            cout << "That number is too large! Try again." << "\n";
            cin.clear();
            cin.ignore();
            continue;
        }
    }
}

// An array containing the allowed numbers
const int allowedNumbers[36] = 
{
    1, 2, 3, 4, 5, 6,
    7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17,
    18, 19, 20, 21, 22,
    23, 24, 25, 26, 27,
    28, 29, 30, 31, 32,
    33, 34, 35, 36
};

// An array containing the allowed bets. The lowest allowed bet MUST always come first.
const int allowedBets[3] = {100, 300, 500};

// Reward multipliers for winning on a colour or number bet
constexpr clrBetMult = 2;
constexpr numBetMult = 10;

int main() {
    int bet = 0;
    int totalLosses = 0;
    int totalWins = 0;
    int balance = 1000;
    bool active = true;

    // Print intro text before the game begins
    intro();

    while(active) {

        bet = promptBet(&allowedBets, balance);
        //promptBet only returns 0 if the user wants to quit
        if (bet == 0) { 
            active = false;
            break;
        }

        cout << "You have bet " << bet << "kr." << "\n" << "\n";
        cout << "Please enter the colour or number you would like to bet on." << "\n" << ">> ";
        // Variable to store the input we're about to get
        string betSelection;
        int betNumber = 0;
        string betClr;
        // Variable to store the type of bet we determine the user selected
        string betType = "none";
        // Loop until a valid bet type is selected
        while (betType == "none") {
            cout << ">> ";
            cin >> betSelection;
            // Check if the user wants to quit and withdraw
            if (betSelection == "q") {
                balance += bet;
                active = false;
                betType = "exit";
                break;
            }
            // Try to interpret the input as a number and save it in betNumber
            try {
                betNumber = stoi(betSelection);
                int amountOfAllowed = allowedNumbers.size();
                // Check if the input is a valid number (an allowed bet)
                if (!boolFindInt(betNumber, allowedNumbers, amountOfAllowed)) { 
                    cout << "You may only bet on numbers" << allowedNumbers[0] << " through "
                         << allowedNumbers[amountOfAllowed] << "Please try again." << "\n";
                    continue;
                }
                // If it is a valid number, set betType to "number"
                betType = "number";
            } catch (const invalid_argument& e) { // Input was not a number
                if (betSelection != "red" && betSelection != "black") { // Check if the input is a valid colour
                    cout << "Not a valid input! Try again." << "\n";
                    continue;
                }
                // If it is a valid colour, save the colour that was betted and set bet type to "colour"
                betClr = betSelection; 
                betType = "colour";
            } catch (const out_of_range& e) { // Input was too large (2**31 - 1)
                cout << "That number is too large! Try again." << "\n";
                continue;
            }
        }
        cout << "\n";
        int generated = spin();
        cout << "The number rolled was " << generated << "..." << "\n";
        // If it was previously determined that the user bet on a colour
        if (betType == "colour") {
            // If it was the winning colour, you win!
            if (checkNumberColour(generated, betClr)) {
            cout << "...which is a " << betClr << " number!" << "\n";
            cout << "You win " << bet * clrBetMult << "kr!" << "\n";
            // Increase balance and total wins by the winning amount
            balance += bet * clrBetMult;
            totalWins += bet * clrBetMult;
            } else {
                // If it was not the winning colour, you lose :(
                cout << "...which is not a " << betClr << " number." << "\n";
                cout << "Sorry! You lost your bet of " << bet << "kr." << "\n";
                /* Increase total losses by the bet amount; we already subtracted the bet from the balance
                 * so we don't need to do that again
                 */
                totalLosses += bet;
            }
        // If it was previously determined that the user bet on a number
        } else if (betType == "number") {
            // If it was the winning number
            if (generated == betNumber) {
                cout << "...which was the number you bet on!";
                cout << "You win " << bet * numBetMult << "kr!" << "\n";
                // Increase balance and total wins
                balance += bet * numBetMult;
                totalWins += bet * numBetMult;
            } else {
                // If it was not
                cout << "...which was not the number you bet on." << "\n";
                cout << "Sorry! You lost your bet of " << bet << "kr." << "\n";
                // Increase losses
                totalLosses += bet;
            }
        }
        // Print the new balance and statistics for this game
        cout << "\n";
        cout << "New balance: " << balance << "kr" << "\n";
        cout << "Total payout: " << totalWins << "kr" << "\n";
        /*
         * It's not strictly necessary to print out the losses, but it's something folkhälsomyndigheten
         * would approve of, and though we want to make money, we'd also like people to be responsible.
         */
        cout << "Total losses: " << totalLosses << "kr" << "\n";
        // Prompt the user to deposit money if they have run out
        if (balance < allowedBets[0]) {
            cout << "You've run out of money. Enter a number if you'd like to deposit more, else enter any key to quit." << "\n";
            promptDeposit(balance);
        }
        // If the balance is still 0 after the user is prompted to deposit, i.e. if they did not, end the game
        if (balance < allowedBets[0]) {
            active = false;
        }
        cout << "------------------------------------------------------------" << endl;
    }
    // Print out a good-bye message and the user's withdrawn balance
    cout << "Thanks for playing!" << endl;
    cout << "Exiting and withdrawing " << balance << "kr. Good-bye!" << endl;
    // EXIT PROGRAM
    return 0;
}