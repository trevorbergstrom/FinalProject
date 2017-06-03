//
//  Board.hpp
//  FinalProject
//
//  Created by Trevor Bergstrom on 5/30/17.
//  Copyright © 2017 Trevor Bergstrom. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <fstream>
#include "Line.hpp"
#include <stdlib.h>
#include "Player.hpp"
#include "Wall.hpp"

using std::string;
using std::getline;

class Board {
private:
    int rowNum;
    int colNum;
    Line *top;
    Line *bottom;
    Player* p;
    Space *center;
    
public:
    Board(int);
    Board(int, int);
    void printBoard();
    void getFileData(string);
    void setCenter();
    void writeCenter();
    void boardChecker();
    void setPlayer();
    
    void setCenterWithPtrs();
};
#endif /* Board_hpp */
