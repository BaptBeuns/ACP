cmake_minimum_required(VERSION 2.7)
project(openmp-tests CXX)

set(ENABLE_OMP On CACHE BOOL "Enable OpenMP")

if(ENABLE_OMP)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
endif()

# Note: -fopenmp automatically links libgomp, here we manually force its linking
#       so that our programs keep working even if OpenMP is disabled.

add_executable(parallel parallel.cpp)
target_link_libraries(parallel gomp)

add_executable(parallel-2 parallel-2.cpp)
target_link_libraries(parallel-2 gomp)

add_executable(parallel-3 parallel-3.cpp)
target_link_libraries(parallel-3 gomp)

add_executable(matrix-multiply matrix-multiply.cpp)
target_link_libraries(matrix-multiply gomp)

add_executable(matrix-multiply-2 matrix-multiply-2.cpp)
target_link_libraries(matrix-multiply-2 gomp)

add_executable(matrix-multiply-3 matrix-multiply-3.cpp)
target_link_libraries(matrix-multiply-3 gomp)

add_executable(matrix-multiply-4 matrix-multiply-4.cpp)
target_link_libraries(matrix-multiply-4 gomp)

add_executable(matrix-multiply-5 matrix-multiply-5.cpp)
target_link_libraries(matrix-multiply-5 gomp)

add_executable(matrix-multiply-6 matrix-multiply-6.cpp)
target_link_libraries(matrix-multiply-6 gomp)

add_executable(matrix-multiply-7 matrix-multiply-7.cpp)
target_link_libraries(matrix-multiply-7 gomp)

add_executable(mandelbrot mandelbrot.cpp)
target_link_libraries(mandelbrot gomp)

add_executable(mandelbrot-2 mandelbrot-2.cpp)
target_link_libraries(mandelbrot-2 gomp)

add_executable(var-types var-types.cpp)
target_link_libraries(var-types gomp)
