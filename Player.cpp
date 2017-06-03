//
//  Player.cpp
//  FinalProject
//
//  Created by Trevor Bergstrom on 6/2/17.
//  Copyright © 2017 Trevor Bergstrom. All rights reserved.
//

#include "Player.hpp"

Player::Player() {
    current = nullptr;
    iD = 'x';
    strength = 100;
}

void Player::setCurrentSpace(Space *nwsp) {
    current = nwsp;
    current->setID(iD);
    
}

void Player::move() {
    cout << "Please enter your move" << endl;
    std::string entry;
    getline(std::cin, entry);
    char mov = entry.at(0);
    
    switch (mov) {
        case 'w':
            if(current->getUp() != nullptr) {
                current = current->getUp()->interact(current, this);
                current->setID(iD);
            } else {
                cout << "The way is blocked!" << endl;
            }
            
            break;
            
        case 'd':
            if(current->getRight() != nullptr) {
                current = current->getRight()->interact(current, this);
                current->setID(iD);
            } else {
                cout << "The way is blocked!" << endl;
            }
            break;
            
            case 's':
            if(current->getDown() != nullptr) {
                current = current->getDown()->interact(current, this);
                current->setID(iD);
            } else {
                cout << "The way is blocked!" << endl;
            }
            
            break;
            
            case 'a':
            if(current->getLeft() != nullptr) {
                current = current->getLeft()->interact(current, this);
                current->setID(iD);
            } else {
                cout << "The way is blocked!" << endl;
            }
            
            break;
    }
}
