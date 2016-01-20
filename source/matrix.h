#include <iostream>
#include <map>
#include <string>


class Matrix{
public:
    Matrix(){ row=0; col=0; }
    Matrix(int r, int c){ row=r; col=c; mat = new int[row*col]; }

    void printInFile(std::string outputFile);
    void setElement(int i, int j, int number) { mat[i*col + j] = number; };

private:
    int row, col, *mat;
};
