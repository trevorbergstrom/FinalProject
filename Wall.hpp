//
//  Wall.hpp
//  FinalProject
//
//  Created by Trevor Bergstrom on 6/2/17.
//  Copyright © 2017 Trevor Bergstrom. All rights reserved.
//

#ifndef Wall_hpp
#define Wall_hpp

#include <stdio.h>
#include "Space.hpp"

class Wall : public Space {
private:
    
public:
    Wall();
    Space* interact(Space*, Player*);
};
#endif /* Wall_hpp */
