#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
using namespace std;

#pragma once
class Player {
    public:
        string name;
        Player(string name = "George Smith", int balance = 100);

        void setName(string name);

        void setBalance(int balance);

        void updateBalance(int balance);

        void printName();
    private:
        int balance;
};

#endif
