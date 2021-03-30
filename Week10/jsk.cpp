
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

    https://en.wikipedia.org/wiki/Fenwick_tree

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/
const int MAXN = 200001;

int n, t[4*MAXN], Q;
int gemsvs[MAXN];
int V[6];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main() {
    cin >> n >> Q;
    for (int i = 0; i < 6; ++i) {
        cin >> V[i];
    }

    char a;
    int L[n];
    for (int i = 0; i < n; ++i) {
        cin >> a;
        int m = (int)(a - '0') - 1;
        gemsvs[i] = m;
        L[i] = V[m];
    }   
    build(L, 1, 0, n-1);

    int b, c, d;
    for (int i = 0; i < Q; ++i) {
        cin >> b >> c >> d;
        --c;
        if (b == 1) {
            --d;
            update(1, 0, n-1, c, d);
            gemsvs[c] = d;
        } else if (b == 2) {
            for (int j = 0; j < n; ++j) {
                if (gemsvs[j] == c) update(1,0,n-1,j,d);
            }
            V[c] = d;
        } else {
            --d;
            cout << sum(1, 0, n-1, c, d) << endl;
        }
        
    }
}