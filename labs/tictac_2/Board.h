#ifndef BOARD_H
#define BOARD_H

#include "Move.h"
#include <exception>
#include <type_traits>

// I recommended writing a Board class to manage your game state.
// Here's some space for the class definition; member functions go in Board.cpp.

class Board{
    const static size_t turns = 9; 

    char** board;
    char currentPlayer;
    int currentTurn;
    std::string move_toString;

    char** initializeBoard(){
        char** temp = new char*[3];
        for(size_t i = 0 ; i < 3; i++){
            temp[i] = new char[3];
        }

        for(size_t i = 0 ; i < 3; i++){
            for(size_t j = 0 ; j < 3; j++){
                temp[i][j] = '*';
            }
        }
        return temp;
    }

    bool isEmptySpace(int& row, int& col){
        return board[row][col] == '*';
    };

    void switchPlayer(){
        if(currentPlayer == 'X'){ currentPlayer = 'O'; }
        else if(currentPlayer == 'O'){ currentPlayer = 'X'; }
    }

    public:
    Board();
    ~Board();

    void enforceGameRules(Move& move);
    void inputLocation(Move& move);
    void inputMove(std::string& input);


    char getNextPlayer() const;
    int getCurrentTurn() const;

    bool checkRow();
    bool checkCol();
    bool checkDiagonal();

    bool checkWin();

    std::string to_string();

};

#endif
