#include <iostream>
#include "roulette.h"
#include "player.h"
using namespace std;

int main() {
    Roulette roulette;
    Player player;

    player.printName();
    player.setName("Erik Jonsson");
    player.printName();

    roulette.setBet();
    cout << roulette.getBet() << "\n";
    srand(time(NULL));
    cout << roulette.spin() << "\n";
    srand(time(NULL));
    return 1;
}
