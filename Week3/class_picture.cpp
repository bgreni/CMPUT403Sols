#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <functional>
#include <iterator>
/*
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  The paintings examples from class https://eclass.srv.ualberta.ca/pluginfile.php/6910628/mod_resource/content/1/paintings.cpp

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

using namespace std;


void show(vector<int> &s, vector<string> c) {
    for (int i = 0; i < s.size() - 1; ++i) {
        cout << c[s[i]] << " ";
    }
    cout << c[s[s.size() - 1]] << endl;
}

vector<int> perm, first;
vector<vector<bool>> bad;


int brute(int at) {
    if (at == perm.size()) {
        first = min(first, perm);
        return 1;
    }

    int total = 0;

    for (int i = at; i < perm.size(); ++i) {
        if (at > 0 && bad[perm[i]][perm[at-1]]) continue;
        swap(perm[i], perm[at]);
        total += brute(at+1);
        swap(perm[i], perm[at]);
    }
    return total;
}

void solve() {
    int num = 0;
    cin >> num;
    if (num == 0) return;

    vector<string> c(num);
    bad.assign(num, vector<bool>(num, false));

    for (int i = 0; i < num; ++i)
        cin >> c[i];
    sort(c.begin(), c.end());
    int nb;
    cin >> nb;

    while (nb--) {
        string s1, s2;
        cin >> s1 >> s2;
        int i1 = find(c.begin(), c.end(), s1) - c.begin();
        int i2 = find(c.begin(), c.end(), s2) - c.begin();
        bad[i1][i2] = bad[i2][i1] = true;
    }
    first.assign(num, num);
    perm.resize(num);
    for (int i = 0; i < num; ++i) {
        perm[i] = i;
    }

    int sols = brute(0);

    if (sols > 0) {
        show(first, c);
    } else {
        cout << "You all need therapy." <<  endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int class_size, pair_len;

    while (!cin.eof()) {
        solve();
    }
     
}