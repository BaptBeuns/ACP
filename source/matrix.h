#include <iostream>
#include <map>
#include <string>


class Matrix{
public:
    Matrix(){ row=0; col=0; }
    Matrix(int r, int c){ row=r; col=c; mat = new int[row*col]; }

    int& operator()(int i, int j);
    int operator()(int i, int j) const;

    void printInFile(std::string outputFile);
    void setElement(int i, int j, int number) { mat[i*col + j] = number; };

    // Move methods
    bool moveBlue();
    bool moveRed() {return false; };

private:
    int row, col, *mat;

};


inline
int& Matrix::operator()(int i, int j){
    return mat[i*col + j];
}

inline
int Matrix::operator()(int i, int j) const {
    return mat[i*col + j];
}
