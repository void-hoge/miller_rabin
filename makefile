CC = clang++
PROG = isprime
FLAG = -lgmp -lgmpxx
STD = -std=c++11
OPTIM = -O2 -mtune=native -march=native

$(PROG).out: main.cpp miller_rabin.cpp
	$(CC) main.cpp miller_rabin.cpp $(FLAG) $(STD) $(OPTIM) -o $(PROG).out

test: $(PROG).out
	./$(PROG).out 3918277498164613871680731263797 3

clean:
	rm *.out || rm *.o
