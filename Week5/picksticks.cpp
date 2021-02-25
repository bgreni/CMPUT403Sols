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

  https://www.geeksforgeeks.org/python-program-for-topological-sorting/

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/


bool good = true;
vector<int> v;
vector<vector<int>> g;

vector<int> s;
int n, m;

void util(int ind) {
    if (!good)
        return;

    v[ind] = 1;
    for (auto e : g[ind]) {
        if (v[e] == 0) {
            util(e);
        }
        else if (v[e] == 1) {
            good = false;
            return;
        }
    }

    s.push_back(ind);
    v[ind] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    v.resize(n, 0);
    g.resize(n, vector<int>());

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
    }

    for (int i = 0; i < n; ++i) {
        if (v[i] == 0)
            util(i);
        if (!good)
            break;
    }

    if (!good){
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            cout << (*it)+1 << endl;
        }
    }
}