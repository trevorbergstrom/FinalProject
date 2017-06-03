//
//  EmptySpace.cpp
//  FinalProject
//
//  Created by Trevor Bergstrom on 6/2/17.
//  Copyright © 2017 Trevor Bergstrom. All rights reserved.
//

#include "EmptySpace.hpp"

EmptySpace::EmptySpace() : Space() {
    typ = empty;
    isSpecial = false;
    iD = ' ';
}

Space* EmptySpace::interact(Space* current, Player *me) {
    current->setID(' ');
    return this;
}
