#ifndef FIBVEC_H
#define FIBVEC_H

// This provides the size_t type:
#include <cstddef>
#include <iostream>

class FibVec {
  // Member Variables
  int* arr;
  size_t mCapacity;
  size_t mCount;
  size_t fib_num;

  // Helper Functions

  //Fibonacci Function
  size_t fib(size_t n) {
    if(n <= 1) { return n; }
    return fib(n - 1) + fib(n - 2);
  }

  void expandArr(){
    fib_num++;
    mCapacity = fib(fib_num);

    int* temp = new int[mCapacity];

    for(size_t i = 0 ; i < mCount; i++){
      temp[i] = arr[i];
    }

    delete [] arr;
    arr = temp;
  };

  void shrinkArr(){
    //check to make sure 
    if( (fib_num-2 < 2) && fib(fib_num-2) <= mCount){ return; }

    fib_num--;
    mCapacity = fib(fib_num);

    int* temp = new int[mCapacity];
    for(size_t i = 0 ; i < mCount; i++){
      temp[i] = arr[i];
    } 

    delete [] arr;
    arr = temp;

  };


public:
  // Constructor and Destructor
  FibVec();
  FibVec(const FibVec& other);
  ~FibVec();

  // Member Functions
  size_t capacity() const;
  size_t count() const;

  int lookup(size_t index) const;
  bool isEmpty();
  void print() const;

  int pop();
  void push(int value);

  void insert(int value, size_t index);
  int remove(size_t index);

  void clear();


};

#endif
