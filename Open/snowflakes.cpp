#include <iostream>
#include <vector>
#include <algorithm>
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
    int cases, caselen, curr;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        vector<int> seq = vector<int>();
        int longest = 0;
        cin >> caselen;
        for (int j = 0; j < caselen; ++j) {
            cin >> curr;
            if (find(seq.begin(), seq.end(), curr) == seq.end()) {
                seq.push_back(curr);
            } else {
                if (seq.size() > longest) {
                    longest = seq.size();
                }
                seq.clear();
            }
        }
        cout << longest << endl;
    }
}