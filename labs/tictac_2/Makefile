
CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX      = clang++

# These targets don't create any files:
.PHONY: all clean

# Magic Variables!
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
#  $@ is the name of the target
#  $+ is a list of all the dependencies
#  $< is the first dependency


all: game

game: game-check.o Board.o Move.o # Errors.o move-check.o
	${CXX} $(CXXFLAGS) -o $@ $+

# move-check.o: move-check.cpp 
# 	${CXX} $(CXXFLAGS) -c -o $@ $<

game-check.o:  game-check.cpp
	${CXX} $(CXXFLAGS) -c -o $@ $<


Board.o: Board.cpp Board.h 
	${CXX} $(CXXFLAGS) -c -o $@ $<


Move.o: Move.cpp Move.h Errors.h 
	${CXX} $(CXXFLAGS) -c -o $@ $<


clean:
	rm -f  game game-check.o Board.o Move.o 