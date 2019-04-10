#include <fstream>

#include "GameOfLife.hpp"

using namespace std;

int main(){
    ifstream input("input.txt");
    GameOfLife game;
    if (input.is_open()){
        input >> game;
    }
    for(int i = 1;i<=3;i++){
        cout << game << endl;
        game.move();
    }
}