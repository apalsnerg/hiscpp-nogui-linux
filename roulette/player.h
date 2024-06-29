#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

#pragma once
class Player {
    public:
        string name;

        Player(string name = "John Doe", int balance = 1000);

        void promptName();

        void setName(string);

        void setBalance(int);

        int getBalance();

        void increaseBalance(int);

        void reduceBalance(int);

        void printName();
    private:
        int balance;
};

#endif
