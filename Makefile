CXX = g++
CXXFLAGS += -std=c++14

main: main.o GameOfLife.o
	$(CXX) $(CXXFLAGS) -o main main.o GameOfLife.o
main.o: main.cpp GameOfLife.hpp
GameOfLife.o: GameOfLife.hpp
clean:
	rm main main.o GameOfLife.o