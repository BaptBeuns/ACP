#include <iomanip>
#include <iostream>
#include <complex>

#include "timing.h"

const int top = 1000;
const int max_iterations = 999;
const int area_size = 1100;


typedef std::complex<double> complexi;

int mandelbrot(complexi z, complexi c, int n) {
  if (abs(z) > top || n <= 0)
    return n;
  else
    return mandelbrot(z * z + c, c, n - 1);
}

int main(int argc, char *argv[]) {
  complexi asdf(1, 2);
  int result[area_size][area_size];

  timer Timer;

  Timer.start();
  for (int c = 0; c < 20; c++) {
    #pragma omp parallel for schedule(static)
    for (int x = 0; x < area_size; x++) {
      for (int y = 0; y < area_size; y++) {
        result[x][y] = mandelbrot(0, (-2 + x * 0.05) + complexi(0, -1.5 + y * 0.05), max_iterations);
      }
    }
  }
  Timer.stop();

  for (int x = 0; x < area_size; x++) {
    for (int y = 0; y < area_size; y++)
      std::cout << std::setfill('0') << std::setw(3) << result[x][y] << " ";
    std::cout << std::endl;
  }

  return 0;
}
