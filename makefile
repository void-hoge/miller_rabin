CC = g++
FLAGS = -lgmpxx -lgmp
STD = 
OPTIM = -mtune=native -march=native -flto -O3
PROGRAM = isprime

$(PROGRAM).out: main.cpp
	$(CC) main.cpp $(FLAGS) $(STD) $(OPTIM) -o $(PROGRAM).out

run:
	./$(PROGRAM).out 531137992816767098689588206552468627329593117727031923199444138200403559860852242739162502265229285668889329486246501015346579337652707239409519978766587351943831270835393219031728127

clean:
	rm *.out
	rm *.o
