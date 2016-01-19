#include <iostream>
#include <set>
#include "matrix.h"

using namespace std;

void loadFile(string inputFile, int &row, int &col, Blue &blue, Red &red, set<int> stepsToPrint)
{
    cout << "Bien chargé négro" << endl;
};


int main()
{
    int row, col;
    Blue blue;
    Red red;
    set<int> stepsToPrint;
    string inputFile = "../../problem.csv";

    loadFile(inputFile, row, col, blue, red, stepsToPrint);
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
