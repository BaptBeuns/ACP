#include <iostream>

#define DEBUG

#ifdef DEBUG

#define M 10
#define N 7
#define O 5

#else

#define M 1000
#define N 500
#define O 280

#endif

int main(int argc, char *argv[]) {
  double A[M][N];
  double B[N][O];
  double C[M][O] = { 0 };

  // Initialize the matrices

#ifdef DEBUG
  std::cout << "A =" << std::endl;
  for (int I = 0; I < M; I++) {
    for (int J = 0; J < N; J++) {
      A[I][J] = I + 2 * J;
      std::cout << " " << A[I][J];
    }
    std::cout << std::endl;
  }

  std::cout << "B =" << std::endl;
  for (int J = 0; J < N; J++) {
    for (int K = 0; K < O; K++) {
      B[J][K] = 2 * J + K;
      std::cout << " " << B[J][K];
    }
    std::cout << std::endl;
  }
#endif

  double Total = 0.0;

  #pragma omp parallel for reduction(+: Total)
  for (int I = 0; I < M; I++) {
    for (int J = 0; J < N; J++) {
      for (int K = 0; K < O; K++) {
        C[I][K] += A[I][J] * B[J][K];
        Total += C[I][K];
      }
    }
  }


#ifdef DEBUG
  std::cout << "C =" << std::endl;
  for (int I = 0; I < M; I++) {
      for (int K = 0; K < O; K++) {
      std::cout << " " << C[I][K];
    }
    std::cout << std::endl;
  }

  std::cout << "Total: " << Total << std::endl;
#endif

  return 0;
}
