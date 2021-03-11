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

  N/A

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

int T;
double V1, V2, N, W;

using ld = long double;

ld facts[51];

void buildfacts() {
    facts[0] = 1;
    facts[1] = 1;

    for (int i = 2; i < 51; ++i) {
        facts[i] = i * facts[i-1];
    }
}


ld choose(ld n, ld i) {
    int N = n;
    int I = i;
    return facts[N] / (facts[I] * (facts[N - I]));
}

ld stuff(ld n, ld k) {
    ld tot = pow(2, n);
    ld total = 0;
    for (int i = k; i <= n; ++i) {
        total += choose(n, i) / tot;
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin  >> T;
    buildfacts();

    for (int k = 0; k < T; ++k) {
        cin >> N >> V1 >> V2 >> W;
        ld pwin = (V1 / N);
        ld plose = (V2 / N);

        if (pwin > 0.5) {
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
            continue;
        }
        if (plose >= 0.5) {
            cout << "RECOUNT!\n";
            continue;
        } else {
            ld k = abs(((N * 0.5) + 1) - V1);
            ld n = N - (V1 + V2);
            ld res = stuff(n, k);
            
            if (res > W / 100) {
                cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
                continue;
            }
            cout << "PATIENCE, EVERYONE!\n";
        }
    }
}