#include "Errors.h"
#include "Board.h"
#include <iostream>

// Space for implementing Board functions.


Board::Board(){
    board = initializeBoard();
    currentPlayer = 0;
    currentTurn = 1;
};
Board::~Board(){
    for(size_t i = 0; i < 3; i++){ delete [] board[i]; }
    delete [] board;
};

void Board::enforceGameRules(Move& move){
    if(currentTurn != move.number){ throw InvalidMove("Invalid Move, Invalid Turn."); }
    if(!isEmptySpace(move.row, move.column)){ throw InvalidMove("Invalid Move, Occupied Space.");}

    if(currentTurn == 1){ currentPlayer = move.player; }
    else if(currentPlayer != move.player){ throw InvalidMove("Invalid Move, Wrong Player Turn."); }

    currentTurn++;
};

void Board::inputLocation(Move& move){
    board[move.row][move.column] = move.player;
};


void Board::inputMove(std::string& input){
    Move move(input);
    move.column = move.column-1;

    enforceGameRules(move);
    inputLocation(move);
    switchPlayer();
};


char Board::getNextPlayer() const{ return currentPlayer; };
int Board::getCurrentTurn() const{ return currentTurn; };


bool Board::checkRow(){
    for(size_t i = 0 ; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != '*'){return true;}
    }
    return false;
};
bool Board::checkCol(){
    for(size_t i = 0 ; i < 3; i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != '*'){return true;}
    }
    return false;
};
bool Board::checkDiagonal(){
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != '*'){return true;}
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != '*'){return true;}
    return false;
};

bool Board::checkWin(){
    if(currentTurn > 3 && (checkCol() || checkDiagonal() || checkRow())){ return true; }
    return false;
};


std::string Board::to_string(){
    std::string result;

    result += "    1   2   3\n";
    for(size_t i = 0 ; i < 3; i++){
        result += char(i+65);
        result += "   ";
        for(size_t j = 0 ; j < 3; j++){
            result += board[i][j]; 
            if(j!=2) result += " | ";
        }
        result += "\n";
        if(i!=2) result +="   ---+---+---\n";
    }
    result += '\n';

    return result;
};
