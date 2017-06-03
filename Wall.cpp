//
//  Wall.cpp
//  FinalProject
//
//  Created by Trevor Bergstrom on 6/2/17.
//  Copyright © 2017 Trevor Bergstrom. All rights reserved.
//

#include "Wall.hpp"

Wall::Wall() : Space() {
    typ = wall;
    isSpecial = true;
    iD = '#';
}

Space* Wall::interact(Space* current, Player*) {
    cout << "The way is blocked" << endl;
    return current;
}
