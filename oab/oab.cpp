#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include "player.h"
#include "oab.h"

#pragma once

using namespace std;

OneArmedBandit::OneArmedBandit() {
}

vector<vector<char>> OneArmedBandit::spinAll() {
    vector<vector<char>> rolledField;
    for (int i = 0; i < 3; i++) {
        vector<char> row = spinRow();
        rolledField.push_back(row);
        for (int j = 0; j < 3; j++) {
            cout << rolledField[i][j];
        }
        sleep(1);
        cout << "\n";
    }
    return rolledField;
}

vector<char> OneArmedBandit::spinRow() {
    srand(time(0));
    vector<char> row;
    row.push_back(possibleChars[rand() % 2]);
    row.push_back(possibleChars[rand() % 2]);
    row.push_back(possibleChars[rand() % 2]);
    rolledField.push_back(row);
    return row;
}

int OneArmedBandit::setBet(int) {

} 

int OneArmedBandit::getBet(int) {

}

int OneArmedBandit::winningRows() {
    for (int i = 0; i < 3; i++) {

        if (rolledField[i][i])
    }
}

/**
 * Evaluates the rows of the playingfield to see if any are winning.
 * 
 * @returns the amount of winning rows
 */
int OneArmedBandit::evalRows() {
    int winningRows = 0;
    /*
     * For every row, see if the characters at 0, 1, and 2 are the same
     * If they are, increase winningRows by 1.
     */
    for (int i = 0; i < 3; i++) {
        if (playingField[i][0] == playingfield[i][1] == playingField[i][2]) {
            winningRows += 1;
        }
    }
    return winningRows;
}

/**
 * Evaluates the columns of the playingfield to see if any are winning.
 * 
 * @returns the amount of winning columns
 */
int oneArmedBandit::evalCols() {
    int winningColumns = 0;
    /*
     * For the ith character of the first, second, and third sub-array
     * I.e. for [0][0], [1][0], [2][0]; [0][1], [1][1], [2][1], et.c.
     */
    for (int i = 0; i < 3; i++) {
        if (playingField[0][i] == playingField[1][i] == playingField[2][i]) {
            winningColumns += 1;
        }
    }
    return winningColumns;
}

vector<char> OneArmedBandit::getPossibleChars() {
    return possibleChars;
}

vector<vector<char>> OneArmedBandit::getRolledField() {
    return rolledField;
}

Player OneArmedBandit::getPlayer() {
    return player;
}

void OneArmedBandit::setPlayer() {

}

void OneArmedBandit::printRolledField() {
    
}

int OneArmedBandit::gameloop() {
    while (true) {
        string input;
        getline(cin, input);
        cout << "Your input was: " << input << "\n";
        cout << "Here's some random rolls:" << "\n";
        spinAll();
    }
    return 0;
}