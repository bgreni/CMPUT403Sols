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

  The paintings examples from class https://eclass.srv.ualberta.ca/pluginfile.php/6910628/mod_resource/content/1/paintings.cpp

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

vector<char> bad = {'.', 'X'};
vector<vector<bool>> board;
int n, k;

int ways(vector<int> pieces) {

    for (auto p)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    board = vector<vector<bool>>(n);
    board.resize(n, vector<bool>(n));
    char curr;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> curr;
            if (find(bad.begin(), bad.end(), curr) != bad.end()) {
                board[i][j] = false;
            } else {
                board[i][j] = true;
            }
        }
    }

    vector<int> pieces = vector<int>(k);
    for (int i = 0; i < k; ++i) {
        cin >> pieces[i];
    }

    sort(pieces.begin(), pieces.end(), greater<int>());

    cout << ways(pieces) << endl;
}