#include <iostream>
#include <map>
#include <string>


class Matrix{
public:
    Matrix(){ row=0; col=0; }
    Matrix(int r, int c){ row=r; col=c; mat = new int[row*col]; }
    Matrix(std::string inputFile);
    ~Matrix() {
        if (row!=0 and col!=0) {
            delete[] mat;
        }
    };

    // Setter
    int& operator()(int i, int j);
    // Getter
    int operator()(int i, int j) const;

    void printInFile(std::string outputFile);

    // Move methods
    bool moveBlue();
    bool moveRed();

private:
    int row, col, *mat;

};


inline
int& Matrix::operator()(int i, int j){
    if(!(0 <= i && i < row && 0 <= j && j < col)) {
        throw std::invalid_argument( "received incoherent value" );
    }
    return mat[i*col + j];
}

inline
int Matrix::operator()(int i, int j) const {
    if(!(0 <= i && i < row && 0 <= j && j < col)) {
        throw std::invalid_argument( "received incoherent value" );
    }
    return mat[i*col + j];
}
