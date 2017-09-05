CC=g++
CFLAGS=-Wall -O2 -lgtest
SOURCES=test.cpp friend_recommendation.cpp
EXE=TEST
all: test
test: 
	$(CC) $(CFLAGS) -o $(EXE) $(SOURCES)
clean:
	touch $(EXE)
	rm $(EXE)
run: test
	./$(EXE)
remake: 
	make clean
	make all

