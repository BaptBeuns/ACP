#include "matrix.h"
#include <iostream>
#include <fstream>

using namespace std;

void Matrix::printInFile(std::string outputFile) {
    ofstream fileToWrite(outputFile, ios::out);

    for (int i=0; i<row; ++i){
        for (int j=0; j<col; ++j){
            fileToWrite << this->operator()(i, j) << string((j == col-1) ? "\n" : ",");
        }
    }
}

bool Matrix::moveBlue(){
int i;
for (int j=0; j<col; ++j){

      for (int i=0; i<row; ++i){
  if  (this->operator()(i, j)==1 && this->operator()((i+1)%row, j)==0){

        this->operator()(i, j)=0;
        this->operator()((i+1)%row, j)=1;
        i=i+2;
    }

    }
  }
  return true;
};


/*bool Matrix::moveRed(){
for (int i=0; i<row; ++i){
    for (int j=0; j<col; ++j){
  if  (this->operator()(i, j)==1 && this->operator()(i, (j+1)%row)==0){

        this->operator()(i, j)=0;
        this->operator()((i+1)%col, j)=1;
}*/
