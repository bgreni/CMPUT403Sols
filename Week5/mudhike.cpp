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
// typedef pair<int, int> pa;
// typedef pair<pa, int> p;

typedef vector<vector<int>> vec;

#define UP (i - c)
#define DOWN (i + c)
#define LEFT (i - 1)
#define RIGHT (i + 1)

struct Loc {
    int x;
    int y;

    friend bool operator==(const Loc &l1, const Loc &l2) {
        return l1.x == l2.x && l1.y == l2.y;
    }
};

struct Node {
	Loc l;
	int cost;
	Node() {}
	Node(Loc newl, int newCost) {
		l = newl;
		cost = newCost;
	}
	bool operator()(const Node &lhs, const Node &rhs) {
		return lhs.cost > rhs.cost;
	}
};

int main() {
    int r, c;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> r >> c;

    vec g(r, vector<int>(c));

    int val;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> g[i][j];
        }
    }
    
    int deepest = INT32_MAX;
    // long long total = LONG_LONG_MAX;    
    // vec d(r, vector<int>(c, INT32_MAX));

    priority_queue<Node, vector<Node>, Node> q;

    vector<int> best;

    for (int i = 0; i < c; ++i) {
        vector<vector<bool>> v(r, vector<bool>(c, false));
        vector<int> sol;
        Loc start = {0, i};
        q.push(Node(start, g[i][0]));
    
        while (!q.empty()) {
            Node top = q.top();
            Loc l = top.l;
            int x = l.x;
            int y = l.y;
            int cost = top.cost;
            q.pop();
            sol.push_back(cost);

            if (x == c-1) {
                break;
            }

            if (v[y][x])
                continue;

            v[y][x] = true;

            if (x - 1 >= 0 && !v[y][x-1]) {
                q.push(Node({x-1, y}, g[y][x-1]));
            }
            if (x + 1 < r && !v[y][x+1]) {
                q.push(Node({x+1, y}, g[y][x+1]));
            }
            if (y - 1 >= 0 && !v[y-1][x]) {
                q.push(Node({x, y-1}, g[y-1][x]));
            }
            if (y + 1 < c && !v[y+1][x]) {
                q.push(Node({x, y+1}, g[y+1][x]));
            }
        }
        int maxel = *(max_element(sol.begin(), sol.end()));
        // long long tot = accumulate(sol.begin(), sol.end(), 0LL);
        for (auto e : sol) {
            cout << e << " ";
        }
        cout << "\n\n";
        if (maxel < deepest) {
            deepest = maxel;
            best = vector<int>(sol.begin(), sol.end());
        }
    }

    for (auto e : best) {
        cout << e << " ";
    }
    cout << endl;
    cout << deepest << endl;
    
}
