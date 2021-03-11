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

  https://cp-algorithms.com/string/string-hashing.html

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

using ll = long long;

long long compute_hash(string const& s, int i) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    bool skipped = false;
    for (int j = 0; j < s.size() - 1; ++j) {
        if (j == i && !skipped) {
            continue;
        }
        hash_value = (hash_value + (s[j] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}


int main() {
    int n;

    cin >> n;
    int typos = 0;
    unordered_set<ll> hashes;
    hashes.reserve(n);
    vector<string> things(n);
    unordered_set<int> sizes;
    sizes.reserve(n);

    string temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        hashes.insert(compute_hash(temp, -1));
        things[i] = temp;
        sizes.insert(temp.size());
    }

    for (auto word : things) {
        if (sizes.count(word.size() - 1) > 0 ) {
            for (int i = 0; i < word.size(); ++i) {
                ll hash = compute_hash(word, i);
                if (hashes.count(hash) > 0) {
                    ++typos;
                    cout << word << endl;
                    break;
                }
            }
        }
    }
    if (typos == 0) cout << "NO TYPOS" << endl;
}