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

int n, m;
vector<int> items;
vector<int> orders;

const int maxcost = 30000;
const int AMB = -1;
const int IMP = -2;

int main() {
    cin >> n;
    items.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i];
    }

    cin >> m;
    orders.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> orders[i];
    }

    // assume all orders are impossible, then correct this below
    vector<int> table(maxcost + 10000, IMP);
    table[0] = 0;

    for (int i = 0; i < n; ++i) {
        int item = items[i];
        for (int j = 0; j < maxcost; ++j) {
            int curr = j + item;
            if (table[j] >= 0) {
                if (table[curr] == IMP) {
                    table[curr] = i;
                } else {
                    table[curr] = AMB;
                }
            }
            if (table[j] == AMB)
                table[curr] = AMB;
        }
    }

    for (auto o : orders) {
        vector<int> order;

        if (table[o] == IMP) {
            cout << "Impossible" << endl;
            continue;
        } 
        if (table[o] == AMB) {
            cout << "Ambiguous" << endl;
            continue;
        }

        while (o > 0) {
            order.push_back(table[o] + 1);
            o -= items[table[o]];
        }
        
        for (int i = order.size() - 1; i >= 0; --i) {
            cout << order[i] << " ";
        }
        cout << endl;
    }


}