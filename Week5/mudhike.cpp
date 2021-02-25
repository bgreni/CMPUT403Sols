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

typedef vector<vector<int>> vec;

struct Loc {
    int x;
    int y;
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

int xs[] = {0,0,1,-1};
int ys[] = {1,-1,0,0};

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
    priority_queue<Node, vector<Node>, Node> q;
    vec b(r, vector<int>(c, INT32_MAX));
    for (int i = 0; i < r; ++i) {
        vector<vector<bool>> v(r, vector<bool>(c, false));
        while (!q.empty()){
            q.pop();
        }
        q.push(Node({0, i}, g[i][0]));
        while (!q.empty()) {
            int x = q.top().l.x;
            int y = q.top().l.y;
            int cost = q.top().cost;
            q.pop();

            if (x == c-1) {
                break;
            }

            v[y][x] = true;

            for (int k = 0; k < 4; ++k) {
                int adjx = x + xs[k];
                int adjy = y + ys[k];

                if (adjx >=0 && adjx < c && adjy >= 0 && adjy < r && !v[adjy][adjx]) {
                    int next = max(g[adjy][adjx], cost);
                    if (next < b[adjy][adjx]){
                        b[adjy][adjx] = next;
                        q.push(Node({adjx, adjy}, next));
                    }
                }
            }
        }
    }
    for (auto e : b) {
        deepest = min(deepest, e[c-1]);
    }
    cout << deepest << endl;
}
