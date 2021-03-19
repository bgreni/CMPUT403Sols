#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://github.com/UAPSPC/Code-Archive/blob/master/graph/strong_conn.cc
  https://www.geeksforgeeks.org/strongly-connected-components/

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/


#define VI vector<int>
#define MAXN 100010

VI g[MAXN], curr;
vector< VI > scc;
int dfsnum[MAXN], low[MAXN], id;
char done[MAXN];

void visit(int x){
  curr.push_back(x);
  dfsnum[x] = low[x] = id++;
  for(size_t i = 0; i < g[x].size(); i++)
    if(dfsnum[g[x][i]] == -1){
      visit(g[x][i]);
      low[x] = min(low[x], low[g[x][i]]);
    } else if(!done[g[x][i]])
      low[x] = min(low[x], dfsnum[g[x][i]]);

  if(low[x] == dfsnum[x]){
    VI c; int y;
    do{
      done[y = curr[curr.size()-1]] = 1;
      c.push_back(y);
      curr.pop_back();
    } while(y != x);
    scc.push_back(c);
  }
}

void strong_conn(int n){
  memset(dfsnum, -1, n*sizeof(int));
  memset(done, 0, sizeof(done));
  memset(low, 0, sizeof(low));
  scc.clear(); curr.clear();
  id = 0;
  for(int i = id = 0; i < n; i++)
    if(dfsnum[i] == -1) visit(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int CASES, D, L, s, e;

    cin >> CASES;

    for (int i = 0; i < CASES; ++i) {
        for (auto e : g) {
            e.clear();
        }

        cin >> D >> L;
        vector<pair<int, int>> edges(L);
        for (int j = 0; j < L; ++j) {
            cin >> s >> e;
            --s;
            --e;
            g[s].push_back(e);
            g[e].push_back(s);
            edges[i] = {s, e};
        }
        strong_conn(D);

        map<int, int> m;

        for (int j = 0; j < scc.size(); ++j) {
            for (auto g : scc[j]) {
                m[g] = j;
            }
        }
        VI connects(scc.size(), 0);
        int things = 0;
        for (auto &e : edges) {
            if (m[e.first] != m[e.second]) {
                connects[m[e.first]]++;
            }
        }

        for (auto e : connects) if (e == 0) ++things;
        cout << things << endl;
    }
}