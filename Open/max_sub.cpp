#include <iostream>
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

https://en.cppreference.com/w/cpp/algorithm/binary_search

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

// FOR DEBUG
void show(int arr[], int n) {

    for (int i = 0; i < n; ++i) {
        cout << arr[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int len_seq, num_q;
    cin >> len_seq;
    int num[len_seq];
    for (int i = 0; i < len_seq; ++i) {
        cin >> num[i];
    }
    cin >> num_q;

    int start, len;
    for (int i = 0; i < num_q; ++i) {
        cin >> start >> len;
        int query[len];
        for (int j = 0; j < len; ++j) {
            cin >> query[j];
        }

        sort(query, query+len);
        int count = 0;
        for (int k = (start - 1); k < len_seq; ++k) {
            if (binary_search(query, query+len, num[k])) {
                ++count;
            } else break;
        }
        cout << count << endl;
    }


}