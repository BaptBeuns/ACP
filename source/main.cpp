#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <string>

#include "matrix.h"

using namespace std;

void loadFile(const char* inputFile, int &row, int &col, set<int> stepsToPrint, Matrix &matrix)
{
    string line, number;
    ifstream file(inputFile, ios::in);
    row = 0;
    col = 0;

    if(file){
        // Read first line to get stepsToPrint
        getline(file, line);
        string step;
        istringstream streamline(line);
        while(getline(streamline, step, ',')) {
            stepsToPrint.insert(stoi(step));
        }

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
        cout << "Number of lines: " << row << endl;
        cout << "Number of columns: " << col << endl;

        // Creating and filling the matrix
        matrix = Matrix(row, col);
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
                matrix.setElement(i, j, stoi(number));
                ++j;
            }
            ++i;
        }

        cout << "Matrix loaded" << endl;
    }
};


int main()
{
    // Initialisation of variables
    int row, col;
    set<int> stepsToPrint;
    Matrix matrix;

    loadFile("../../problem.csv", row, col, stepsToPrint, matrix);
    matrix.printInFile("tamere.csv");

    return 0;
}
