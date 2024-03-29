#include <bits/stdc++.h>
using namespace std;

/*
    COMPLETED

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

unordered_set<int> seen;
deque<int> window;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int CASES, CASELEN, flake;

    cin >> CASES;

    for (int i = 0; i < CASES; ++i) {
        cin >> CASELEN;
        int longest = 0;
        seen.clear();
        window.clear();
        for (int j = 0; j < CASELEN; ++j) {
            cin >> flake;
            if (seen.count(flake) > 0) {
                while (window.front() != flake) {
                    seen.erase(window.front());
                    window.pop_front();
                }
                seen.erase(window.front());
                window.pop_front();
            }

            seen.insert(flake);
            window.push_back(flake);
            longest = max(longest, (int)window.size());
        }
        cout << longest << endl;
    }
   
}