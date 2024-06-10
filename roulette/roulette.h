#ifndef ROULETTE_H
#define ROULETTE_H

#include <iostream>
#include "player.h"
using namespace std;

#pragma once
/**
 * Handles a game of Roulette.
 * 
*/
class Roulette {
    int bet;
    int pot;
    Player player;
    int rolledNumber;

    public:
        Roulette(string name = "George Smith");

        void setBet();

        int getBet();

        int spin();
};

#endif
