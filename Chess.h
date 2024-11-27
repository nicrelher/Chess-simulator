#ifndef CHESS_H
#define CHESS_H

#include <string>
#include "chessPiece.h"

using namespace std;

class Chess {
private:

    static const int ROWS = 8;
    static const int COLS = 8;
    static const int PIECES = 6;
    string name;
    int size;
    chessPiece pieceList[16];
    


public:
    Chess() : pieceList{
                        {1,0,"[p]"},
                        {1,1,"[p]"},
                        {1,2,"[p]"},
                        {1,3,"[p]"},
                        {1,4,"[p]"},
                        {1,5,"[p]"},
                        {1,6,"[p]"},
                        {1,7,"[p]"},
                        {0,0,"[r]"},
                        {0,1,"[n]"},
                        {0,2,"[b]"},
                        {0,5,"[b]"},
                        {0,6,"[n]"},
                        {0,7,"[r]"},
                        {0,3,"[Q]"},
                        {0,4,"[K]"}} {
    }
    
    // Functions
    void createBoard(string boardArray[][COLS]);
    void chessPiecePlacements(string boardArray[][COLS]);
    void movePawn(string boardArray[][COLS]);
    void moveRook(string boardArray[][COLS]);
    void moveKnight(string boardArray[][COLS]);
    void moveBishop(string boardArray[][COLS]);
    void moveQueen(string boardArray[][COLS]);
    void moveKing(string boardArray[][COLS]);
    void newGame(string boardArray[][COLS]);

};
#endif