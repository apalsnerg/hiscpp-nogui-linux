#include <iostream>
#include <string>
#include "player.h"
using namespace std;

Player::Player(string playerName, int playerBalance) {
    name = playerName;
    balance = playerBalance;
}

void Player::promptName() {
    cout << "What is your name?" << "\n" << ">> ";
    string newName;
    getline(cin, newName);
    name = newName;
}

void Player::setName(string newName) {
    name = newName;
}

void Player::setBalance(int newBalance) {
    balance = newBalance;
}

void Player::reduceBalance(int newBalance) {
    balance -= newBalance;
}

void Player::printName() {
    cout << "Your name is " << name << "\n";
}

int Player::getBalance() {
    return balance;
}