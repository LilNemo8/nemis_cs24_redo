#include "Errors.h"
#include "Move.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main(int argc, char** argv) {

  std::vector<std::string> files = 
  {"bad-line", "bad-move", "draw",
  "new-game", "o-wins", "os-wins", "os-turn",
  "x-wins", "xs-turn"};


  std::string route = "data/" + files[0] + ".ttt";
  std::cout << "Testing: " << route << '\n';

  std::ifstream file(route); // Open the file
  if (!file) {
    std::cerr << "Error opening file." << std::endl;
    exit(1); // Exit if the file cannot be opened
  }else{
    std::string line;
    while (std::getline(file, line)) { // Read word by word
      try{
        Move move(line);
        std::cout << move.to_string() << '\n';
      }catch(const ParseError& e) {
        std::cout << e.what() << '\n';
        exit(1);
      }
    }
  }
      
  return 0;
}