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

/*
    Matrix cars = Matrix("../../cars.csv", &blue, &red);

    while (step <= 100) {
      // if step 1, 10, 100 -> print in file
      if (step in [1, 10, 100]) {
        print cars;
      }
      // move blue cars
      blue.move()
      // move red cars
      red.move()
    }
*/


/*
ECRITURE DANS UN FICHIER

int nomfichier = vect[j];
string extension = ".csv";
string nomentier = to_string(nomfichier) + extension;
ofstream objectfile(nomentier, ios::out);

for (int m=0; m<lines; m++){
    for (int n=0; n<columns; n++){
        if(n == columns-1){
            objectfile << matrix[m][n] << endl;
        }
        else{
            objectfile << matrix[m][n] << ",";
        }
    }
}


*/
    return 0;
}
