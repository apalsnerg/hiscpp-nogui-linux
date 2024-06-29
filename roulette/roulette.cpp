#include <iostream>
#include <time.h>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <string>
#include "player.h"
#include "roulette.h"
#include "util.h"
using namespace std;


Roulette::Roulette(string name)  {
    if (name != "") {
        player = Player(name);
    } else {
        player = Player();
    }
}

int Roulette::playingField[3][4][3] =
{
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    },
    {
        {13, 14, 15},
        {16, 17, 18},
        {19, 20, 21},
        {22, 23, 24}
    },
    {
        {25, 26, 27},
        {28, 29, 30},
        {31, 32, 33},
        {34, 35, 36}
    }
};
vector<int> Roulette::redNums = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
vector<int> Roulette::blackNums = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};

void Roulette::setBet() {
    cout << "How much would you like to bet?" << "\n" << ">> ";
    try {
        cin >> bet;
    } catch (const invalid_argument& e) {
        cout << "You must enter a number." << "\n";
    }
}

int Roulette::getBet() {
    return bet;
}

void Roulette::betRelease() {
    bOverrideBetProtocol = true;
}

int Roulette::spin() {
    srand(time(0));
    return rand() % 37; // 0 to 36
}

Player Roulette::getPlayer() {
    return player;
}

void Roulette::setMinBet(int newMinBet) {
    minBet = newMinBet;
}

void Roulette::setMaxBet(int newMaxBet) {
    maxBet = newMaxBet;
}

void Roulette::configuration() {

    int newBalance;
    cout << "What would you like to set your starting balance to?" << "\n" << ">> ";
    cin >> newBalance;
    player.setBalance(newBalance);

    string response;
    cout << "Would you like to unshackle the allowed bets? (Y/n)" << "\n" << ">> ";
    cin >> response;
    if (response == "Y" || response == "y") {
        betRelease();
        string configResMax;
        cout << "Would you like to configure a maximum bet? (Y/n)" << "\n" << ">> ";
        cin >> configResMax;
        if (configResMax == "Y" || configResMax == "y") {
            cout << "Please enter a maximum bet." << "\n" << ">> ";
            int newMaxBet;
            try {
                cin >> newMaxBet;
                setMaxBet(newMaxBet);
            } catch (const invalid_argument& e) {
                cout << "Not a valid number. Defaulting to no maximum." << "\n";
            }
        }
        string configResMin;
        cout << "Would you like to configure a minimum bet? The default minimum bet is 100. (Y/n)" << "\n" << ">> ";
        cin >> configResMin;
        if (configResMin == "Y" || configResMin == "y") {
            cout << "Please enter a minimum bet." << "\n" << ">> ";
            int newMinBet;
            try {
                cin >> newMinBet;
                setMinBet(newMinBet);
            } catch (const invalid_argument& e) {
                cout << "Not a valid number. Defaulting to 100." << "\n";
            }
        }
    }
}

void Roulette::printRules() {
    cout << "This might be a lot to take in, so you might have to read it twice. Let's go!" << "\n";
    cout << "The Roulette table is divided into three dozens of four lines of three numbers, like this: " << "\n";
    showPlayingField();
    if (bOverrideBetProtocol) {
        cout << "You will be able to place a bet between " << minBet << " and " << maxBet << "." << "\n";
    } else {
        cout << "You will be able to bet 100kr, 350kr, and 500kr." << "\n";
    }
    cout << "On the Roulette table, odd numbers are black, and even numbers are red." << "\n";
    cout << "You will be able to enter a variety of commands depending on what you want to do. Here they are:" << "\n";
    
    printComs();
}

void Roulette::printComs() {
    cout << "Enter 'help' at any time to show this list" << "\n";
    cout << "Enter 'quit' at any time to end the game." << "\n";
    cout << "Enter 'bet' followed by a number to set your bet. Default 1kr." << "\n";
    cout << "Enter 'balance' to see your account balance." << "\n";
    cout << "-------------------------------" << "\n";
    cout << "The following are spinning commands. When you enter any of these, the wheel with spin." << "\n";
    cout << "Enter 'single' followed by a number to bet on that number. A win on single returns 35x your bet." << "\n";
    cout << "Enter 'split' followed by the lower of the two numbers you want to bet on. A win on split returns 17x your bet." << "\n";
    cout << "Enter 'street' followed by the number of the row to bet on those numbers. A win on street returns 11x your bet." << "\n";
    cout << "Enter 'corner' followed by the number at the top left of the square you want to bet on. A win on corner returns 8x your bet." << "\n";
    cout << "Enter 'line' followed by the first number of your desired line to bet on that line. A win on line returns 5x your bet." << "\n";
    cout << "Enter 'dozen' followed by the number of the dozen you want to bet on. A win on dozen returns 2x your bet." << "\n";
    cout << "Enter 'column' followed by the number of the column you want to bet on. A win on column returns 2x your bet." << "\n";
    cout << "Enter 'colour' followed by the colour you want to bet on. A win on colour returns 2x your bet." << "\n";
    cout << "Enter 'high' to bet the rolled number will be greater than 18. A win on high returns 1x your bet." << "\n";
    cout << "Enter 'low' to bet the rolled number will be less than 18. A win on low returns 1x your bet." << "\n";
    cout << "Enter 'even' to bet the rolled number will be even. A win on even returns 1x your bet." << "\n";
    cout << "Enter 'odd' to bet the rolled number will be odd. A win on odd returns 1x your bet." << "\n";
    cout << endl;
}

void Roulette::showPlayingField() {
    int lineCounter = 0;
    int dozenCounter = 1;
    cout << "+--------------+ [1]" << "\n";
    for (int i = 0; i < 3; i++) {
        dozenCounter += 1;
        for (int j = 0; j < 4; j++) {
            lineCounter += 1;
            for (int k = 0; k < 3; k++) {
                int curNum = playingField[i][j][k];
                cout << "| ";
                if (curNum < 10) { // Even spacing for the single-digit numbers as compared to the double-digit ones
                    cout << " ";
                }
                cout << curNum;
                cout << " ";
            }
            cout << "| " << lineCounter << endl;
        }
        if (dozenCounter < 4) {
            cout << "+--------------+ " << "[" << dozenCounter << "]" "\n";
        } else {
            cout << "+--------------+ " << "\n";
            cout << "  |1|  |2|  |3|" << "\n";
        }
    }
}

void Roulette::intro() {
    cout << "Welcome to Roulette!" << "\n";
    cout << "You will be playing with custom rules based on the European standard." << "\n";
    cout << "There will be 37 numbers in total, ranging from 0-36." << "\n";
    cout << "0 can only be used as a direct bet." << "\n";
    cout << "Black numbers are even, and red numbers are odd." << "\n";
    cout << "Now, please tell me what your name is!" << "\n" << ">> ";
}

/**
 * Evaluates the numbers the user bet on and the spin and returns how much they won or lost
 * 
 * @param action the numbers the user bet on
 * @returns a vector with the result of the bet and how much the player won or lost.
 */
vector<string> Roulette::evalSpin(string userInput) {
    vector<string> usrInptVctr = strSplit(userInput);
    
    if (bet == 0) {
        cout << "You need to set a bet first!" << "\n";
        return {"none", "0"};
    }
    if (usrInptVctr.size() < 2 && usrInptVctr[0] != "spin" && usrInptVctr[0] != "high" && usrInptVctr[0] != "low" && usrInptVctr[0] != "even" && usrInptVctr[0] != "odd") {
        if ((usrInptVctr[0] == "colour" || usrInptVctr[0] == "color")) {
            cout << "You need to specify a colour!" << "\n";
            return {"none", "0"};
        } else {
            cout << "You need to specify a number!" << "\n";
            return {"none", "0"};
        }
    }
    rolledNumber = spin();
    cout << "Spinning the wheel..." << "\n";
    sleep(3);
    /*
     * Here we evaluate the user's selected bet type. Could be done with a switch, but switching on a string is complicated.
     * Methods for checking whether the bet was successful are used where necessary; elsewhere just some basic logic is used.
     * 
     * On a win, "win" is return with the bet multiplied by the win factor. On a loss, "lose" is returned with just the bet.
     * This way, we can evaluate whether the user's balance should be increased or decreased (using the first value),
     * and how much it should be done so by (the second value) where we return in our game loop.
     */
    if (usrInptVctr[0] == "single") {
        int betNum = stoi(usrInptVctr[1]);
        if (rolledNumber == betNum) {
            return {"win", to_string(bet * 35)};
        } else {
            return {"lose", to_string(bet)};
        }
    } else if (usrInptVctr[0] == "split") {
        int betNum = stoi(usrInptVctr[1]);
        if (rolledNumber == betNum || rolledNumber == betNum + 1) {
            return {"win", to_string(bet * 17)};
        } else {
            return{"lose", to_string(bet)};
        }
    } else if (usrInptVctr[0] == "street") {
        int betRow = stoi(usrInptVctr[1]);
        if (isInStreet(betRow, rolledNumber)) {
            return {"win", to_string(bet * 11)};
        } else {
            return {"lose", to_string(bet)};
        }
    } else if (usrInptVctr[0] == "corner") {
        int betNum = stoi(usrInptVctr[1]);
        if (isInCorner(betNum, rolledNumber)) {
            return {"win", to_string(bet * 8)};
        } else {
            return {"lose", to_string(bet)};
        }
    } else if (usrInptVctr[0] == "line") {
        int betNum = stoi(usrInptVctr[1]);
        if (isInLine(betNum, rolledNumber)) {
            return {"win", to_string(bet * 5)};
        } else {
            return {"lose", to_string(bet)};
        }
    } else if (usrInptVctr[0] == "dozen") {
        int betNum = stoi(usrInptVctr[1]);
        if (isInDozen(betNum, rolledNumber)) { 
            return {"win", to_string(bet * 3)};
        } else {
            return {"lose", to_string(bet)};
        }
    } else if (usrInptVctr[0] == "column") {
        int betNum = stoi(usrInptVctr[1]);
        if (isInColumn(betNum, rolledNumber)) {
            return {"win", to_string(bet * 2)};
        } else {
            return {"lose", to_string(bet)};
        }
    } else if (usrInptVctr[0] == "colour" || usrInptVctr[0] == "color") {
        string betClr = usrInptVctr[1];
        if (betClr == "red" && trueFindInt(rolledNumber, redNums)) {
            return {"win", to_string(bet * 2)};
        } else if (betClr == "black" && trueFindInt(rolledNumber, blackNums)) {
            return {"win", to_string(bet * 2)};
        }
        return {"lose", to_string(bet)};
    } else if (usrInptVctr[0] == "high" || usrInptVctr[0] == "low") {
        string highOrLow = usrInptVctr[0];
        if (isHighOrLow(highOrLow, rolledNumber)) {
            return {"win", to_string(bet * 2)};
        } else {
            return {"lose", to_string(bet)};
        }
    }
    return {"none", 0};
}

string Roulette::evalInput(string userInput) {
    vector<string> validBets = {
        "single",
        "split",
        "street",
        "corner",
        "line",
        "dozen",
        "column",
        "colour",
        "color",
        "high",
        "low"
    };
    vector<string> usrInptVctr = strSplit(userInput);

    if (usrInptVctr[0] == "quit" || usrInptVctr[0] == "exit") {
        return "quit";
    } else if (usrInptVctr[0] == "balance") {
        cout << "Your balance is " << player.getBalance() << "kr." << "\n";
        return "none";
    } else if (usrInptVctr[0] == "help") {
        printComs();
        return "none";
    } else if (usrInptVctr[0] == "bet") {
        if (usrInptVctr.size() != 2) {
            cout << "You must enter a number to bet." << "\n";
            return "none";
        }
        if (stoi(usrInptVctr[1]) > player.getBalance()) {
            cout << "You don't have enough money to make that bet." << "\n";
            return "none";
        } else if (bOverrideBetProtocol && stoi(usrInptVctr[1]) < 1) {
            cout << "Your bet must be at least 1kr." << "\n";
            return "none";
        } else if (!trueFindInt(stoi(usrInptVctr[1]), allowedBets)) {
            cout << "Your bet must be either " << allowedBets[0] << "kr, " << allowedBets[1] << "kr, or " << allowedBets[2] << "kr." << "\n";
            return "none";
        }
        bet = stoi(usrInptVctr[1]);
        cout << "You have placed a bet of " << bet << "kr." << "\n";
        return "none";
    } else if (!trueFindStr(usrInptVctr[0], validBets)) {
        cout << '"' << usrInptVctr[0] << '"' << " is not a valid command. Please try again." << endl;
        return "none";
    }
    return "ok";
}

bool Roulette::isInDozen(int num, int rolled) {
    for (int i = 0; i < 4; i++) { // For every row
        for (int j = 0; j < 3; j++) { // For every number
            if (playingField[num][i][j] == rolled) {
                return true;
            }
        }
    }
    return false;
}

bool Roulette::isInStreet(int num, int rolled) {
    for (int i = 0; i < 3; i++) {
        if (playingField[i][num][0] == rolled || playingField[i][num][1] == rolled || playingField[i][num][2] == rolled) {
            return true;
        }
    }
    return false;
}

bool Roulette::isInLine(int num, int rolled) {
    for (int i = 0; i < 3; i++) { // For every dozen
        for (int j = 0; j < 3; j++) { // For every number
            if (playingField[i][num][j] == rolled || playingField[i][num + 1][j] == rolled) {
                return true;
            }
        }
    }
    return false;
}

bool Roulette::isInColumn(int num, int rolled) {
    for (int i = 0; i < 3; i++) { // For every dozen
        for (int j = 0; j < 4; j++) { // For every row
            if (playingField[i][j][num - 1] == rolled) { // If the number is in the chosen column (user will enter 1, 2, or 3 so we need to subtract 1)
                return true;
            }
        }
    }
    return false;
}

bool Roulette::isHighOrLow(string highOrLow, int rolled) {
    string rolledLevel = "high";
    if (rolled < 19) {
        rolledLevel = "low";
    }
    return (rolledLevel == highOrLow);
}

/**
 * Since every corner can be simplified to n, n+1, n+3, n+4, we don't need to check against the playingField, just do some arithmetic.
 * Visually, using 2 as our number:
 * {1, [2, 3]}
 * {4, [5, 6]}
 * {7, 8, 9}
 * The corner includes 3 (2 + 1), 5 (2 + 3), and 6 (2 + 4), Q.E.D.
 *
 * @param num the number to the top left of the corner
 * @param rolled the number generated randomly
 * 
 * @returns bool whether the rolled number is in the chosen corner
 */
bool Roulette::isInCorner(int num, int rolled) {
    vector<int> checkNums = {num, num+1, num+3, num+4};
    if (trueFindInt(rolled, checkNums)) {
        return true;
    }
    return false;
}

/**
 * The main loop for the game. Keeps going until the user enters the "quit" command.
 * 
 */
int Roulette::gameLoop() {
    bool playing = true;
    while (playing) {
        string action = "none";
        string userInput;
        getline(cin, userInput);
        if (userInput != "") { // If the user enters an empty line, do nothing
            action = evalInput(userInput);
        }
        if (action == "quit") { // If the user quits, exit the loop
            playing = false;
        } else if (action == "none") { // If the user inputs a nonsense command, do nothing
            continue;
        } else if (action == "help"){ // If the user needs help, print the available commands
            printComs();
        } else { // If the input evaluation passes, evaluate the spin the user desired
            vector<string> result = evalSpin(userInput);
            if (result[0] == "none") { // If the user inputted a nonsense command, do nothing; we do the appropriate cout in the evalSpin function
                continue;
            } else {
                cout << "The number rolled was: " << rolledNumber << "\n";
                if (result[0] == "win") {
                    cout << "You won! You earned " << result[1] << "kr!" << "\n";
                    player.increaseBalance(stoi(result[1]));
                    totalPayouts += stoi(result[1]);
                } else if (result[0] == "lose") {
                    cout << "Sorry, you lose! You lost your bet of " << result[1] << "kr." << "\n";
                    player.reduceBalance(stoi(result[1]));
                    totalPayouts -= stoi(result[1]);
                }
                bet = 0;
                cout << "Your new balance is: " << player.getBalance() << "kr." << "\n";
                cout << "Your total payout for this session is: " << totalPayouts << "kr." << "\n";
                cout << "Your total losses for this session are: " << totalLosses << "kr." << "\n";
                if (player.getBalance() == 0) {
                    cout << "Game over! You're out of money!" << "\n";
                    playing = false;
                }
            }
        }
    }
    cout << "Bye bye!" << endl;
    return 1;
}