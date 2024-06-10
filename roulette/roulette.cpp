#include <iostream>
#include <time.h>
#include "player.h"
#include "roulette.h"
using namespace std;


Roulette::Roulette(string name) {
    if (name != "") {
        player = Player(name);
    } else {
        player = Player();
    }
}

void Roulette::setBet() {
    cout << "How much would you like to bet?" << "\n" << ">> ";
    cin >> bet;
}

int Roulette::getBet() {
    return bet;
}

int Roulette::spin() {
    return rand() % 37; // 0 to 36
}
