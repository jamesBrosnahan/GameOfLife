CXX = g++
main: main.o GameOfLife.o
	$(CXX) -o main main.o GameOfLife.o
main.o: main.cpp GameOfLife.hpp
GameOfLife.o: GameOfLife.hpp
clean:
	rm main main.o GameOfLife.o