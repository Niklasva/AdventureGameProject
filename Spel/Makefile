#
# Makefile för Game,
#

CCC	= g++ -std=c++11 
LFLAGS	= -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

all:  Game  main  Merchant


Game: Game.cc Game.h Game.o
	$(CCC) $(LFLAGS) -o Game 

main: main.cc 
	$(CCC) -c main main.cc

Merchant: Merchant.cc Merchant.h
	$(CCC) $(LFLAGS) -o Merchant.cc



clean:
	@ \rm -rf *.o *.gch core

zap: clean
	@ \rm -f brute encrypt *~

