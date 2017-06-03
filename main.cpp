//
//  main.cpp
//  FinalProject
//
//  Created by Trevor Bergstrom on 5/30/17.
//  Copyright © 2017 Trevor Bergstrom. All rights reserved.
//

#include <iostream>
#include "Board.hpp"
#include <stdlib.h>


int main() {
    srand (time(NULL));
    Board *b = new Board(10,10);
    b->printBoard();
    
    cout << '\n';
    
    b->getFileData("test.txt");
    b->printBoard();
    
    cout << '\n';
    
    b->setPlayer();
    
    
}

