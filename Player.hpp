

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Space.hpp"

class Space;

class Player {
private:
    Space *current;
    char iD;
    int strength;
public:
    Player();
    void move();
    void setCurrentSpace(Space*);
    Space* getCurSpace() { return current;}
};
#endif /* Player_hpp */
