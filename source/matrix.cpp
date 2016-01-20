#include "matrix.h"
#include <iostream>
#include <fstream>

using namespace std;

void Matrix::printInFile(std::string outputFile) {
    ofstream fileToWrite(outputFile, ios::out);

    for (int i=0; i<row; ++i){
        for (int j=0; j<col; ++j){
            fileToWrite << mat[i*col + j] << string((j == col-1) ? "\n" : ",");
        }
    }
}
