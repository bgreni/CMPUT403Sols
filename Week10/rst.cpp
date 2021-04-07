
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

    https://eclass.srv.ualberta.ca/pluginfile.php/7035320/mod_resource/content/3/tourists.cpp

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

int n, Q, u, v;

typedef long long ll;
#define MAXN 200010
#define LOGN 18
// the graph
vector<int> g[MAXN];
int up[LOGN][MAXN], depth[MAXN];

// Find the vertex that is 2^i steps above u
void dfs(int v, int pre, int d) {
    depth[v] = d;

    for (auto w : g[v])
        if (w != pre)
            dfs(w, v, d+1);

    up[0][v] = pre;
}

// compute the LCA of a and b
int lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);

    // raise b to have the same depth as a by jumping up via
    // powers of 2 (sort of like the fast exponentiation trick)
    for (int j = LOGN-1; j >= 0; --j)
        if (depth[a] + (1<<j) <= depth[b])
            b = up[j][b];

    // then a was an ancestor of b, so it is the LCA
    if (a == b) return a;

    // otherwise, simultaneously raise them both up via the powers of
    // 2 trick but only if this does not cause them to be equal
    for (int j = LOGN-1; j >= 0; --j)
        if (up[j][a] != up[j][b]) {
            a = up[j][a];
            b = up[j][b];
        }

    // now a != b but they have a common parent, which is the LCA
    return up[0][a];
}

// just the forumula from the file header
ll dist(ll a, ll b) {
    return depth[a] + depth[b] - 2*depth[lca(a, b)] + 1;
}



int main() {
    cin >> n >> Q;

    for (int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (auto x : up) fill(x, x+n, -1);
    dfs(0, -1, 0);

     for (int j = 1; j < LOGN; ++j)
        for (int v = 0; v < n; ++v)
            if (up[j-1][v] != -1)
                up[j][v] = up[j-1][up[j-1][v]];

    for (int i = 0; i < Q; ++i) {
        cin >> u >> v;
        --u;
        --v;
        ll z = dist(u,v);
        cout << ((z*(z-1))/2)+n << endl;
        
    }
}