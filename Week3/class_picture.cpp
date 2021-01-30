#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
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

void show(vector<string> s) {
    for (int i = 0; i < s.size() - 1; ++i) {
        cout << s[i] << " ";
    }
    cout << s[s.size() - 1] << endl;
}


bool is_valid(vector<string> v, vector<pair<string, string>> p) {
    for (int i = 0; i < v.size() - 1; ++i) {
        for (auto b : p) {
            if ((v[i] == b.first && v[i+1] == b.second) || (v[i] == b.second && v[i+1] == b.first)) 
                return false;
        }
    }
    return true;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int class_size, pair_len;
    while (!cin.eof()) {
        cin >> class_size;
        vector<string> c;
        string temp, p1, p2;
        for (int i = 0; i < class_size; ++i) {
            cin >> temp;
            c.push_back(temp);
        }

        cin >> pair_len;
        vector<pair<string, string>> p;;
        for (int i = 0; i < pair_len; ++i) {
            cin >> p1 >> p2;
            p.push_back(make_pair(p1, p2));
        }
        bool done = false;
        sort(c.begin(), c.end());
        do {
            if (is_valid(c, p)) {
                show(c);
                done = true;
                break;
            }
        } while (next_permutation(c.begin(), c.end()));

        if (!done) {
            cout << "You all need therapy." << endl;
        }
    }
}