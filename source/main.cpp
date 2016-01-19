#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <string>

#include "matrix.h"

using namespace std;

void loadFile(const char* inputFile, int &row, int &col, Blue &blue, Red &red, set<int> stepsToPrint)
{
    string line, number;
    ifstream file(inputFile, ios::in);

    if(file){
        // Read first line to get stepsToPrint
        getline(file, line);
        string step;
        istringstream streamline(line);
        while(getline(streamline, step, ',')) {
            stepsToPrint.insert(stoi(step));
        }

        // Read other lines to get the cars matrices
        while(getline(file, line)){
            istringstream streamline(line);
            while(getline(streamline, number, ',')){
                int n = stoi(number);
            }
        }
        cout << "Bien chargé négro" << endl;
    }
};


int main()
{
    int row, col;
    Blue blue;
    Red red;
    set<int> stepsToPrint;

    loadFile("../../problem.csv", row, col, blue, red, stepsToPrint);

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
    return 0;
}
