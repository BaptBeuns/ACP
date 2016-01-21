#include "matrix.h"
#include <iostream>
#include <fstream>

using namespace std;

const int BLUE = 1;
const int RED = 2;

void Matrix::printInFile(std::string outputFile) {
    ofstream fileToWrite(outputFile, ios::out);

    for (int i=0; i<row; ++i){
        for (int j=0; j<col; ++j){
            fileToWrite << this->operator()(i, j) << (j == col-1) ? "\n" : ",";
        }
    }
}

bool Matrix::moveBlue() {
    bool movedBlue = false;
    for (int j=0; j<col; ++j){
        int i = 0;
        while(i < row) {
            int *currentCar = &(this->operator()(i, j));
            int *nextCar = &(this->operator()((i+1)%row, j));
            bool next_isFree = (*nextCar == 0);

            if(*currentCar == BLUE) {
                if(next_isFree) {
                    // Move current car
                    *currentCar = 0;
                    *nextCar = BLUE;
                    i += 2;
                } else {
                    // Skip current car
                    ++i;
                }
            } else {
                ++i;
            }
        }
    }
    return movedBlue;
}


bool Matrix::moveRed(){
    bool movedRed = false;
    for (int i=0; i<row; ++i){
        int j = 0;
        while(j < col) {
            int *currentCar = &(this->operator()(i, j));
            int *nextCar = &(this->operator()(i, (j+1)%col));
            bool next_isFree = (*nextCar == 0);

            if(*currentCar == RED) {
                if(next_isFree) {
                    // Move current car
                    *currentCar = 0;
                    *nextCar = RED;
                    j+= 2;
                } else {
                    // Skip current car
                    ++j;
                }
            } else {
                ++j;
            }
        }
    }
    return movedRed;
}
