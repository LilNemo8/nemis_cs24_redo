#include "FibVec.h"
#include <iostream>

// Use this file to test your FibVec class!
// This file won't be graded - do whatever you want.

int main() {
  FibVec fibvec;

  for(size_t i = 0; i < 10; i++){
    fibvec.push(i);
  }

  fibvec.print();


  fibvec.insert(10, 5);
  fibvec.print();

  FibVec fibvec2(fibvec);

  fibvec.remove(5);
  fibvec.print();



  fibvec2.print();

  fibvec2.clear();
  fibvec2.print();

  std::cout << fibvec2.isEmpty() << '\n';
  // std::cout << "This program doesn't do anything interesting yet...\n";

  return 0;
}
