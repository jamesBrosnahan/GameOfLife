#include "GameOfLife.hpp"

GameOfLife::GameOfLife(){
    this->generation = 1;
    this->rows = 4;
    this->columns = 8;
    this->allocBoard();
}
int GameOfLife::neighbors(int r, int c){
    int sum = 0;
    for(int i = r - 1; i <= r + 1; i++){
        for(int j = c - 1; j <= c + 1; j++){
            if(i >= 0 && i < this->rows && j >= 0 && j < this->columns && !(i == r && j == c)){
                sum += this->board[i][j];
            }
        }
    }
    return sum;
}
bool GameOfLife::aliveordead(int row, int column){
    switch(this->neighbors(row, column)){
                    case 0:
                    case 1:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        //1. Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
                        //2. Any live cell with more than three live neighbours dies, as if by overcrowding.
                        return false;
                        break;
                    case 2:
                        //3. Any live cell with two or three live neighbours lives on to the next generation.
                        if(this->board[row][column] == 1){
                            return true;
                        }else{
                            return false;
                        }
                        break;
                    case 3:
                        //4. Any dead cell with exactly three live neighbours becomes a live cell.
                        return true;
                        break;
                }
}
void GameOfLife::move(){
    /*
    1. Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
    2. Any live cell with more than three live neighbours dies, as if by overcrowding.
    3. Any live cell with two or three live neighbours lives on to the next generation.
    4. Any dead cell with exactly three live neighbours becomes a live cell.
    */
   
   int** tempBoard;
   tempBoard = (int**)malloc(this->rows*sizeof(int*));
    for(int i = 0; i < this->rows; i++){
        tempBoard[i] = (int*)malloc(this->columns*sizeof(int*));
    }
    
    int value;
    for(int r = 0; r < this->rows; r++){
        for(int c = 0; c < this->columns; c++){
            tempBoard[r][c] = this->aliveordead(r,c) ? 1 : 0;
        }
    }
    this->board = tempBoard;
    this->generation++;
}
void GameOfLife::allocBoard(){
    if(this->board){
        for(int i = 0; i < this->rows; i++){
            delete [] this->board[i];
        }
        delete [] this->board;
    }
    this->board = (int**)malloc(this->rows*sizeof(int*));
    for(int i = 0; i < this->rows; i++){
        this->board[i] = (int*)malloc(this->columns*sizeof(int*));
    }
}