//
//  EmptySpace.hpp
//  FinalProject
//
//  Created by Trevor Bergstrom on 6/2/17.
//  Copyright © 2017 Trevor Bergstrom. All rights reserved.
//

#ifndef EmptySpace_hpp
#define EmptySpace_hpp

#include <stdio.h>
#include "Space.hpp"

class EmptySpace : public Space {
public:
    EmptySpace();
    Space* interact(Space*, Player*);
};
#endif /* EmptySpace_hpp */
