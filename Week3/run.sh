g++ std=c++17 -0 minibattleship.cpp &&
 && time ./a.out < battleship-0000.in > sample.out && diff sample.out battleship-0000.ans
&& time ./a.out < battleship-0001.in > sample.out && diff sample.out battleship-0001.ans
&& time ./a.out < battleship-0002.in > sample.out && diff sample.out battleship-0002.ans
