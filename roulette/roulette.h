#ifndef ROULETTE_H
#define ROULETTE_H

#include <iostream>
#include <map>
#include <vector>
#include "player.h"
#include "util.h"

using namespace std;

#pragma once
/**
 * Handles a game of Roulette.
 * 
*/
class Roulette {

    public:
        Roulette(string name = "George Smith");

        void setBet();

        void setPot(int);

        int getPot();

        int getBet();

        int spin();

        void setMinBet(int);

        int getMinBet();

        void setMaxBet(int);

        int getMaxBet();

        int evalWin(int);

        void initGame();

        void printRules();

        void showPlayingField();

        Player getPlayer();

        void printComs();

        void gameLoop();

        vector<string> evalSpin(string);

        string evalInput(string);

        bool isInDozen(int chosenDozen, int rolledNumber);

        bool isInLine(int chosenLine, int rolledNumber);

        bool isInColumn(int chosenColumn, int rolledNumber);

        bool isInCorner(int chosenCorner, int rolledNumber);

        bool isHighOrLow(string chosenHighOrLow, int rolledNumber);

    private:    
        int bet;
        int pot = 10000;
        int minBet = 1;
        int maxBet = 100;
        Player player;
        int rolledNumber;
        int playingField[3][4][3];
};

#endif
