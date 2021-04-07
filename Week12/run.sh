g++ -std=c++17 -g -O3 cheese.cpp && \
time ./a.out < 1.in > out.put && diff out.put 1.ans && \
time ./a.out < 2.in > out.put && diff out.put 2.ans