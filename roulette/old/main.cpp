#include <iostream>
#include <string>
#include "roulette.h"
#include "player.h"
using namespace std;

int main() {
    Roulette roulette;
    bool playing = true;
    roulette.intro();
    roulette.configPlayerName();
    Player player = roulette.getPlayer();
    cout << "Welcome, " << player.getName() << "!" << "\n";
    cout << "Your starting balance is " << player.getBalance() << "kr." << "\n" << "The allowed bets are 100kr, 350kr, and 500kr." << "\n";

    cout << "First, let me explain how this program works to you." << "\n\n";
    roulette.printRules();

    cout << "Great! Now we're ready to begin." << endl;

    roulette.gameLoop();
    return 1;
}
