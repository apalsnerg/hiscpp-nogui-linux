#include <iostream>
#include <string>
#include "player.h"

using namespace std;

Player::Player() {
}

int Player::getBalance() {
    return balance;
}

void Player::setBalance(int newBal) {
    balance = newBal;
}

void Player::updateBalance(int balChange) {
    balance += balChange;
}

void Player::setName(string newName) {
    name = newName;
}

string Player::getName() {
    return name;
}