#include <omp.h>
#include <iostream>

long long factorial(unsigned Value) {
  if (Value != 1)
    return Value * factorial(Value - 1);
  else
    return Value;
}

int main(int argc, char *argv[]) {
  #pragma omp parallel
  {
    unsigned ThreadCount = omp_get_num_threads();
    unsigned ThreadIndex = omp_get_thread_num();
    unsigned FactorialArg = ThreadCount + ThreadIndex;
    long long Factorial = factorial(FactorialArg);

    #pragma omp critical
    {
      std::cout << "Factorial of " << FactorialArg
                << " is " << Factorial << std::endl;
    }
  }

  return 0;
}
