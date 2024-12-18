#include "FibVec.h"

// This provides exception types:
#include <stdexcept>


// FibVec Function Implementations


// Constructor and Destructor
FibVec::FibVec(){
    fib_num = 2;
    mCapacity = fib(fib_num);
    mCount = 0;
    arr = new int[mCapacity];
};

FibVec::FibVec(const FibVec& other){
    this->mCount = other.mCount;
    this->mCapacity = other.mCapacity;
    this->fib_num = other.fib_num;

    this->arr = new int[mCapacity];
    for(size_t i = 0; i < mCount; i++){
        this->arr[i] = other.arr[i];
    }

};


FibVec::~FibVec(){
    delete [] arr;
};

// Member Functions
size_t FibVec::capacity() const{ return mCapacity; };
size_t FibVec::count() const{ return mCount; };

int FibVec::lookup(size_t index) const{
    if(index >= mCount){ throw std::out_of_range("Invalid Index"); }
    return arr[index];
};

bool FibVec::isEmpty(){ return mCount == 0; }

void FibVec::print() const{
    if(!mCount){ throw std::underflow_error("Array is Empty."); return;}

    std::cout << '[';   
    for(size_t i = 0 ; i < mCount; i++){
        std::cout<< arr[i]; 
        if(i != mCount-1 ){ std::cout<< ", "; }
    }
    std::cout << "]\n";   
    
};

int FibVec::pop(){
    if(mCount == 0){ throw std::underflow_error("Array is Empty"); }
    mCount--;
    shrinkArr();
    return arr[mCount];
};

void FibVec::push(int value){
    if(mCount == mCapacity){ expandArr(); }
    arr[mCount] = value;
    mCount++;
};

void FibVec::insert(int value, size_t index){
    if(index > mCount){ throw std::out_of_range("Invalid Index."); }
    if(mCount == mCapacity){ expandArr(); }

    if(index == mCount){ 
        arr[index] = value; 
        return;
    }else{
        int* temp = new int[mCapacity];

        for(size_t i = 0; i < index; i++){ temp[i] = arr[i]; }
        temp[index] = value;
        for(size_t j = index + 1; j <= mCount; j++){ temp[j] = arr[j-1]; }
        
        delete [] arr;
        arr = temp;
        mCount++;
    
    }
};
int FibVec::remove(size_t index){
    if(index >= mCount){ throw std::out_of_range("Invalid Index."); }
    int* temp = new int[mCapacity];

    size_t tracker_index = 0;
    int removedVal = arr[index];

    for (size_t i = 0; i < mCount - 1; i++) {
        if (tracker_index == index) { tracker_index++; } 
        temp[i] = arr[tracker_index++];
    }

    delete[] arr; 
    arr = temp;   
    mCount--; 

    shrinkArr();
    return removedVal;
};


void FibVec::clear(){
    if(isEmpty()){ return; }

    delete [] arr;
    arr = new int[mCapacity];
    mCount=0;
}
