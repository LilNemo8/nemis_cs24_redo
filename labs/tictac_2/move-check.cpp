#include "Errors.h"
#include "Move.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main(int argc, char** argv) {

  std::vector<std::pair<std::string, std::string>> files = {
  {"bad-line", "FAIL"}, {"bad-move", "FAIL"}, {"draw", "SUCCESS"},
  {"new-game", "SUCCESS"}, {"o-wins", "SUCCESS"}, {"os-wins", "SUCCESS"}, {"os-turn", "SUCCESS"},
  {"x-wins", "SUCCESS"}, {"xs-turn", "SUCCESS"}
  };

  size_t indexTest = 2;
  std::string route = "data/" + files[indexTest].first + ".ttt";
  std::cout << "Testing: " << route << " | Expected Result: " << files[indexTest].second << '\n';

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
