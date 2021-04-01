
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

    https://github.com/UAPSPC/Code-Archive/blob/master/graph/lca.cpp

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/
constexpr int log2(int n) {
    int c = 0;
    while(n >>= 1) c++;
    return c;
}

#define MAXN 200100 // TODO: Max node count
int n; // TODO: Node count
int P[MAXN][log2(MAXN)+1]; // TODO: Parents. P[i][0] = parent of i, P[0][0] = -2

// Find the vertex that is 2^i steps above u
int parent(int u, int i) {
    int &v = P[u][i];
    if (v != -1) return v;
    if (!i) return P[u][0];
    if (parent(u,i-1) == -2) return v = -2;
    return v = parent(parent(u,i-1),i-1);
}

// Depth of node u
int D[MAXN];
int depth(int u) {
    if (D[u] != -1) return D[u];
    return u ? D[u] = 1+depth(P[u][0]) : 0;
}

// Least common ancestor. O(log n)
int lca(int u, int v) {
    if (depth(v) > depth(u)) return lca(v,u);
    for (int i = log2(n); i >= 0; i--)
        if ((depth(u) - (1<<i)) >= depth(v)) u = parent(u,i);
    // invariant: depth(u) == depth(v)
    assert(depth(u) == depth(v));
    if (u == v) return u;
    for (int i = log2(n)-1; i >= 0; i--)
        if (parent(u,i) != parent(v,i)) {
            u = parent(u,i);
            v = parent(v,i);
        }
    // invariant: p(u,0) == p(v,0)
    assert(parent(u,0) == parent(v,0));
    return parent(u,0);
}

// Distance between u and v.
// Includes both endpoint nodes.
int dist(int u, int v) {
    int a = lca(u,v);
    return depth(u) + depth(v) - 2*depth(a) + 1;
}

int Q, u, v;

int main() {
    memset(D,-1,sizeof D);
    memset(P,-1,sizeof P);
    cin >> n >> Q;

    P[0][0] = -2;

    for (int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        P[v][0] = u;
    }

    for (int i = 0; i < Q; ++i) {
        cin >> u >> v;

        // int oldpu = P[u][0];
        // int oldpv = P[v][0];
        // P[oldpu][0] = u; 
        // P[oldpv][0] = v;
        // P[u][0] = -1;
        // P[v][0] = -1;

        cout << lca(u,v) << endl;
        cout << dist(u,v) << endl;
        cout << lca(u,v) + dist(u,v) << endl << endl;

        // P[u][0] = oldpu;
        // P[v][0] = oldpv;
    }
}