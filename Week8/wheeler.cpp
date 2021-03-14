// #include <bits/stdc++.h>.
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

/*
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://github.com/UAPSPC/Code-Archive/blob/master/string/suffix_array.cpp

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/
const int MaxN = 200010;
int SA[MaxN], tempSA[MaxN];
int RA[MaxN], tempRA[MaxN];
// char T[MaxN];
string T;
int c[MaxN];
int N;
void radixSort(int k) { // O(n), numbers up to N, any chars
    int i, maxi = max(300, N);
    memset(c, 0, sizeof c);
    for (i = 0; i < N; ++i) {// Integer rank freq
        // TODO: Mod instead if circular sorting.
        int index = i + k < N ? RA[i + k] : 0;
        c[index]++;
    }
    int sum = 0;
    for (i = 0; i < maxi; ++i) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (i = 0; i < N; ++i) { // Shuffle sufix array.
        // TODO: Mod if circular sorting.
        int indexToRA = SA[i] + k;
        int indexToC = indexToRA < N ? RA[indexToRA] : 0;
        tempSA[c[indexToC]++] = SA[i];
    }
    for (i = 0; i < N; ++i)
        SA[i] = tempSA[i];
}

void constructSA() {
    int i;
    for (i = 0; i < N; ++i)
        RA[i] = T[i];
    for (i = 0; i < N; ++i)
        SA[i] = i;
    for (int k = 1; k < N; k <<= 1) {
        radixSort(k); // Sort based on value k indicies after
        radixSort(0); // Sort based on current value of self (stable)
        int r = 0; // Rank, starting from 0.
        tempRA[SA[0]] = r;
        for (i = 1; i < N; ++i) {
            tempRA[SA[i]] =
                // Note that second condition will only be tried with non-circular sorting if SAs + k < N.
                // Otherwise they would already be different, due to sorting to the end.
                (RA[SA[i]] == RA[SA[i - 1]] && RA[(SA[i] +k)%N] == RA[(SA[i - 1] + k)%N]) ? r : ++r;
        }
        for (i = 0; i < N; ++i)
            RA[i] = tempRA[i];
        if (RA[SA[N - 1]] == N - 1)
            break; // All have unique ranks.
    }
}

int main() {
    T.reserve(MaxN);
    while (getline(cin, T)) {
        N = T.size();
        T += T;
        N *= 2;
        T[N] = '\0';
        ++N;
        constructSA();
        for(int i = 0; i < N; i++) {
            if(SA[i] < N/2)
                cout << T[SA[i] + N/2 - 1];
        }
        cout << endl;
    }
    
}