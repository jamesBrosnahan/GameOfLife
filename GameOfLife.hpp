#include <iostream>
#include <regex>
#include <string>

using namespace std;

class GameOfLife{
    private:
        int rows, columns, generation;
        int** board;    
    public:
    GameOfLife();
    void move();
    void allocBoard();
    friend ostream &operator<<(ostream &output, const GameOfLife &g){
        output << "Generation " << g.generation << ":" << endl;
        output << g.rows << " " << g.columns << endl;
        int value;
        for(int r = 0; r < g.rows; r++){
            for(int c = 0; c < g.columns; c++){
                value = g.board[r][c];
                if(value == 1){
                    output << "*";
                }else if(value == 0){
                    output << ".";
                }
            }
            if(r != g.rows-1){
                output << endl;
            }
        }
        return output;
    }
    friend istream &operator>>( istream  &input, GameOfLife &g ) {
        string temp;
        int rowCount = 0;
        regex generation("^Generation \\d+:$");
        regex rowsAndColumns("^\\d+\\s\\d+$");
        regex row("^(\\.|\\*)+$");
        smatch matches;
        if(getline(input,temp)){
            if(regex_match(temp,generation)){

            }
        }
        while(getline(input,temp)){
            if(regex_match(temp,generation)){
                if(regex_search(temp, matches, regex("\\d+"))){
                    g.generation = stoi(matches[0].str());
                }
            }else if(regex_match(temp,rowsAndColumns)){
                    if(regex_search(temp, matches, regex("\\S+"))){
                        g.rows = stoi(matches[0].str());
                        temp = matches.suffix().str();
                        if(regex_search(temp, matches, regex("\\S+"))){
                            g.columns = stoi(matches[0].str());
                        }
                    }
            }else if(regex_match(temp,row)){
                for(int i = 0; i < temp.length();i++){
                    if(temp[i] == '*'){
                        g.board[rowCount][i] = 1;
                    }else if(temp[i] == '.'){
                        g.board[rowCount][i] = 0;
                    }
                }
                rowCount++;
            }
        }
        return input;
    }
};