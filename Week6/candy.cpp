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

  https://github.com/UAPSPC/Code-Archive/blob/master/num_theory/modular_inverse.cpp

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

using ll = long long;

ll N, k, c;

int gcd_ex(int a, int b, int& s, int& t) {
    int r0 = a, r1 = b, q;
    int s0 = 1, s1 = 0;
    int t0 = 0, t1 = 1;

    while (r1) {
        q = r0 / r1;

        r0 -= q*r1;
        swap(r0, r1);

        s0 -= q*s1;
        swap(s0, s1);

        t0 -= q*t1;
        swap(t0, t1);
    }


    s = s0;
    t = t0;

    return r0;
}

int mod_inverse(int a, int m) {
    int s, t;

    a %= m;

    if (a < 0) a += m;

    if (gcd_ex(a, m, s, t) > 1) return -1;

    s %= m;

    if (s < 0) s += m;

    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int t = 0; t < N; ++t) {
        cin >> k >> c;
 
        if (k == 1 && c == 1) {
            cout << 2 << endl;
        }
        else if (k == 1) {
            cout << 1 << endl;
        }
        else if (c == 1) {
            cout << k + 1 << endl;
        } else {
            int res = mod_inverse(c, k);

            if (res == -1){
                cout << "IMPOSSIBLE" << endl;
                continue;
            }

            cout << res << endl;
        }
        
    }
}