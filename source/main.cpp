#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    Matrix cars = Matrix("../../cars.csv");

    blue = Blue(cars);
    red = Red(cars);
    
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

    return 0;
}
