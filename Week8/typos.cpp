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

using ll = __uint128_t;

// ll BIG_PRIME = 1152921504606847009;

// ll hashy(const string& s, int exclude) {
//     ll X = 2392;
//     ll hash = 0;
//     for (int i = 0; i < s.size(); ++i) {
//         if (i == exclude) continue;
//         hash += (s[i] * X) % BIG_PRIME;
//         X *= X;
//     }   
//     return hash;
// }

ll hashy(string const& s, int ex) {
    const ll p = 31;
    const ll m = 9223372036854775783;
    ll hash_value = 0;
    ll p_pow = 1;
    int i = 0;
    for (char c : s) {
        if (i == ex) continue;
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}


int main() {
    int n;

    cin >> n;
    vector<string> things(n);
    unordered_set<long long> hashes;
    hashes.reserve(n);
    unordered_set<int> sizes;
    sizes.reserve(n);

    hash<string> hasher;

    string temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        things[i] = temp;
        // hashes.insert(hasher(temp));
        hashes.insert((long long)hashy(temp, -1));
        sizes.insert(temp.size());
    }

    int typos = 0;
    for (auto word : things) {
        if (sizes.count(word.size() - 1) > 0 ) {
            for (int i = 0; i < word.size(); ++i) {
                // ll h = hasher(word.substr(0, i) + word.substr(i+1));
                long long h = hashy(word, i);
                if (hashes.count(h) > 0) {
                    ++typos;
                    cout << word << endl;
                    break;
                }
            }
        }
    }
    if (typos == 0) cout << "NO TYPOS" << endl;
}