#include "Chess.h"
#include <iostream>
#include <string>

using namespace std;

// Creates Board and piece placement
void Chess::createBoard(string boardArray[][COLS])   {
    // Empty spaces
    for (int r = 0; r < ROWS; r++)  {
        for (int c = 0; c < COLS; c++)  {
            boardArray[r][c] = "[ ]";
        }
    }
    
    cout << "   a  b  c  d  e  f  g  h\n";
    for (int r = 0; r < ROWS; r++)  {
        if((r+1) < 10)  {
            cout << (r + 1) << " ";
        }else{
            cout << (r + 1);
        }
        for (int c = 0; c < COLS; c++)  {
            cout << boardArray[r][c] << "";
        }
        cout << endl;
    }
    
}

// Places pieces
void Chess::chessPiecePlacements(string boardArray[][COLS]) {
// Empty spaces
    for (int r = 0; r < ROWS; r++)  {
        for (int c = 0; c < COLS; c++)  {
            boardArray[r][c] = "[ ]";
        }
    }
    
    for (chessPiece cp : pieceList){
        boardArray[cp.getX()][cp.getY()] = cp.getName();
    }
    
    cout << "   a  b  c  d  e  f  g  h\n";
    for (int r = 0; r < ROWS; r++)  {
        if((r+1) < 10)  {
            cout << (r + 1) << " ";
        }else{
            cout << (r + 1);
        }
        for (int c = 0; c < COLS; c++)  {
            cout << boardArray[r][c] << "";
        }
        cout << endl;
    }
    
}
// ******************** PAWN *********************************
void Chess::movePawn(string boardArray[][COLS])    {
    
    int userRow, userCol;
    cout << "You chose pawn." << endl;
    cout << "Legal moves for a pawn: " << endl;
    
    for (chessPiece p : pieceList) {
        if (p.getName() == "[p]" && p.getX() < ROWS - 1 && boardArray[p.getX() + 1][p.getY()] == "[ ]")
            boardArray[p.getX() + 1][p.getY()] = "[X]";
    }
    
    cout << "   a  b  c  d  e  f  g  h\n";
    for (int r = 0; r < ROWS; r++)  {
        if((r+1) < 10)  {
            cout << (r + 1) << " ";
        }else{
            cout << (r + 1);
        }
        for (int c = 0; c < COLS; c++)  {
            cout << boardArray[r][c] << "";
            if (boardArray[r][c]!= "[X]" && boardArray[r][c] != "[p]")    {
                //boardArray[r][c] = "[ ]";
            }
        }
        
        cout << endl;
    }
    cout << "Enter a row and column to move a pawn: " << endl;
    cin >> userRow >> userCol;
    userRow--;
    userCol--;
    if (userRow >= 0 && userRow < ROWS && userCol >= 0 && userCol < COLS && boardArray[userRow][userCol] == "[X]")
    for(chessPiece& p : pieceList) {
        // down
        if (p.getName() == "[p]" && p.getX() == userRow - 1 && p.getY() == userCol) {
            boardArray[p.getX()][p.getY()] = "[ ]";
            p.setX(userRow);
            p.setY(userCol);
            boardArray[p.getX()][p.getY()] = p.getName();
            
        }
    }else {
        cout << "Not a valid move!" << endl;
    }
    cout << endl;
}
//******************************************************************************
// ******************************* ROOK ************************************
void Chess::moveRook(string boardArray[][COLS]) {
    
    int userRow, userCol;
    cout << "You chose rook." << endl;
    cout << "Legal moves for a rook: " << endl;
    int rRow, rCol;
    
    chessPiece rook1 = chessPiece(1,1,"?");
    bool rook1Found = false;
    chessPiece rook2 = chessPiece(1,1,"?");
    
    for(chessPiece p : pieceList){
        if(p.getName() == "[r]"){
            if(!rook1Found) {
                rook1 = p;
                rook1Found = true;
            } else{
                rook2 = p;
            }
        }
    }
    
    
    cout << "Which rook would you like to move? ('" << rook1.getX() + 1 << " " << rook1.getY() + 1 <<
         "' for rook 1, '"<< rook2.getX() + 1 << " " << rook2.getY() + 1 << "' for rook 2)" << endl;
    cin >> rRow >> rCol;
    rRow--;
    rCol--;
    
    for (chessPiece r : pieceList) {
        if ((r.getName() == "[r]" && r.getX() == rRow && r.getY() == rCol)){
            cout << "Piece found." << endl;
            for (int i = 1; i <= 7; ++i) {
                if (r.getX() + i < ROWS && boardArray[r.getX()][r.getY()] == "[ ]")
                    boardArray[r.getX() + i][r.getY()] = "[X]";
            }
        }
    }
    
    cout << "   a  b  c  d  e  f  g  h\n";
    for (int r = 0; r < ROWS; r++) {
        if ((r + 1) < 10) {
            cout << (r + 1) << " ";
        } else {
            cout << (r + 1);
        }
        for (int c = 0; c < COLS; c++) {
            cout << boardArray[r][c] << "";
        }
        cout << endl;
    }
    
    cout << "Enter a row and column to move a rook: " << endl;
    cin >> userRow >> userCol;
    userRow--;
    userCol--;
    
    if (userRow >= 0 && userRow < ROWS && userCol >= 0 && userCol < COLS && boardArray[userRow][userCol] == "[X]")
        for(chessPiece& r : pieceList) {
            if ((r.getName() == "[r]" && rRow == r.getX() && rCol == r.getY())) {
                boardArray[rRow][rCol] = "[ ]";
                r.setX(userRow);
                r.setY(userCol);
                boardArray[r.getX()][r.getY()] = r.getName();
            }
        }
    cout << endl;
}
// **************************************************************************
// ******************** KNIGHT *********************
void Chess::moveKnight(string boardArray[][COLS]) {
    
    cout << "You chose knight." << endl;
    cout << "Legal moves for a knight: " << endl;
    
    for (chessPiece n : pieceList)  {
        if (n.getName() == "[n]")   {
            // Legal moves for knight
            if (n.getX() + 2 < COLS && n.getY() + 1 < ROWS && boardArray[n.getX() + 2][n.getY() + 1] == "[ ]")
                boardArray[n.getX() + 2][n.getY() + 1] = "[X]";
            if (n.getX() + 2 < COLS && n.getY() - 1 >= 0 && boardArray[n.getX() + 2][n.getY() - 1] == "[ ]")
                boardArray[n.getX() + 2][n.getY() - 1] = "[X]";
            if (n.getX() + 1 < COLS && n.getY() + 2 < ROWS && boardArray[n.getX() + 1][n.getY() + 2] == "[ ]")
                boardArray[n.getX() + 1][n.getY() + 2] = "[X]";
            if (n.getX() + 1 < COLS && n.getY() - 2 >= 0 && boardArray[n.getX() + 1][n.getY() - 2] == "[ ]")
                boardArray[n.getX() + 1][n.getY() - 2] = "[X]";
            if (n.getX() - 2 >= 0 && n.getY() - 1 >= 0 && boardArray[n.getX() - 2][n.getY() - 1] == "[ ]")
                boardArray[n.getX() - 2][n.getY() - 1] = "[X]";
            if (n.getX() - 2 >= 0 && n.getY() + 1 < COLS && boardArray[n.getX() - 2][n.getY() + 1] == "[ ]")
                boardArray[n.getX() - 2][n.getY() + 1] = "[X]";
            if (n.getX() - 1 >= 0 && n.getY() - 2 >= 0 && boardArray[n.getX() - 1][n.getY() - 2] == "[ ]")
                boardArray[n.getX() - 1][n.getY() - 2] = "[X]";
            if (n.getX() - 1 >= 0 && n.getY() + 2 < COLS && boardArray[n.getX() - 1][n.getY() + 2] == "[ ]")
                boardArray[n.getX() - 1][n.getY() + 2] = "[X]";
        }
    }
    
    cout << "   a  b  c  d  e  f  g  h\n";
    for (int r = 0; r < ROWS; r++)  {
        if((r+1) < 10)  {
            cout << (r + 1) << " ";
        }else{
            cout << (r + 1);
        }
        for (int c = 0; c < COLS; c++)  {
            cout << boardArray[r][c] << "";
        }
        cout << endl;
    }
    
    int userRow, userCol;
    
    cout << "Enter a row and column to move a knight: " << endl;
    cin >> userRow >> userCol;
    
    for (chessPiece& n : pieceList) {
        if (n.getName() == "[n]") {
            if ((n.getX() == userRow - 3 && n.getY() == userCol - 2)
                ||  (n.getX() == userRow - 3 && n.getY() == userCol)
                ||  (n.getX() == userRow + 1 && n.getY() == userCol - 2)
                ||  (n.getX() == userRow + 1 && n.getY() == userCol)
                ||  (n.getX() == userRow - 2 && n.getY() == userCol - 3)
                ||  (n.getX() == userRow - 2 && n.getY() == userCol + 1)
                ||  (n.getX() == userRow && n.getY() == userCol - 3)
                ||  (n.getX() == userRow && n.getY() == userCol + 1)){
                boardArray[n.getX()][n.getY()] = "[ ]";
                n.setX(userRow - 1);
                n.setY(userCol - 1);
                boardArray[n.getX()][n.getY()] = n.getName();
            }
        }
    }
    cout << endl;
}
// *********************************************************************************
// ****************************** BISHOP *******************************************
void Chess::moveBishop(string boardArray[][COLS]) {
    cout << "You chose bishop." << endl;
    cout << "Legal moves for a bishop: " << endl;
    int userRow, userCol;
    int bRow, bCol;
    
    chessPiece bishop1 = chessPiece(1,3,"?");
    bool bishop1Found = false;
    chessPiece bishop2 = chessPiece(1,6,"?");
    
    for(chessPiece p : pieceList){
        if(p.getName() == "[b]"){
            if(!bishop1Found) {
                bishop1 = p;
                bishop1Found = true;
            } else{
                bishop2 = p;
            }
        }
    }
    
    cout << "Which bishop would you like to move? ('" << bishop1.getX() + 1 << " " << bishop1.getY() + 1 <<
         "' for bishop 1, '"<< bishop2.getX() + 1 << " " << bishop2.getY() + 1 << "' for bishop 2)" << endl;
    cin >> bRow >> bCol;
    bRow--;
    bCol--;
    
    for (chessPiece b : pieceList)  {
        if ((b.getName() == "[b]" && b.getX() == bRow && b.getY() == bCol))    {
            for (int l = 1; l <= 7; l++)    {
                if (b.getX() + l < ROWS && b.getY() - l >= 0 && boardArray[b.getX() + l][b.getY() - l] == "[ ]")
                    boardArray[b.getX() + l][b.getY() - l] = "[X]"; // diagonal left
            }
            for (int l = 1; l <= 7; l++)    {
                if (b.getX() + l < ROWS && b.getY() + l < COLS && boardArray[b.getX() + l][b.getY() + l] == "[ ]")
                    boardArray[b.getX() + l][b.getY() + l] = "[X]"; // diagonal right
            }
            for (int l = 1; l <= 7; l++)    {
                if (b.getX() - l >= 0 && b.getY() - l >= 0 && boardArray[b.getX() - l][b.getY() - l] == "[ ]")
                    boardArray[b.getX() - l][b.getY() - l] = "[X]"; // diagonal left
            }
            for (int l = 1; l <= 7; l++)    {
                if (b.getX() - l >= 0 && b.getY() + l < COLS && boardArray[b.getX() - l][b.getY() + l] == "[ ]")
                    boardArray[b.getX() - l][b.getY() + l] = "[X]"; // diagonal right
            }
            
        }
        
    }
    
    cout << "   a  b  c  d  e  f  g  h\n";
    for (int r = 0; r < ROWS; r++)  {
        if((r+1) < 10)  {
            cout << (r + 1) << " ";
        }else{
            cout << (r + 1);
        }
        for (int c = 0; c < COLS; c++)  {
            cout << boardArray[r][c] << "";
        }
        cout << endl;
    }
    
    cout << "Enter a row and column to move the bishop: " << endl;
    cin >> userRow >> userCol;
    userRow--;
    userCol--;
    if (userRow >= 0 && userRow < ROWS && userCol >= 0 && userCol < COLS && boardArray[userRow][userCol] == "[X]")
        for (chessPiece& b : pieceList) {
            if ((b.getName() == "[b]" && bRow == b.getX() && bCol == b.getY()))  {
                boardArray[bRow][bCol] = "[ ]";
                b.setX(userRow);
                b.setY(userCol);
                boardArray[b.getX()][b.getY()] = b.getName();
            }
        }
    
    cout << endl;
}
// ********************************************************************************************************************
// *************************** QUEEN ******************************
void Chess::moveQueen(string boardArray[][COLS])    {
    int userRow, userCol;
    cout << "You chose Queen." << endl;
    cout << "Legal moves for the Queen: " << endl;
    
    for (chessPiece q : pieceList)  {
        if (q.getName() == "[Q]")   {
            
            for (int i = 1; i <= 7; i++) {
                if (q.getX() + i < ROWS && boardArray[q.getX() + i][q.getY()] == "[ ]")
                    boardArray[q.getX() + i][q.getY()] = "[X]"; // down
                else
                    i = 7;
            }
            for (int k = 1; k <= 7; ++k) {
                if (q.getY() + k < COLS && boardArray[q.getX()][q.getY() + k] == "[ ]")
                    boardArray[q.getX()][q.getY() + k] = "[X]"; // right
            }
            
            for (int k = 1; k <=7; k++) {
                if (q.getY() - k >= 0 && boardArray[q.getX()][q.getY() - k] == "[ ]")
                    boardArray[q.getX()][q.getY() - k] = "[X]"; // left
            }
            
            for (int l = 1; l <= 7; l++)    {
                if (q.getX() + l < ROWS && q.getY() - l >= 0 && boardArray[q.getX() + l][q.getY() - l] == "[ ]")
                    boardArray[q.getX() + l][q.getY() - l] = "[X]"; // diagonal left
            }
            for (int l = 1; l <= 7; l++)    {
                if (q.getX() + l < ROWS && q.getY() + l < COLS && boardArray[q.getX() + l][q.getY() + l] == "[ ]")
                    boardArray[q.getX() + l][q.getY() + l] = "[X]"; // diagonal right
            }
            
        }
    }
    
    cout << "   a  b  c  d  e  f  g  h\n";
    for (int r = 0; r < ROWS; r++)  {
        if((r+1) < 10)  {
            cout << (r + 1) << " ";
        }else{
            cout << (r + 1);
        }
        for (int c = 0; c < COLS; c++)  {
            cout << boardArray[r][c] << "";
        }
        cout << endl;
    }
    
    cout << "Enter a row and column to move the Queen: " << endl;
    cin >> userRow >> userCol;
    userRow--;
    userCol--;
    if (userRow >= 0 && userRow < ROWS && userCol >= 0 && userCol < COLS && boardArray[userRow][userCol] == "[X]")
        for (chessPiece& q : pieceList) {
            if (q.getName() == "[Q]") {
                
                boardArray[q.getX()][q.getY()] = "[ ]";
                q.setX(userRow);
                q.setY(userCol);
                boardArray[q.getX()][q.getY()] = q.getName();
            }
        }
    cout << endl;
}
// ********************************************************************************************************
// ********************************* KING **********************************
void Chess::moveKing(string boardArray[][COLS])   {
    int userRow, userCol;
    cout << "You chose King." << endl;
    cout << "Legal moves for the King: " << endl;
    
    for (chessPiece k : pieceList) {
        if (k.getName() == "[K]") {
            // legal moves for King
            if (k.getX() + 1 < ROWS)
                boardArray[k.getX() + 1][k.getY()] = "[X]"; // down
            if (k.getY() - 1 >= 0)
                boardArray[k.getX()][k.getY() - 1] = "[X]"; // left
            if (k.getY() + 1 <= COLS)
                boardArray[k.getX()][k.getY() + 1] = "[X]"; // right
            if (k.getX() + 1 < ROWS && k.getY() - 1 >= 0)
                boardArray[k.getX() + 1][k.getY() - 1] = "[X]"; // diagonal left
            if (k.getX() + 1 < ROWS && k.getY() + 1 < COLS)
                boardArray[k.getX() + 1][k.getY() + 1] = "[X]"; // diagonal right
            if (k.getX() - 1 >= 0 && k.getY() - 1 >= 0)
                boardArray[k.getX() - 1][k.getY() - 1] = "[X]"; // back left
            if (k.getX() - 1 >= 0)
                boardArray[k.getX() - 1][k.getY()] = "[X]"; // back
            if (k.getX() - 1 >= 0 && k.getY() + 1 < COLS)
                boardArray[k.getX() - 1][k.getY() + 1] = "[X]"; // back right
        }
    }
    
    //for (chessPiece k : pieceList) {
      //  if (k.getName() == "[K]")
        //    boardArray[k.getX()][k.getY()] = k.getName();
    //}
    
    cout << "   a  b  c  d  e  f  g  h\n";
    for (int r = 0; r < ROWS; r++)  {
        if((r+1) < 10)  {
            cout << (r + 1) << " ";
        }else{
            cout << (r + 1);
        }
        for (int c = 0; c < COLS; c++)  {
            cout << boardArray[r][c] << "";
            if (boardArray[r][c]!= "[X]" && boardArray[r][c] != "[K]")    {
            }
        }
        cout << endl;
    }
    
    cout << "Enter a row and column to move the King: " << endl;
    cin >> userRow >> userCol;
    userRow--;
    userCol--;
    if (userRow >= 0 && userRow < ROWS && userCol >= 0 && userCol < COLS && boardArray[userRow][userCol] == "[X]")
        for(chessPiece& k : pieceList){
            if (k.getName() == "[K]") {
                boardArray[k.getX()][k.getY()] = "[ ]";
                k.setX(userRow);
                k.setY(userCol);
                boardArray[k.getX()][k.getY()] = k.getName();
                
            }
        }
    
    cout << endl;
}