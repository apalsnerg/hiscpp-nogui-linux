#include <iostream>
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

        /** Prints the rules of the game, also invokes printComs */
        void printRules();

        /** Prints the playing field */
        void showPlayingField();

        /** Prints the possible ommands */
        void printComs();

        /** Prints intro text */
        void intro();

        /** Calls promptName() in the player instance */
        void configPlayerName();

        /** Main game loop */
        int gameLoop();

        /** Getter for the current bet amount */
        int getBet();

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

        /** Evaluates whether the player guessed whether the number would be red or black correctly */
        bool isRedOrBlack(string chosenRedOrBlack, int rolledNumber);

        /** Evaluates whether the player guessed whether the number would be odd or even correctly */
        bool isOddOrEven(string chosenOddOrEven, int rolledNumber);

        /** Evaluates whether the player guessed whether the number would be in the colour the player chose */
        bool isInColour(string chosenColour, int rolledNumber);

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

        /** the current bet amount */
        int bet;

        /** the player of the game */
        Player player;

        /** the random number that the wheel has spun */
        int rolledNumber;

        /** the playing field with and without dozens */
        static int playingField[3][4][3];
        static int playingFieldLines[12][3];
};
