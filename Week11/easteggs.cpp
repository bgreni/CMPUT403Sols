
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

    https://en.wikipedia.org/wiki/Blossom_algorithm

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

using ld = long double;
#define MAXN 510
int vis[MAXN], match[MAXN];
int B, R, N, V;
ld D;
ld X[MAXN], Y[MAXN];

inline ld dist(int i, int j) {
    return sqrt((X[i]-X[j])*(X[i] - X[j]) + (Y[i] - Y[j])*(Y[i]-Y[j]));
}

inline int augment(int i) {
    if(vis[i]) return 0;
    vis[i] = 1;
    for(int j = B; j < V; ++j) {
        if(dist(i, j) < D) {
            if(match[j] == -1 || augment(match[j])) {
                match[j] = i;
                return 1;
            }
        }
    }
    return 0;
}

bool works() {
    long long count = 0;
    for (int k = 0; k < B; ++k) {
        fill(vis, vis+(V+1), 0);
        count += augment(k);
    }
    return (V >= count + N);
}


int main() {
    cin >> N >> B >> R;

    V = B+R;
    ld hi = sqrt(2.0) * 2000000.1;
    ld lo = 0;
    for (int i = 0; i < V; i++)
        cin >> X[i] >> Y[i];

    while (hi - lo > 1e-8) {
        fill(match, match+(V+1), -1);
        D = (hi+lo)/2.0;
        if (works()) lo = D;
        else hi = D;
    }
    cout << fixed << setprecision(7) << hi << endl;

}