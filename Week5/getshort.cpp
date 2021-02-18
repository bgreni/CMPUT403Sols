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

  https://bradfieldcs.com/algos/graphs/dijkstras-algorithm/

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

typedef pair<double, double> p;

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        vector<vector<p>> g(n);

        for (int i = 0; i < m; ++i) {
            double s, e, w;
            cin >> s >> e >> w;

            g[s].push_back({w, e});
            g[e].push_back({w, s});
        }

        priority_queue<p> q;
        q.push({1, 0});
        
        vector<double> d(n, 0);
        vector<bool> v(n, false);
        while (!q.empty()) {
            p item = q.top();
            double pos = item.second;
            double w = item.first;
            q.pop();
            
            if (v[pos]) {
                continue;
            }

            // if (w > d[pos])
            d[pos] = w;
            v[pos] = true;
            

            for (auto nei : g[pos]) {
                q.push({nei.first * w, nei.second});
            }

        }

        // for (auto j : d) {
        //     cout << j << " ";
        // }
        // cout << endl;
        cout << fixed << setprecision(4) << d[n-1] << endl;
    }
}
