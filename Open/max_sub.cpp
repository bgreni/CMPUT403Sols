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


using p = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, en;
    cin >> n;
    p arr[n+1];
    int last = -1;
    int lastind = 0;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (temp == last) {
            arr[lastind].second += 1;
        } else {
            arr[lastind] = {temp, 1};
            ++lastind;
        }
    }
    arr[lastind+1] = {-1, 1};

    int start, m, t;
    cin >> en;
    unordered_set<int> s;

    for (int i = 0; i < en; ++i) {
        s.clear();
        cin >> start >> m;
        --start;

        if (m == n) {
            cout << n - start << endl;
            for (int k = 0; k < m; ++k) {
                cin >> start;
            }
            continue;
        }
        
        s.reserve(m);
        for (int k = 0; k < m; ++k) {
            cin >> t;
            s.insert(t);
        }

        int count = 0;
        int j = 0;

        while (start != 0) {
            if (arr[j].second <= start) {
                start -= arr[j].second;
                ++j;
            } else {
                if (s.count(arr[j].first) > 0) {
                    count += arr[j].second - start;
                    ++j;
                    break;
                } else {
                    goto nothing;
                }
            }
        }

        for (; j <= lastind; ++j) {
            
            if (s.count(arr[j].first) > 0) {
                count += arr[j].second;
            } else {
                break;
            }

        }
        nothing:

        
        cout << count << endl;
    }
}