#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

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

int xs[] = {0,0,1,-1};
int ys[] = {1,-1,0,0};

int main() {
    int r, c;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> r >> c;

    vec g(r, vector<int>(c));
    vec d(r, vector<int>(c, INT_MAX));
    

    int val;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> g[i][j];
        }
    }
    
    int deepest = INT32_MAX;

    priority_queue<Node, vector<Node>, Node> q;

    vector<int> best;

    for (int i = 0; i < r; ++i) {
        vector<vector<bool>> v(r, vector<bool>(c, false));
        vector<int> sol;
        Loc start = {0, i};
        q.push(Node(start, g[i][0]));
        int maxel = INT_MIN;
    
        while (!q.empty()) {
            Node top = q.top();
            Loc l = top.l;
            int x = l.x;
            int y = l.y;
            int cost = top.cost;
            q.pop();
            sol.push_back(cost);

            // maxel = max(maxel, cost);

            if (cost > d[y][x])
			    continue;

            // if (x == c-1) {
            //     break;
            // }

            // if (v[y][x])
            //     continue;

            v[y][x] = true;

            Node to_add;
            int b = INT_MAX;

            for (int k = 0; k < 4; ++k) {
                int adjx = x + xs[k];
                int adjy = y + ys[k];

                if (adjx >=0 && adjx < c && adjy >= 0 && adjy < r && !v[adjy][adjx]) {
                    if (max(g[adjy][adjx], cost) < d[adjy][adjx]) {
                        d[adjy][adjx] = max(g[adjy][adjx], cost);
                        Node node({adjx, adjy}, d[adjy][adjx]);
                        q.push(node);
                    }
                }
            }
            // q.push(to_add);
        }
        deepest = min(g[i][0], deepest);
    }
    cout << deepest << endl;
}
