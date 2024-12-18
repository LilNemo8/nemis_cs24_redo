#include "Errors.h"
#include <cctype>
#include <istream>
#include "Move.h"

// Space for implementing Move functions.


// The constructor parses a string.
Move::Move(const std::string& input){
    //check whitespace 
    if(input.length() < 6|| !std::isspace(input[1]) || !std::isspace(input[3])){ throw ParseError("ParseError, Invalid Move."); }

    number = input[0] - '0';
    if(1 > number || number > 9){throw ParseError("Parse error, Invalid Number."); }

    player = toupper(input[2]);
    if(player != 'X' && player != 'O'){  throw ParseError("Parse error, Invalid Player."); }

    row = (toupper(input[4]) - '0') - 17;
    if(row < 0 || row > 2) { throw ParseError("Parse error, Invalid Row."); }

    column = input[5] - '0';
    if(column < 1 || column > 3){ throw ParseError("Parse error, Invalid Column."); }

    //check for comment 
    size_t strLen = input.length();
    if((strLen - 6 >= 2) && !isspace(input[6])){ throw ParseError("Parse error, Invalid Comment."); }

};

// Helper to render a Move as text.
std::string Move::to_string() const{
    std::string result;
    result += number; 
    result += ' ';
    result += player;
    result += ' ';
    result += row;
    result += column;

    return result;

};