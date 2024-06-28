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


Roulette::Roulette(string name) {
    if (name != "") {
        player = Player(name);
    } else {
        player = Player();
    }

    int playingField[3][4][3] = {
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

    int redNums[19] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36, 100};
    int blackNums[19] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35, 100};
}

void Roulette::setBet() {
    cout << "How much would you like to bet?" << "\n" << ">> ";
    cin >> bet;
}

int Roulette::getBet() {
    return bet;
}

int Roulette::spin() {
    return rand() % 37; // 0 to 36
}


void Roulette::setPot(int newPot) {
    pot = newPot;
}

int Roulette::getPot() {
    return pot;
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

void Roulette::initGame() {

    int newBalance;
    cout << "What would you like to set your starting balance to?" << "\n" << ">> ";
    cin >> newBalance;
    player.setBalance(newBalance);

    int newPot;
    cout << "What would you like to set the pot to?" << "\n" << ">> ";
    cin >> newPot;
    setPot(newPot);

    int newMinBet;
    cout << "What would you like to set the minimum bet to?" << "\n" << ">> ";
    cin >> newMinBet;
    setMinBet(newMinBet);

    int newMaxBet;
    cout << "What would you like to set the maximum bet to?" << "\n" << ">> ";
    cin >> newMaxBet;
    setMaxBet(newMaxBet);
}

void Roulette::printRules() {
    cout << "No problem. This might be a lot to take in, so you might have to read it twice. Let's go!" << "\n";
    cout << "You will be able to place a bet between " << minBet << " and " << maxBet << "." << "\n";
    cout << "You can bet on any number between 0 and 37. Odd numbers are red, even numbers are black." << "\n";
    cout << "You will be able to enter a variety of commands depending on what you want to do." << "\n";
    
    printComs();
}

void Roulette::printComs() {
    cout << "Enter 'help' at any time to show this list" << "\n";
    cout << "Enter 'quit' at any time to end the game." << "\n";
    cout << "Enter 'bet' followed by a number to set your bet. Default 1kr." << "\n";
    cout << "Enter 'balance' to see your balance." << "\n";
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
    cout << "Enter 'spin' after setting your bet to spin the wheel." << "\n";

}

void Roulette::showPlayingField() {
    cout << playingField << "\n";
}

/**
 * Evaluates the numbers the user bet on and the spin and returns how much they won or lost
 * 
 * @param action the numbers the user bet on
 */
vector<string> Roulette::evalSpin(string userInput) {
    vector<string> usrInptVctr = strSplit(userInput);
    if (usrInptVctr.size() > 2) {
        cout << "Too many arguments! Please try again." << "\n";
        return {"none", 0};
    }
    int randNum = spin();
    cout << "Spinning the wheel..." << "\n";
    sleep(3);
    if (usrInptVctr[0] == "single") { // Could be done with a switch, but switching on a string is more complicated than a bunch of if-else
        int betNum = usrInptVctr[1];
        if (randNum == betNum) {
            string winStr = to_string(bet * 35);
            return {"win", winStr};
        } else {
            return {"lose", to_string(bet)};
        }
    } else if (usrInptVctr[0] == "split") {
        int betNum = usrInptVctr[1];
        if (randNum == betNum || randNum == betNum + 1) {
            string winStr = to_string(bet * 17);
            return {"win", winStr};
        } else {
            return{"lose", to_string(bet)};
        }
    } else if (usrInptVctr[0] == "street") {
        int betRow = usrInptVctr[1];
        if (isInStreet(betRow, randNum)) {
            string winStr = to_string(bet * 11);
            return {"win", winStr};
        } else {
            return {"lose", to_string(bet)};
        }
    } else if (usrInptVctr[0] == "corner") {
        int betNum = usrInptVctr[1];
        if (isInCorner(betNum, randNum)) {
        string winStr = to_string(bet * 8);
            return {"win", winStr};
        } else {
            return {"lose", to_string(bet)};
        }
    } else if (usrInptVctr[0] == "line") {
        int betNum = usrInptVctr[1];
        if (isInLine(betNum, randNum)) {
        string winStr = to_string(bet * 5);
            return {"win", winStr};
        } else {
            return {"lose", to_string(bet)};
        }
    } else if (usrInptVctr[0] == "dozen") {
        int betNum = usrInptVctr[1];
        if (isInDozen(betNum, randNum)) { 
            string winStr = to_string(bet * 35);
            return {"win", bet * 2};
        } else { 
            return {"lose", to_string(bet)};
        }
    } else if (usrInptVctr[0] == "column") {
        int betNum = usrInptVctr[1];
        if (isInColumn(betNum, randNum)) { 
        string winStr = to_string(bet * 2);
            return {"win", winStr};
        } else { 
            return {"lose", to_string(bet)};
        }
    } else if (usrInptVctr[0] == "colour" || usrInptVctr[0] == "color") {
        int betClr = usrInptVctr[1];
        if (find(col)) { 
        string winStr = to_string(bet * 2);
            return {"win", winStr};
        } else { 
            return {"lose", to_string(bet)};
        }
    } else if (usrInptVctr[0] == "high" || usrInptVctr[0] == "low") {
        string highOrLow = usrInptVctr[0];
        if (isHighOrLow(highOrLow, randNum)) {
            string winStr = to_string(bet * 2); 
            return {"win", winStr};
        } else { 
            return {"lose", to_string(bet)};
        }
    } else if {
        
    }
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
        "low",
        "ENDOFARRAY_ERROR_STR"
    };
    cout << userInput << endl;
    vector<string> usrInptVctr = strSplit(userInput);
    
    cout << 2 << endl;
    cout << usrInptVctr[0] << endl;
    if (usrInptVctr[0] == "balance" ) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    if (usrInptVctr[0] == "quit" || usrInptVctr[0] == "exit") {
        return "quit";
    } else if (usrInptVctr[0] == "balance") {
        cout << "Your balance is " << balance << "kr." << "\n";
        return "none";
    } else if (usrInptVctr[0] == "help") {
        printComs();
        return "none";
    } else if (find(validBets.begin(), validBets.end(), usrInptVctr[0]) == validBets.end()) {
        cout << '"' << usrInptVctr[0] << '"' << " is not a valid command. Please try again." << "\n";
        return "none";
    } else if (usrInptVctr[0] == "bet") {
        if (usrInptVctr.size() != 2) {
            cout << "Invalid argument amount." << "\n";
            return "none";
        }
        if (usrInptVctr[1] > maxBet || usrInptVctr[1] < minBet) {
            cout << "Your bet must be between " << minBet << "kr and " << maxBet << "kr." << "\n";
            return "none";
        } else if (usrInptVctr[1] > player.balance) {
            cout << "You don't have enough money to make that bet!" << "\n";
            return "none";
        }
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




void Roulette::gameLoop() {
    bool playing = true;
    while (playing) {
        string userInput;
        getline(cin, userInput);
        string action = evalInput(userInput);
        if (action == "quit") {
            playing = false;
        } else if (action == "none") {
            continue;
        } else if (action == "ok"){
            printComs();
        } else {
            vector<string, int> result = evalSpin(userInput);
        }
    }
}