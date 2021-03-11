#include <bits/stdc++.h>

using namespace std;
/*
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://github.com/UAPSPC/Code-Archive/blob/master/num_theory/isprime_fast.cpp

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

using ld = long double;
using p = pair<ld, ld>;
int T, N;
ld D;

double dist(p p1, p p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

using u128 = __uint128_t;
u128 powmod(u128 b, u128 e, u128 m) {
    u128 res = 1;
    for (b %= m; e; e >>= 1) {
        if (e&1) res = res*b%m;
        b = b*b%m;
    }
    return res;
}
bool is_prime(uint64_t n) {
    if (n < 2) return false;
    u128 d = n-1, r = 0;
    while (d%2 == 0) r++, d /= 2;
    for (u128 a : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if (a > n-2) break;
        u128 x = powmod(a, d, n);
        if (x == 1 || x == n-1) continue;
        for (u128 j = 0; r && j < r-1; j++) {
            x = x*x%n;
            if (x == n-1) goto next;
        }
        return false;
    next:;
    }
    return true;
}

// #define ONEPRIME 0

// int is_prime(int x){
//   int i;
//   if( x == 1 ) return ONEPRIME;
//   if( x == 2 ) return 1;
//   if( x % 2 == 0) return 0;
  
//   for(i = 3; i*i <= x; i+=2)
//     if( x % i == 0) return 0;
//   return 1;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T != 0) { 
        cin >> N >> D;

        p curr = {0.0, 0.0};
        p next = {0.0, 0.0};
        int done = 0;
        for (int i = 0; i < N; ++i) {
            cin >> next.first >> next.second;
            D -= dist(curr, next);
            curr = next;
            if (D >= 0)
                ++done;
        }
        while (done != 0 && !is_prime(done)) --done;
        cout << done << endl;
        --T;
    }
}