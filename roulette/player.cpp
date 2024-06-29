#include <iostream>
#include <string>
#include "player.h"
using namespace std;

Player::Player(string playerName, int playerBalance) {
    name = playerName;
    balance = playerBalance;
}

void Player::promptName() {
    string newName;
    getline(cin, newName);
    if (newName == "" || newName == " ") {
        name = "John Doe";
    }
    name = newName;
}

void Player::setName(string newName) {
    name = newName;
}

void Player::setBalance(int newBalance) {
    balance = newBalance;
}

void Player::increaseBalance(int incAmnt) {
    balance += incAmnt;
}

void Player::reduceBalance(int rdcAmnt) {
    balance -= rdcAmnt;
}

void Player::printName() {
    cout << "Your name is " << name << "\n";
}

int Player::getBalance() {
    return balance;
}