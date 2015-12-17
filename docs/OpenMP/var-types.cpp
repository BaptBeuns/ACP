#include <iostream>
#include <omp.h>

int main(int argc, char *argv[]) {
  int x = 3;

  #pragma omp parallel for firstprivate(x) lastprivate(x)
  for (int i = 0; i < 10; i++) {
    x += i;
    #pragma omp critical
    {
      std::cout << "Thread " << omp_get_thread_num()
                << ", iteration " << i
                <<  "  sees " << x << std::endl;
    }
  }

  std::cout << "Final value: " << x << std::endl;

  return 0;
}
