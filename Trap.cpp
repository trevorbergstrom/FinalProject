//
//  Trap.cpp
//  FinalProject
//
//  Created by Trevor Bergstrom on 6/2/17.
//  Copyright © 2017 Trevor Bergstrom. All rights reserved.
//

#include "Trap.hpp"

Trap::Trap() : Space() {
    typ = trap;
    iD = ' ';
    
}


Space* Trap::interact(Space* current, Player* me) {
    return this;
}

