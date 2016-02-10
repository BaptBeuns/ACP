#include "matrix.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <omp.h>

using namespace std;

const int BLUE = 1;
const int RED = 2;


Matrix::Matrix(std::string inputFile) {
    string line, number;
    ifstream file(inputFile, ios::in);
    row = 0;
    col = 0;

    if(file){
        // Skip first line
        getline(file, line);

        // Read other lines to get the dimensions
        while(getline(file, line)){
            istringstream streamline(line);
            if (row == 0) {
                while(getline(streamline, number, ',')){
                    ++col;
                }
            }
            ++row;
        }
        mat = new int[row*col];

        // Creating and filling the matrix
        file.clear();
        file.seekg(0);
        int i = 0;
        int j = 0;
        // Skip first line
        getline(file, line);
        while(getline(file, line)){
            istringstream streamline(line);
            j = 0;
            while(getline(streamline, number, ',')){
                this->operator()(i, j) = stoi(number);
                ++j;
            }
            ++i;
        }
        file.close();
    } else {
        cout << "File doesn't exist!" << endl ;
    }
}

void Matrix::printInFile(std::string outputFile) {
    ofstream fileToWrite(outputFile, ios::out);

    for (int i=0; i<row; ++i){
        for (int j=0; j<col; ++j){
            fileToWrite << this->operator()(i, j) << string((j == col-1) ? "\n" : ",");
        }
    }

    fileToWrite.close();
}

bool Matrix::moveBlue() {
    bool movedBlue = false;

    for (int j=0; j<col; ++j){

        // This boolean checks that first box is free at the beginning of the loop
        bool first_isInitiallyFree = (this->operator()(0, j) == 0);
        int i = 0;
        while(i < row) {
            int *currentCar = &(this->operator()(i, j));
            int *nextCar = &(this->operator()((i+1)%row, j));
            bool next_isFree = (*nextCar == 0);
            // Sometimes, when we arrive at the last box, we don't make the car move because the first box was originally not free
            if (i == row - 1 and !first_isInitiallyFree) {
                next_isFree = false;
            }

            if(*currentCar == BLUE) {
                if(next_isFree) {
                    // Move current car
                    *currentCar = 0;
                    *nextCar = BLUE;
                    movedBlue = true;
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

        // This boolean checks that first box is free at the beginning of the loop
        bool first_isInitiallyFree = (this->operator()(i, 0) == 0);

        int j = 0;
        while(j < col) {
            int *currentCar = &(this->operator()(i, j));
            int *nextCar = &(this->operator()(i, (j+1)%col));
            bool next_isFree = (*nextCar == 0);
            // Sometimes, when we arrive at the last box, we don't make the car move because the first box was originally not free
            if (j == col - 1 and !first_isInitiallyFree) {
                next_isFree = false;
            }

            if(*currentCar == RED) {
                if(next_isFree) {
                    // Move current car
                    *currentCar = 0;
                    *nextCar = RED;
                    movedRed = true;
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
