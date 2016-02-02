#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <string>

#include "matrix.h"

using namespace std;

set<int> loadFile(const char* inputFile)
{
    set<int> stepsToPrint;
    string line;
    ifstream file(inputFile, ios::in);

    if(file){
        // Read first line to get stepsToPrint
        getline(file, line);
        string step;
        istringstream streamline(line);
        while(getline(streamline, step, ',')) {
            stepsToPrint.insert(stoi(step));
        }
        file.close();
    } else {
        cout << "File doesn't exist!" << endl ;
    }

    return stepsToPrint;
};


int main()
{
    // Initialisation of variables
    int row, col, step=0;
    set<int> stepsToPrint = loadFile("problem.csv");
    Matrix matrix("problem.csv");

    // Boolean representing the fact that some cars moved. ie traffic not blocked
    bool redMoved = true, blueMoved = true, blockedTraffic = false;

    // Main loop, going on until there is no more step to print in file,
    // or until no car can move anymore.
    while(!blockedTraffic && !stepsToPrint.empty()) {

        // Increments the step
        ++step;

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


    // If traffic is blocked, we print all the missing files
    if (blockedTraffic) {
        cout << "Traffic is blocked at step " << step << ", printing output files..." << endl;
        for (set<int>::iterator step = stepsToPrint.begin(); step != stepsToPrint.end(); ++step)
        {
            matrix.printInFile(to_string(*step) + ".csv");
        }
    }

    return 0;
}
