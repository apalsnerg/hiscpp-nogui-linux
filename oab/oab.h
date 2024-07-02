#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include "player.h"

#pragma once

using namespace std;

class OneArmedBandit {
    public:
        OneArmedBandit();

        vector<vector<char>> spinAll();

        vector<char> spinRow();

        int setBet(int);

        int getBet(int);

        int winningRows();

        
        int evalRows();

        /* evaluates and returns any winning columns */
        int evalColumns();

        vector<char> getPossibleChars();

        vector<vector<char>> getRolledField();

        Player getPlayer();

        void setPlayer();

        void printRolledField();

        int gameloop();

    private:
        vector<vector<char>> rolledField;
        vector<char> possibleChars = {'X', 'O', 'A'};
        int bet;
        Player player;

};
