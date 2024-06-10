#include <iostream>
#include "player.h"
using namespace std;

Player::Player(string playerName, int playerBalance) {
    name = playerName;
    balance = playerBalance;
}

void Player::setName(string newName) {
    cout << "What is your name?" << "\n" << ">> ";
    getline(cin, newName);
    name = newName;
}

void Player::setBalance(int newBalance) {
    balance = newBalance;
}

void Player::updateBalance(int newBalance) {
    balance -= newBalance;
}
void Player::printName() {
    cout << "Your name is " << name << "\n";
}