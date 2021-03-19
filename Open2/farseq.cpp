#include <bits/stdc++.h>
using namespace std;
/*

COMPLETED
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

    https://www.geeksforgeeks.org/eulers-totient-function/
    https://www.geeksforgeeks.org/eulers-totient-function/
  https://en.wikipedia.org/wiki/Farey_sequence
  ^ formular for calculating f(o)

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/



unordered_map<int, int> m;

int phi(int n) 
{ 
    int result = n;  
    for(int p = 2; p * p <= n; ++p) 
    { 
        if (n % p == 0)  
        { 
            while (n % p == 0) 
                n /= p; 
                  
            result -= result / p; 
        } 
    } 
    if (n > 1) 
        result -= result / n; 
    return result; 
} 


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 10000; ++i) {
        m[i] = phi(i);
    }

    int n, k, o;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k >> o;  
        int sum = 0;
        for (int j = 1; j <= o; ++j) {
            sum += m[j];
        }

        cout << k << " " << (1 + sum) << endl;
    }
}