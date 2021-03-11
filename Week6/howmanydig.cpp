/*
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

https://math.stackexchange.com/questions/136831/factorial-number-of-digits#:~:text=One%20more%20than%20the%20floor%20gives%2018%20or%2019%20digits,the%20upper%20is%20nearly%2020.

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/
#include <bits/stdc++.h>
using namespace std;
const int m = 1000000;

double ls[m + 1];

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*
    Using the rule that the number of digits in a number x is
    floor(log(x)) + 1
    So for x! we calculate it in log space which is  sum(log(i)) for i 1..x
    Then that number is the number of digits in x! 
    */
    ls[0] = 0;
    for (int i = 1; i <= m; ++i) {
        ls[i] = log10(i) + ls[i-1];
    }
    while (cin >> n) {
        if (n == 0 || n == 1) {
            cout << 1 << endl;
        } else {
            cout << (int)ls[n] + 1 << endl;
        }
    }
}