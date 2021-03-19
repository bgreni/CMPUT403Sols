g++ -std=c++17 -g -O3 farseq.cpp && \
time ./a.out < 1.in > out.put && diff out.put 1.ans