#include <iostream>
#include <string>

#pragma once

using namespace std;

class Player {
    public:
        Player();

        int getBalance();
        
        void setBalance(int);

        void updateBalance(int);

        void setName(string);

        string getName();

    private:
        string name = "John Doe";
        int balance = 0;

};