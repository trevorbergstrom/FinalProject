//
//  Line.hpp
//  FinalProject
//
//  Created by Trevor Bergstrom on 5/30/17.
//  Copyright © 2017 Trevor Bergstrom. All rights reserved.
//

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>
#include "Space.hpp"
#include "EmptySpace.hpp"

class Line {
private:
    Space *start;
    Space *end;
    Line *above;
    Line *below;
    int length;
    
public:
    Line() {};
    Line(int);
    Space* getStart() {return start;}
    Line* getBelow() {return below;}
    void setAbove(Line *a) {above = a;}
    void setBelow(Line *b) {below = b;}
    void printLine();
    void linkLines(Line*);
    
};
#endif /* Line_hpp */
