#include <iostream>
#include <vector>

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


struct Pair {
    int arrived;
    int end;
};

int main() {
    int researchers, inactive_mins;
    cin >> researchers >> inactive_mins;
    vector<Pair> left = vector<Pair>();
    left.reserve(researchers);
    int arrives, stays;
    int count = 0;
    for (int i = 0; i < researchers; ++i) {
        cin >> arrives >> stays;
        Pair newPair = {
            arrives,
            arrives + stays
        };

        for (int i = 0; i < left.size(); ++i) {
            cout << left[i].arrived << " " << left[i].end << " " << newPair.arrived << " " << newPair.end << endl << endl;
            if (helper(left[i], newPair, inactive_mins)) {
                ++count;
                left.push_back(newPair);
                break;
            }
        }
        left.push_back(newPair);
    }
    cout << count << endl;
}