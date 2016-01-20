#include <iostream>
#include <map>
#include <string>

// typedef int size_type; // long int ?
// typedef char element_type;

// typedef std::map<size_type, std::map<size_type , element_type> > mat_t;
// typedef typename mat_t::iterator row_iter;

// typedef std::map<size_type, element_type> col_t;
// typedef typename col_t::iterator col_iter;


class Matrix{
private:
    int row, col, *mat;
public:
    Matrix(){ row=0; col=0; }
    Matrix(int r, int c){ row=r; col=c; mat = new int[row*col]; }
    void printInFile(std::string outputFile);
    void setElement(int i, int j, int number) { mat[i*col + j] = number; };
};

/*
class Blue:public Matrix{
  // static int color='1';
  int **cars;
};

class Red:public Matrix{
  // static int color='2';
  int **cars;
};
*/

/*
class Matrix
{
public:
    Matrix(size_type i){ m=i; n=i; }
    Matrix(size_type i, size_type j){ m=i; n=j; }
    Matrix(std::string file_name);

    // inline
    // int& operator()(size_type i, size_type j)
    // {
    //     if(i>=m || j>=n) throw;
    //     return mat[i][j];
    // }

protected:
    Matrix(){}

private:
    mat_t mat;
    size_type m;
    size_type n;
};
*/
