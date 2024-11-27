#include "chessPiece.h"

chessPiece::chessPiece(int pieceX, int pieceY, string pieceName){
        x = pieceX;
        y = pieceY;
        name = pieceName;
    }
    int chessPiece::getX(){
        return x;
    };
    int chessPiece::getY(){
        return y;
    };
    string chessPiece::getName(){
        return name;
    };
    void chessPiece::setX(int x2){
        x = x2;
    };
    void chessPiece::setY(int y2){
        y = y2;
    };
    void chessPiece::setName(string name2){
        name = name2;
    };
