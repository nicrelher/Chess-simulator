#ifndef CHESSPROJECT_CHESSPIECE_H
#define CHESSPROJECT_CHESSPIECE_H
#include <string>

using namespace std;
class chessPiece {

private:
    int x;
    int y;
    string name;

public:
    chessPiece(int, int, string);
    int getX();
    int getY();
    string getName();
    void setX(int);
    void setY(int);
    void setName(string);
};



#endif //CHESSPROJECT_CHESSPIECE_H
