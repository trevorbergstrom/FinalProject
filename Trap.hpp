//
//  Trap.hpp
//  FinalProject
//
//  Created by Trevor Bergstrom on 6/2/17.
//  Copyright © 2017 Trevor Bergstrom. All rights reserved.
//

#ifndef Trap_hpp
#define Trap_hpp

#include <stdio.h>
#include "Space.hpp"

class Trap : public Space {
private:
    Trap* partner;
public:
    Trap();
    Space* interact(Space*, Player*);
    
};
#endif /* Trap_hpp */
