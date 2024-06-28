#include <iostream>
#include "roulette.h"
#include "player.h"
#include "gameinit.h"
using namespace std;

int main() {
    Roulette roulette;
    Player player = roulette.getPlayer();
    bool playing = true;
    player.promptName();
    cout << "Welcome, " << player.name << "!" << "\n";
    cout << "Your starting balance is 200kr. The pot is 10000kr. The minimum bet is 1kr, and the maximum bet 100kr." << "\n";
    cout << "Would you like to configure these settings? (Y/n)" << "\n" << ">> ";
    string answer;
    cin >> answer;
    if (answer == "Y" || answer == "y") {
        roulette.initGame();
    }

    cout << "Are you familiar with the rules of roulette already? (Y/n)" << "\n";
    string yesNo;
    cin >> yesNo;
    if (yesNo == "N" || yesNo == "n") {
        roulette.printRules();
    }

    cout << "Great! Now we're ready to begin." << "\n";

    roulette.gameLoop();
    return 1;
}
