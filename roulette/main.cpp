#include <iostream>
#include <string>
#include "roulette.h"
#include "player.h"
using namespace std;

int main() {
    Roulette roulette;
    Player player = roulette.getPlayer();
    bool playing = true;
    roulette.intro();
    player.promptName();
    cout << "Welcome, " << player.name << "!" << "\n";
    cout << "Your starting balance is " << player.getBalance() << "kr." << "\n" << "The allowed bets are 100kr, 350kr, and 500kr." << "\n";
    cout << "Would you like to configure these settings? (Y/n)" << "\n" << ">> ";
    string answer;
    cin >> answer;
    if (answer == "Y" || answer == "y") {
        roulette.configuration();
    }

    cout << "First, let me explain how this program works to you." << "\n\n";
    roulette.printRules();

    cout << "Great! Now we're ready to begin." << endl;

    roulette.gameLoop();
    return 1;
}
