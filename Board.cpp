//
//  Board.cpp
//  FinalProject
//
//  Created by Trevor Bergstrom on 5/30/17.
//  Copyright © 2017 Trevor Bergstrom. All rights reserved.
//

#include "Board.hpp"

Board::Board(int length, int height) {
    top = nullptr;
    bottom = nullptr;
    center = nullptr;
    p = new Player();
    
    rowNum = height;
    colNum = length;
    
    for(int i = 0; i < rowNum; i++) {
        Line *nwln = new Line(colNum);
        if(top == nullptr) {
            top = nwln;
            bottom = nwln;
        } else {
            nwln->setAbove(bottom);
            bottom->setBelow(nwln);
            bottom->linkLines(nwln);
            bottom = nwln;
        }
    }
}

void Board::printBoard() {
    Line *nwlne = top;
    
    if (top == nullptr || top->getStart() == nullptr) {
        cout << "Empty board!" << endl;
    } else {
        while (nwlne != nullptr) {
            nwlne->printLine();
            nwlne = nwlne->getBelow();
        }
    }
    delete nwlne;
}

void Board::getFileData(string fileName) {
    std::fstream dataIn(fileName, std::ios::in);
    if(dataIn.fail()) {
        cout << "No board records exist" << endl;
    } else {
        string fileLine;
        Line *curLn = top;
        
        int lineIndex = 0;
        
        while(curLn != nullptr) {
            Space *curSp = curLn->getStart();
            getline(dataIn, fileLine, '\n');
            while(curSp != nullptr) {
                char c = fileLine.at(lineIndex);
                Space* cu = curSp->getUp();
                Space* cr = curSp->getRight();
                Space* cd = curSp->getDown();
                Space* cl = curSp->getLeft();
                
                if(c == '#') {
                    delete curSp;
                    curSp = new Wall();
                    curSp->setUp(cu);
                    curSp->setRight(cr);
                    curSp->setDown(cd);
                    curSp->setLeft(cl);
                }
                curSp->setID(c);
                curSp = curSp->getRight();
                lineIndex++;
            }
            lineIndex = 0;
            curLn = curLn->getBelow();
        }
    }
}

void Board::setCenter() {
    if(top == nullptr) {
        center = nullptr;
    } else {
        int x = colNum/2;
        int y = rowNum/2;
        
        Line *cLine = top;
        
        for(int i = 0; i < y; i++) {
            cLine = cLine->getBelow();
        }
        Space *cSpace = cLine->getStart();
        
        for(int j = 0; j < x; j++) {
            cSpace = cSpace->getRight();
        }
        
        center = cSpace;
    }
}

void Board::writeCenter() {
    center->setID('#');
}

void Board::setCenterWithPtrs() {
    if(top == nullptr) {
        center = nullptr;
    } else {
        Space *find = top->getStart();
        
        for(int i = 0; i < colNum/2; i++) {
            find = find->getRight();
        }
        for(int j = 0; j < rowNum/2; j++) {
            find = find->getDown();
        }
        center = find;
        delete find;
    }
}

void Board::setPlayer() {
    setCenterWithPtrs();
    p->setCurrentSpace(center);
    
    for(int i = 0; i < 10; i++) {
        p->move();
        printBoard();
    }
    
}

void Board::boardChecker() {
    Space* cur = top->getStart();

    int i = 0;
    while (i < 100) {
        int choice = rand() % 4;
        
        switch (choice) {
            case 1:
                if (cur->getUp() == nullptr) {
                    cur = cur->getDown();
                } else {
                    cur = cur->getUp();
                }
                cur->setID('#');
                break;
                
            case 2:
                if (cur->getRight() == nullptr) {
                    cur = cur->getLeft();
                } else {
                    cur = cur->getRight();
                }
                cur->setID('#');
                break;
            case 3:
                if (cur->getDown() == nullptr) {
                    cur = cur->getUp();
                } else {
                    cur = cur->getDown();
                }
                cur->setID('#');
                break;
            case 4:
                if (cur->getLeft() == nullptr) {
                    cur = cur->getRight();
                } else {
                    cur = cur->getLeft();
                }
                cur->setID('#');
                break;
        }
        printBoard();
        cout << '\n';
        i++;
    }
}

