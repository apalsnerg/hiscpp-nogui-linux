#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

#pragma once
class Player {
    public:
        string name;

        Player(string name = "George Smith", int balance = 100);

        void promptName();

        void setName(string name);

        void setBalance(int balance);

        int getBalance();

        void reduceBalance(int balance);

        void printName();
    private:
        int balance;
};

#endif
