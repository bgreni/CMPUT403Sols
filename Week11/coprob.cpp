
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

    https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

#define V 32
const int EN = 2*V*V+1;
char top[V*V];
int rg[EN*EN];
bool visited[EN];
int g[EN*EN];
int N;

inline bool bfs(int s, int t, vector<int> &parent) {
 
    
    for(int i=0; i<N; i++)
        visited[i] = false;

    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < N; v++) {
            if (visited[v] == false && rg[u*N + v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}
int ff(int s, int t) {

    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            int ind = u*N + v;
            rg[ind] = g[ind];
        }
    }


    vector<int> parent(N);

    int mflow = 0;

    while (bfs(s, t, parent)) {
        cout << ":(" << endl;
        int pflow = INT_MAX;
        
        for (int v = t; v != s; v = parent[v]) {
            pflow = min(pflow, rg[parent[v]*N + v]);
        }

        if (pflow == INT_MAX) return -1;

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rg[u*N + v] -= pflow;
            rg[v*N + u] += pflow;
        }

        mflow += pflow;
    }
    return mflow;
} 

int m, n, c;
map<char, int> costs;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {

    cin >> n >> m >> c;

    for(int i = 0; i < m; i++) {
        for(int j=0; j<n; j++) {
            cin >> top[i*n+j];
        }
    }


    char ch = 'a';    
    for(int i=0; i<c; i++)
    {
        cin >> costs[ch+i];
    }


    N = 2*m*n+1;
    for(int i=0; i<N*N; i++)
        g[i]=0;

    int start = -1;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int cidx = m*n + i*n+j;
            for(int k = 0; k < 4; k++) {

                int ni = i + dy[k];
                int nj = j + dx[k];

                if(ni < 0 || nj < 0 || ni >= m || nj >= n) { 
                    g[cidx*N + 2*m*n] = INT_MAX;
                } else {
                    int nidx = ni*n+nj;
                    g[cidx*N + nidx] = INT_MAX;
                }
            }
            int ind1 = i*n+j ;
            int ind2 = (ind1)*N + cidx;
            if(top[ind1] == 'B')
                start = i*n+j;
            if(top[ind1] == 'B' || top[ind1] == '.') {
                g[ind2] = INT_MAX;
            }
            else
            {
                g[ind2] = costs[top[ind1]];
            }
        }
    }

    cout << ff(start, 2*m*n) << endl;
}