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
using ll = long long;
const int Inf = INT_MAX;
using pi = pair<int, int>;
#define MAXN 102
#define MAXM 1002
int N, M, t1, t2;
int standings[MAXN];
pi matches[MAXM];
ll g[MAXN][MAXN + MAXM + 4];
vector<ll> n[MAXN];
vector<bool> v;

inline bool cond(ll nei, int c, const vector<bool> &v) { return g[c][nei] > 0 && !v[nei] && c != nei; }

bool bfs(int N, int start, int end, vector<int> b) {
    queue<ll> u;
    v[start] = true;
    u.push(start);

    while(!u.empty()) {
        int c = u.front();
        u.pop();

        for (int i = 0; i < n[c].size(); ++i) {
            if (cond(n[c][i], c, v)) {
                u.push(n[c][i]);
                b[n[c][i]] = c;
                v[n[c][i]] = true;
                if (n[c][i] == end) return true;
            }
        }
    }
    return false;
}


ll ff(int N, int start, int end) {
    vector<int> b(N, -1);
    ll tf = 0;

    while(bfs(N,start,end,b)) {
        // cout << ":(\n"; 
        ll cf = INT_MAX;
        ll c = end;
        while(b[c] != -1) {
            cf = cf > g[b[c]][c] ? g[b[c]][c] : cf; 
            c = b[c];
        }
        c=end;
        while(b[c] != -1) {
            g[b[c]][c] -= cf;
            g[c][b[c]] += cf;
            c = b[c];
        }
        tf += cf;
    }

    return tf;
}


int main() {

    while (cin >> N) {
        // cout << N << endl;
        v = vector<bool>(N, false);
        if (N == -1) break;
        for(int i = 0; i < N+1; i++) {
            fill(g[i], g[i]+M+N+2, 0);
            n[i].clear();
        }
        cin >> M;
        for (int i = 0; i < N; ++i) {
            cin >> standings[i];
        }

        int source = 0;
        int sink = N+M+1;
        int bonus = 0;
        int mwtc = 0;
        for (int i = 1; i < M+1; ++i) g[0][i] = 2;

        for (int i = 1; i < M+1; ++i) {
            cin >> t1 >> t2;
            
            matches[i] = {t1, t2};

            if (t1 == N || t2 == N) bonus += 2;
            else {
                int ind1 = M+t1;
                int ind2 = M+t2;
                vector<int> adds = {0, ind1, ind2};
                n[0].push_back(i);
                n[i].insert(n[i].end(), adds.begin(), adds.end());
                // n[i].push_back(0);
                // n[i].push_back(ind1);
                // n[i].push_back(ind2);
                n[ind1].push_back(i);
                n[ind2].push_back(i);

                mwtc += 2;

                g[i][ind1] = Inf;
                g[i][ind2] = Inf;
                
            }
        }

        int myscore = standings[N-1] + bonus;

        for (int i = M+1; i < sink; ++i) {
            int cap = myscore - standings[i - M-1] - 1;
            g[i][sink] = cap;
            n[i].push_back(sink);
            n[sink].push_back(i);
        }

        ll flow = ff(N+M+2, 0, N+M+1);
        int s = 0;
        for (int i = 1; i < M+1; ++i) s += g[i][0];
        if (s != mwtc) cout << "NO\n";
        else {
            for (int i = 0; i < M; ++i) {
                int t1 = matches[i].first;
                int t2 = matches[i].second;
                if (t1 == N) cout << 0 << " ";
                else if (t2 == N) cout << 2 << " ";
                else {
                    int ind1 = M+t1;
                    int ind2 = M+t2;
                    if (g[ind1][i+1] == 2) cout << 0 << " ";
                    else if (g[ind2][i+1] == 2) cout << 2 << " ";
                    else cout << 1 << " ";
                }
            }
            cout << endl;
        }

    }

}
