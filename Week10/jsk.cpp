
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
    https://cp-algorithms.com/data_structures/fenwick.html

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

struct FTree {
    int n;
    vector<int> arr;
    FTree(int en) : n(en) {
        arr.resize(en+1);
    }

    void add(int pos, int val) {
        while (pos <= n) {
            arr[pos] += val;
            pos += (pos & (-pos));
        }
    }

    long long csum(int end) {
        long long res = 0;
        while (end > 0) {
            res += arr[end];
            end -= (end & (-end));
        }
        return res;
    }

    long long rsum(int start, int end) {
        long long rhs = 0;
        if (start != 1)
            rhs = csum(start-1);
        return csum(end) - rhs;
    }

    void update(int pos, int val) {
        add(pos, val - rsum(pos, pos));
    }
};

int main() {
    cin >> n >> Q;
    for (int i = 0; i < 6; ++i) {
        cin >> V[i];
    }


    vector<FTree> trees(6, FTree(n));

    char a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        int m = (int)(a - '0') - 1;
        gemsvs[i] = m;
        trees[m].add(i+1, 1);
    }   


    int b, c, d;
    for (int i = 0; i < Q; ++i) {
        cin >> b >> c >> d;
        --c;
        if (b == 1) {
            --d;
            trees[d].update(c+1, 1);
            trees[gemsvs[c]].update(c+1, 0);
            gemsvs[c] = d;
        } else if (b == 2) {
            V[c] = d;
        } else {
            long long s = 0;
            for (int j = 0; j < 6; ++j) {
                s += V[j] * trees[j].rsum(c+1, d);
            }
            cout << s << endl;
        }
        
    }
}