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

typedef vector<int> vec;
int CASES, n, m, l, s;
typedef pair<int, int> p;
#define int long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> CASES;

    for (int k = 0; k < CASES; ++k) {
        cin >> n >> m >> l >> s;
        vec installed(s+1);
        vector<bool> v(n+1);
        vector<vector<p>> g(n+1);
        for (int i = 0; i < s; ++i) {
            cin >> installed[i];
            v[installed[i]] = true;
        }
        int start, end, cost;
        for (int i = 0; i < m; ++i) {
            cin >> start >> end >> cost;
            g[start].push_back({cost + l, end});
            g[end].push_back({cost + l, start});
        }

        priority_queue<p, vector<p>, greater<p>> q;

        // push all starting points
        for (auto index : installed) {
            for (auto e : g[index]) {
                q.push(e);
            }
        }

        long long total = 0;

        while (!q.empty()) {
            int cost = q.top().first;
            int loc = q.top().second;
            q.pop();

            if (v[loc])
                continue;

            v[loc] = true;

            total += cost;

            for (auto e : g[loc]) {
                q.push(e);
            }

        }

        cout << total << endl;
    }

}