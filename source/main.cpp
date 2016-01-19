#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <string>
#include <vector>
#include <stdio.h>

#include "matrix.h"

using namespace std;

void loadFile(const char* inputFile, int &row, int &col, Blue &blue, Red &red, set<int> stepsToPrint)
{
    string line;
    ifstream file(inputFile, ios::in);

    if(file){
        // Read first line to get stepsToPrint
        getline(file, line);
        string step;
        istringstream streamline(line);
        while(getline(streamline, step, ',')) {
            int i = atoi(step.c_str());
            // cout << i << endl;
            // stepsToPrint.insert(stoi(step));
        }
/*
        // Read other lines to get the cars matrices
        while(getline(file, line)){
            istringstream iss(line);
            while(getline(iss, line2, ',')){
                matrix[i][j] = stoi(line2);
                if(j<columns-1){
                    j++;
                }
                else{
                    j=0;
                    i++;
                }
            }
        }
*/
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
