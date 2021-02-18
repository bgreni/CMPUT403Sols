#include <bits/stdc++.h>
using namespace std;
#define l long long

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

vector<l> s;
vector<l> cl;
vector<l> cc;
vector<vector<l>> table;

l n, m, k, r;

int main() {
    cin >> n >> m >> k >> r;

    s.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    cl.resize(n-1);
    cc.resize(n-1);
    for (int i = 0; i < n-1; ++i) {
        cin >> cl[i] >> cc[i];
    }

    table.resize(n+1);
    for (int i = 0; i <= n; ++i) {
        table[i] = vector<l>(m+1, INT32_MAX);
    }

    table[0][1] = 0;

    for (l i = 1; i <= n; ++i) {
        for (l j = 1; j <= m; ++j) {
            l maxchange = s[i-1] / k;
            l start = max(1LL, j - maxchange);
            l end = min(m, j + maxchange);

            for (l k = start; k <= end; ++k) {
                l change = abs(k - j);
                l curve = (i > 1 ? cl[i-2] + cc[i-2] * k : 0);
                table[i][j] = min(table[i][j], change * (k+r) + s[i-1] - change * k + curve + table[i-1][k]);
            }
        }
    }
    cout << table[n][1] << endl;
}