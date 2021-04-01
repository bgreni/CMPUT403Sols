
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
int N, Q, T, A, B, C, D;
const int MAXN = 200002;
const int SQ = 447+10;
vector<vector<int>> buckets(SQ, vector<int>(SQ, 0));
vector<int> arr(MAXN, 0);

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    int NSQ = ceil(sqrt(N));
    for (int i = 0; i < Q; ++i) {
        cin >> T;

        if (T == 1) {
            cin >> A >> B >> C;
            if (B <= NSQ) buckets[B][A] += C;
            else {
                for (int j = A; j <= N; j += B) {
                    arr[j] += C;
                }
            }
        } else {
            cin >> D;
            long long out = arr[D];
            for (int j = 1; j <= NSQ; ++j) {
                out += buckets[j][D%j];
            }
            cout << out << endl;
        }
    }
}