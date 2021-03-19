#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://github.com/kth-competitive-programming/kactl/blob/master/content/strings/KMP.h

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

int mod(int a, int b) {
    return a - floor(a/b) * b;
}

int diff(int a1, int a2) {
    int temp = a1 - a2;
    return abs(mod((temp + 180000), 360000 - 180000));
}

vi pi(const string& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

bool match(const string& s, const string& pat) {
	vi p = pi(pat + '\0' + s), res;
	rep(i,sz(p)-sz(s),sz(p))
		if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
	return res.size() == s.size();
}

int main() {
    int n;

    cin >>n;

    int c1[n];
    int c2[n];
    for (int i = 0; i < n; ++i) {
        cin >> c1[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> c2[i];
    }

    sort(c1, c1+n);
    sort(c2, c2+n);

    vi a(n*2);
    vi b(n);

    for (int i = 1; i < n; ++i) {
        a[i-1] = c1[i] - c1[i-1];
        b[i-1] = c2[i] - c2[i-1];
    }
    a[n-1] = 360000 + c1[0] - c1[n-1];
    b[n-1] = 360000 + c2[0] - c2[n-1];
    for(int i=0;i<n;i++) a[i+n]=a[i];
    if (match(string(a.begin(), a.end()), string(b.begin(), b.end()))) {
        cout << "possible" << endl;
    } else {
        cout << "impossible" << endl;
    }
}