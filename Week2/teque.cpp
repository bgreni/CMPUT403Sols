#include <iostream>
#include <string>
#include <list>
#include <math.h>  

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
    int n;
    cin >> n;
    string cmd;
    int val; 
    list<int> t = list<int>();
    for (int i = 0; i < n; ++i) {
        cin >> cmd >> val;
        // cout << cmd << val << endl;
        if (cmd == "push_back") t.push_back(val);
        else if (cmd == "push_front") t.push_front(val);
        else if (cmd == "push_middle") {
            auto it = t.begin();
            for (int i = 0; i < ceil((float) t.size() / 2.0); ++i) ++it;
            t.insert(it, val);
        }
        else {
            auto it = t.begin();
            for (int i = 0; i < val; ++i) ++it;
            cout << *it << endl;
        }
    }
}