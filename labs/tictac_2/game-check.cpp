#include "Board.h"
#include "Errors.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>


int main(){
  std::vector<std::pair<std::string, std::string>> files = {
  {"bad-line", "FAIL"}, {"bad-move", "FAIL"}, {"draw", "SUCCESS"},
  {"new-game", "SUCCESS"}, {"o-wins", "SUCCESS"}, {"os-wins", "SUCCESS"}, {"os-turn", "SUCCESS"},
  {"x-wins", "SUCCESS"}, {"xs-turn", "SUCCESS"}
  };

    size_t indexTest = 7;
    std::string route = "data/" + files[indexTest].first + ".ttt";
    std::cout << "Testing: " << route << " | Expected Result: " << files[indexTest].second << '\n';


    std::ifstream file(route); // Open the file

    if (!file) {
        std::cerr << "Error opening file." << std::endl;
        exit(1); // Exit if the file cannot be opened
    }

    Board board;
    std::string line;
    while (std::getline(file, line)) { // Read word by word
        try{
            board.inputMove(line);
            std::cout << board.to_string()<< '\n';

        }catch(const InvalidMove& e) {
            std::cout << e.what() << '\n';
            exit(1);
        }catch(const ParseError& e) {
            std::cout << e.what() << '\n';
            exit(1);
        }

        if(board.checkWin()){
            if(board.getNextPlayer() == 'O'){ std::cout<<"Game over: X wins.\n"; return 0; }
            if(board.getNextPlayer() == 'X'){ std::cout<<"Game over: O wins.\n"; return 0; }
        }

        if(board.getCurrentTurn() == 9){ std::cout<< "Game over: Draw.\n"; return 0; }
    }

    if(board.getCurrentTurn() == 1){std::cout<< "Game in progress: New game.\n"; return 0; }
    if(board.getNextPlayer() == 'X'){ std::cout<<"Game in progress: X's turn.\n"; return 0; }
    if(board.getNextPlayer() == 'O'){ std::cout<<"Game in progress: O's turn.\n"; return 0; }

}