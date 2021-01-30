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

  N/A

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

using namespace std;


void show(vector<string> &s) {
    for (int i = 0; i < s.size() - 1; ++i) {
        cout << s[i] << " ";
    }
    cout << s[s.size() - 1] << endl;
}

int is_valid(vector<string> &v, vector<string> &s) {
    // vector<int> v(v1.size());
    // vector<int> s(s1.size());

    // for (int i = 0; i < v1.size(); i++) {
    //     v[i] = hasher(v1[i]);
    // }
    // for (int i = 0; i < s1.size(); i++) {
    //     s[i] = hasher(s1[i]);
    // }    

    for (auto i = v.begin(); i != v.end() - 1; ++i) {
        for (auto j = s.begin(); j < s.end() - 1; j+=2) {
            if ((*i == *j && *(i+1) == *(j+1)) || (*i == *(j+1) && *(i+1) == *j)) 
                return (i - v.begin()) + 1;
            // if ((*i == *j && *(i+1) != *(j+1))) {
                // cout << v1[distance(s.begin(), j)] << " " << v1[distance(s.begin(), j+1)] << endl;
                // show(v1);
                // show(s);
                // s.erase(j, j+2);
                // if (s.empty()) return true;
            // }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int class_size, pair_len;
    hash<string> hasher;
    while (!cin.eof()) {
        class_size = 0;
        cin >> class_size;
        if (class_size == 0) {
            break;
        }
        vector<string> c(class_size);
        map<int, string> m;
        int h;
        // string temp, p1, p2;
        for (int i = 0; i < class_size; ++i) {
            cin >> c[i];
        }
    

        cin >> pair_len;
        // vector<pair<string, string>> p(pair_len);
        vector<string> p(pair_len * 2);
        for (int i = 0; i < pair_len * 2; i += 2) {
            cin >> p[i] >> p[i+1];
        }
        bool done = false;
        // show(p);
        sort(c.begin(), c.end());
        do {
            int v = is_valid(c, p);
            if (v == 0) {
                show(c);
                done = true;
                break;
            } else {
                --v;
                string s1 = c[v];
                string s2 = c[v+1];
                // show(c);
                // cout << c[v] << " " << c[v+1] << endl;
                bool cont = true;
                while (true) {
                    if (((c[v] == s1 && c[v+1] == s2) || (c[v] == s2 && c[v+1] == s1)) && cont) {
                        break;
                    }
                    // show(c);
                    cont = next_permutation(c.begin(), c.end());
                }
                if (!cont) break;
            }
        } while (next_permutation(c.begin(), c.end()));

        if (!done) {
            cout << "You all need therapy." << endl;
        }
    }
}