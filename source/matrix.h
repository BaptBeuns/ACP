#include <iostream>
#include <fstream>
#include <cmath>
#include <map>

typedef int size_type;
typedef std::map<size_type, std::map<size_type , int> > mat_t;
typedef typename mat_t::iterator row_iter;
typedef std::map<size_type, int> col_t;
typedef typename col_t::iterator col_iter;

class Matrix
{
public:
    Matrix(size_type i){ m=i; n=i; }
    Matrix(size_type i, size_type j){ m=i; n=j; }

    inline
    int& operator()(size_type i, size_type j)
    {
        if(i>=m || j>=n) throw;
        return mat[i][j];
    }

    friend std::ostream& operator<<(std::ostream& os, Matrix& matrix); // il faudrait que ce soit const Matrix& matrix...

protected:
    Matrix(){}

private:
    mat_t mat;
    size_type m;
    size_type n;
};

std::ostream& operator<<(std::ostream& os, Matrix& matrix)
{
    for(row_iter ii=matrix.mat.begin(); ii!=matrix.mat.end(); ii++){
        for(col_iter jj=(*ii).second.begin(); jj!=(*ii).second.end(); jj++){
            os << (*ii).first << ' ';
            os << (*jj).first << ' ';
            os << (*jj).second << std::endl;
        }
    }
    os << std::endl;
    return os << std::endl << "Alex PDV enculé";
}
