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
  https://github.com/kth-competitive-programming/kactl/blob/master/content/strings/SuffixArray.h

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

vi pi(const string& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vi match(const string& s, const string& pat) {
	vi p = pi(pat + '\0' + s), res;
	rep(i,sz(p)-sz(s),sz(p))
		if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
	return res;
}

vi sa, lcp;
void suffixArray(string& s, int lim=256) { // or basic_string<int>
    int n = sz(s) + 1, k = 0, a, b;
    vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
    sa = lcp = y, iota(all(sa), 0);
    for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
        p = j, iota(all(y), n - j);
        rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
        fill(all(ws), 0);
        rep(i,0,n) ws[x[i]]++;
        rep(i,1,lim) ws[i] += ws[i - 1];
        for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
        swap(x, y), p = 1, x[sa[0]] = 0;
        rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
            (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
    }
    rep(i,1,n) rank[sa[i]] = i;
    for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
        for (k && k--, j = sa[rank[i] - 1];
                s[i + k] == s[j + k]; k++);
}


int main() {
    int n;
    string s;
    while(cin >> n) {
        if (n == 0) break;
        cin >> s;
        suffixArray(s);
        int longest = 0;
        int index = 0;


        for(int i=0; i<s.length(); i++) {
            // for(int j=1; j<=s.length()-i; j++) {
                string in(s.begin()+sa[i], s.end()); //get a substring of s from position with length j
                vi ret = match(s, in);
                if (ret.size() >= n && in.size() > longest) {
                    longest = in.size();
                    index = ret[ret.size() - 1];
                }
            // }
            
        }
        if (longest < n) {
            cout << "none" << endl;
        } else {
            cout << longest << " " << index << endl;
        }
    }
}