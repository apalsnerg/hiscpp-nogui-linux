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
 * Provides functionality for the Roulette game
 * 
*/
class Roulette {

    public:
        /** Constructor */
        Roulette(string name = "");

        /** Getter for the player of the game */
        Player getPlayer();

        /** Evaluates whether the user won on their selected spin */
        vector<string> evalSpin(string);

        /** Evaluates whether the user made a valid input */
        string evalInput(string);

        /** Sets the player's bet */
        void setBet();

        /** Sets the minimum bet allowed */
        void setMinBet(int);

        /** Sets the maximum bet allowed */
        void setMaxBet(int);

        /** Prompts the user to configure the settings of the game */
        void configuration();

        /** Prints the rules of the game, also invokes printComs */
        void printRules();

        /** Prints the playing field */
        void showPlayingField();

        /** Prints the possible ommands */
        void printComs();

        /** Allows the player to make any bet (above the minimum and not above their balance) */
        void betRelease();

        /** Prints intro text */
        void intro();

        /** Main game loop */
        int gameLoop();

        /** Getter for the minimum bet allowed */
        int getMinBet();

        /** Getter for the current bet amount */
        int getBet();

        /** Getter for the maximum bet allowed */
        int getMaxBet();

        /** Evaluates whether the player won on their spin */
        int evalWin(int);

        /** Spins the wheel (generates a random number) */
        int spin();

        /** Evaluates whether the random number is in the street the player chose */
        bool isInStreet(int chosenStreet, int rolledNumber);

        /** Evaluates whether the random number is in the dozen the player chose */
        bool isInDozen(int chosenDozen, int rolledNumber);

        /** Evaluates whether the random number is in the line the player chose */
        bool isInLine(int chosenLine, int rolledNumber);

        /** Evaluates whether the random number is in the column the player chose */
        bool isInColumn(int chosenColumn, int rolledNumber);

        /** Evaluates whether the random number is in the corner the player chose */
        bool isInCorner(int chosenCorner, int rolledNumber);

        /** Evaluates whether the player guessed whether the number would be high or low correctly */
        bool isHighOrLow(string chosenHighOrLow, int rolledNumber);

    private:
        /* List of allowed bets */
        vector<int> allowedBets = {100, 350, 500};

        /** whether the user can make any bet */
        bool bOverrideBetProtocol = false;

        /** all the numbers of that colour */
        static vector<int> redNums;
        static vector<int> blackNums;

        /** how much the user has won and lost this game */
        int totalPayouts;
        int totalLosses;

        /** the minimum and maximum possible bet (the lowest integer and the highest integer c++ can handle) */
        int minBet = 1;
        int maxBet = 2147483647;

        /** the current bet amount */
        int bet;

        /** the player of the game */
        Player player;

        /** the random number that the wheel has spun */
        int rolledNumber;

        /** the playing field as a 3D array */
        static int playingField[3][4][3];
};

#endif
