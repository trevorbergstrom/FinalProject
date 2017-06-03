//
//  Space.hpp
//  FinalProject
//
//  Created by Trevor Bergstrom on 5/30/17.
//  Copyright © 2017 Trevor Bergstrom. All rights reserved.
//

#ifndef Space_hpp
#define Space_hpp

#include <stdio.h>
#include <iostream>
#include "Player.hpp"

class Player;

using std::cout;
using std::endl;

enum stype {
    empty,
    wall,
    hole,
    chest,
    trap
};

class Space {
protected:
    Space *up;
    Space *down;
    Space *left;
    Space *right;
    char iD;
    stype typ;
    bool isSpecial;
public:
    Space();
    void setUp(Space *u) {up = u;}
    void setDown(Space *d) {down = d;}
    void setRight(Space *r) {right = r;}
    void setLeft(Space *l) {left = l;}
    Space* getRight() {return right;}
    Space* getUp() {return up;}
    Space* getDown() {return down;}
    Space* getLeft() {return left;}
    void setID(char c) {iD = c;}
    char getID() {return iD;}
    virtual Space* interact(Space*, Player*) = 0;
    virtual ~Space() {};
    
    
};
#endif /* Space_hpp */
