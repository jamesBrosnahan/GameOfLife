#include <exception>
#include <fstream>

#include "GameOfLife.hpp"

using namespace std;

int main(int argc, char*argv[]){
    GameOfLife game;
    ifstream input;
    string input_file = "input.txt";
    
    if(argc == 2){
      // two arguments, open second argument as input file and output to std::cout
      input_file = argv[1];
    }
    try{
      input.open(input_file);
      if (input.is_open()){
        input >> game;
      }
      input.close();
      for(int i = 1;i<=3;i++){
        cout << game << endl;
        game.move();
      }
    }catch(const ifstream::failure& e){
      cerr << "File io error";
    }
    
}