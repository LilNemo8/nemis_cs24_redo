#include <iostream>
#include <string>

bool spaceCheck(char& c){
    if(c == ' '|| c == '\n' || c == '\t'){ return true; }
    return false;
}

void checkExcessSpace(std::string& text, int& i, int& j){
    if(spaceCheck(text[i]) && spaceCheck(text[j])){
        while(spaceCheck(text[j])){ j++; }
        int difference = j - i;
        if(difference > 1){ text.erase(i, difference); j = i; }
    }
}

std::string censor(std::string& text, int length){
    int i = 0, j = 0;
    while(true){
        checkExcessSpace(text, i, j);
        if(spaceCheck(text[j])){
            // will erase word from string if length matches, move j back to i
            if(j-i == length){ text.erase(i, length+1); j = i; } 
            // length does not match, move i to one after j
            else{ i = j + 1; } 
        }else if(j == text.length()){
            //check if last word in text matches length
            if(j-i == length){ text.erase(i, length); }
            //reached the end of text, break out of while loop
            break;

        } 
        j++;
    }
    return text;
}

int main(int argv, char** argc){
    if(argv != 2){
        std::cout << "USAGE: censor [length]" << std::endl;
        exit(1);
    }

    //declare varibles
    std::string text;
    int length;

    //initialize variables
    std::getline(std::cin, text);
    length = std::atoi(argc[1]);

    //censor
    std::cout << censor(text, length) << std::endl;

    return 0;
}