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

  https://www.quora.com/What-are-some-examples-of-ternary-search-problems-which-cant-be-solved-with-binary-search
  https://www.quora.com/What-is-a-ternary-search
  https://en.wikipedia.org/wiki/Ternary_search

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

using ld = long double;
ld EPS = 1e-8;

struct P {
  ld x, y, z;
};

struct Obj {
  P p;
  ld r;
  ld xp, yp, zp;
};


P pos_at_t(Obj o, ld t) {
  P res;
  res.x = o.p.x + t*o.xp;
  res.y = o.p.y + t*o.yp;
  res.z = o.p.z + t*o.zp;
  return res;
}

ld dist_3d(P a, P b) {
  return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2) + pow(a.z-b.z, 2));
}


// use ternary search to find t that minimizes the distance of s and j
// easier than doing some math stuff I probably don't understancd
ld find_best_t(Obj s, Obj j) {
    ld lo = 0;
    ld hi = 2000;
    while(hi - lo > EPS) {
        ld diff = (hi - lo) / 3;

        ld midl = lo + diff;
        P newsl = pos_at_t(s, midl);
        P newjl = pos_at_t(j, midl);
        ld curr_distl = dist_3d(newsl, newjl);

        ld midh = lo +  2 * diff;
        P newsh = pos_at_t(s, midh);
        P newjh = pos_at_t(j, midh);
        ld curr_disth = dist_3d(newsh, newjh);

        if(curr_distl < curr_disth) {
            hi = midh;
        }
        else {
            lo = midl;
        }
    }
    return lo;
}


// use binary search to find t where the distance of s and j is closest to target
ld find_contact(Obj s, Obj j, ld target, ld t) {
  ld lo = 0;
  ld hi = t;

  while (hi - lo > EPS) {
    ld mid = (hi + lo) / 2;
    P news = pos_at_t(s, mid);
    P newj = pos_at_t(j, mid);
    ld curr_dist = dist_3d(news, newj);

    if (curr_dist < target) hi = mid;
    else lo = mid;
  }
  return lo;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        Obj s;
        Obj j;

        cin >> s.p.x >> s.p.y >> s.p.z >> s.r;
        cin >> s.xp >> s.yp >> s.zp;

        cin >> j.p.x >> j.p.y >> j.p.z >> j.r;
        cin >> j.xp >> j.yp >> j.zp;

        ld target = s.r + j.r;
        ld t = find_best_t(s, j);

        P news = pos_at_t(s, t);
        P newj = pos_at_t(j, t);
        ld curr_dist = dist_3d(news, newj);

        if (curr_dist > target + EPS) cout << "No collision\n";
        else {
            ld cpoint = find_contact(s, j, target, t);
            cout << fixed << setprecision(3) << cpoint << endl;
        } 
    }
}