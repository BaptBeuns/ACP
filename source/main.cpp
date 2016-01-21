#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <string>

#include "matrix.h"

using namespace std;

void loadFile(const char* inputFile, int &row, int &col, set<int> &stepsToPrint, Matrix &matrix)
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
    int row, col, step=0;
    set<int> stepsToPrint;
    Matrix matrix;

    loadFile("../../problem.csv", row, col, stepsToPrint, matrix);

    // Boolean representing the fact that some cars moved. ie traffic not blocked
    bool redMoved = true, blueMoved = true, blockedTraffic = false;

    // Main loop, going on until there is no more step to print in file,
    // or until no car can move anymore.
    while(!stepsToPrint.empty() || !blockedTraffic) {

        // Increments the step
        ++step;
        cout << step << endl;

        // Moves the cars. If it doesn't move, stop the execution
        if (step%2 == 1) {
            blueMoved = matrix.moveBlue();
        } else {
            redMoved = matrix.moveRed();
        }
        blockedTraffic = (!blueMoved && !redMoved);

        // Checks if the step has to be printed
        if (stepsToPrint.find(step) != stepsToPrint.end()) {
            matrix.printInFile(to_string(step) + ".csv");
            stepsToPrint.erase(step);
        }
    }

    return 0;
}
