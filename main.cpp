#include <iostream>
#include <string>
#include "Chess.h"

using namespace std;

int main()
{

    Chess c;
    string board[8][8];
    string piece;
    
    // Calling functions
    c.chessPiecePlacements(board);
    
    cout << "Which piece would you like to move? or enter 'e' to exit the game" << endl;
    cout << " p - pawn\n r - rook\n n - knight\n b - bishop\n Q - Queen\n K - King\n e - exit game\n" << endl;
    cin >> piece;
    
        while (piece != "e") {
            if (piece == "p") {
                c.movePawn(board);
                cout << endl;
            } else if (piece == "r") {
                c.moveRook(board);
                cout << endl;
            } else if (piece == "n") {
                c.moveKnight(board);
                cout << endl;
            } else if (piece == "b") {
                c.moveBishop(board);
                cout << endl;
            } else if (piece == "Q") {
                c.moveQueen(board);
                cout << endl;
            } else if (piece == "K") {
                c.moveKing(board);
                cout << endl;
            }
            
            cout << "Which piece would you like to move? or enter 'e' to end the game" << endl;
            c.chessPiecePlacements(board);
            cout << " p - pawn\n r - rook\n n - knight\n b - bishop\n Q - Queen\n K - King\n e - exit game\n"<< endl;
            cin >> piece;
            
            
        }
        
    return 0;
}