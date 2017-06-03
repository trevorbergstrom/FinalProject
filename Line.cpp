//
//  Line.cpp
//  FinalProject
//
//  Created by Trevor Bergstrom on 5/30/17.
//  Copyright © 2017 Trevor Bergstrom. All rights reserved.
//

#include "Line.hpp"

Line::Line(int size) {
    above = nullptr;
    below = nullptr;
    length = size;
    
    for (int i = 0; i < size; i++) {
        Space *nwsp = new EmptySpace();
        if (start == nullptr) {
            start = nwsp;
            end = nwsp;
        } else {
            nwsp->setLeft(end);
            end->setRight(nwsp);
            end = nwsp;
        }
    }
}

void Line::printLine() {
    Space* prnt = start;
    while (prnt != nullptr) {
        cout << prnt->getID();
        prnt = prnt->getRight();
    }
    cout << '\n';
    delete prnt;
}

void Line::linkLines(Line *linkee) {
    for(int i = 0; i < length; i++) {
        Space *s = this->getStart();
        Space *l = linkee->getStart();
        
        while(s != nullptr) {
            s->setDown(l);
            l->setUp(s);
            s = s->getRight();
            l = l->getRight();
        }
        delete s;
        delete l;
    }
}
