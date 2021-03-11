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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // map<int, int> pos;

    int n, temp;
    cin >> n;
    vector<int> pos(n);

    for (int i = 0; i < n; ++i) {
        cin >> pos[i];
        pos[i]--;
        // cin >> temp;
        // pos[temp] = i;

    }

    for (int i = 0; i < n; ++i) {
        // for (auto e : pos) {
        //     cout << e << " ";
        // }
        // cout << endl;
        cout << abs(pos[i] - i) << endl;
        int v = pos[i];
        pos.erase(pos.begin() + i);
        pos.insert(pos.begin() + v, v);
    }
}