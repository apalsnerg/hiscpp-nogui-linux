#include <iostream>
#include <string>
#include "oab.h"
#include "player.h"

using namespace std;

int main() {
    cout << "Welcome to the One-Armed Bandit!" << "\n";
    cout << "The rules are simple. You spin the slot machine, and for every row that has the same character, you win!" << "\n";

    OneArmedBandit oab;
    oab.gameloop();
}