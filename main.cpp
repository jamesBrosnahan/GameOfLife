#include <fstream>

#include "GameOfLife.hpp"

using namespace std;

int main(){
    ifstream input("input.txt");
    GameOfLife game;
    if (input.is_open()){
        input >> game;
    }
    cout << game << endl;
    game.move();
    cout << game << endl;
}