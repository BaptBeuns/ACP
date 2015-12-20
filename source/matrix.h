#include <iostream>
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
