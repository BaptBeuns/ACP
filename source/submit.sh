git checkout sequential
tar -zcvf sequential.tar.gz CMakeLists.txt build.sh run.sh main.cpp matrix.cpp matrix.h timing.h

git checkout omp
tar -zcvf omp.tar.gz CMakeLists.txt build.sh run.sh main.cpp matrix.cpp matrix.h timing.h

firefox http://codelab.necst.it/exs/BML
