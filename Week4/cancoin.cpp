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

vector<int> coins;
// true results
vector<int> real;
// greedy results
vector<int> greed;
int n;

string solve() {
  int s = coins.size();
  int limit = coins[s -1] + coins [s - 2];
  real.resize(limit, INT32_MAX);
  real[0] = 0;
  greed.resize(limit, 0);

  for (int i = 0; i < limit; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i - coins[j] >= 0) {
        real[i] = min(real[i], real[i- coins[j]] + 1);
        greed[i] = greed[i - coins[j]] + 1;
      }
    }
    if (real[i] != greed[i]) return "non-canonical";
  }
  return "canonical";
}

int main() {
  cin >> n;
  coins.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }

  cout << solve() << endl;
}