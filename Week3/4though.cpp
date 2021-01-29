#include <iostream>
#include <array>
#include <vector>
#include <utility> 
#include <algorithm>

/*
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://stackoverflow.com/questions/52900557/can-you-store-arithmetic-operators-in-an-array-i-e-in-c/52901087

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

using namespace std;

typedef int (*funptr)(int, int);
struct oper {
    funptr oper;
    string str;
    int val;
    bool done;
};

struct less_than_key
{
    inline bool operator() (const oper& struct1, const oper& struct2)
    {
        return (struct1.val > struct2.val);
    }
};

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int divi(int a, int b) {
    return a / b;
}

void show(vector<int> v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    oper arr[4] = { 
        {add, "+", 1, false}, 
        {sub, "-", 1, false}, 
        {mul, "*", 2, false}, 
        {divi, "/", 2, false} 
    };
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, goal;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> goal;

        for (auto f1 : arr) {
            for (auto f2 : arr) {
                for (auto f3 : arr) {
                    vector<oper> orig = {f1, f2, f3};
                    auto a = orig;
                    int total = 0;
                    vector<int> fours = {4, 4, 4, 4};
                    int i = 0;
                    for (auto it = orig.begin(); it < orig.end();) {
                        auto f = *it;
                        if (f.val == 2) {
                            fours[i] = f.oper(fours[i], fours[i+1]);
                            it = orig.erase(it);
                            fours.erase(fours.begin() + (i+1));
                        } else {
                            ++it;
                            ++i;
                        }
                    }
                    i = 0;
                    for (auto it = orig.begin(); it < orig.end();) {
                        // show(fours);
                        auto f = *it;
                        // cout << f.str << endl;
                        if (f.val == 1) {
                            fours[i] = f.oper(fours[i], fours[i+1]);
                            fours.erase(fours.begin() + (i+1));
                            it = orig.erase(it);
                        } else {
                            ++it;
                            ++i;
                        }
                    }
                    // cout << "4 " << a[0].str << " 4 " << a[1].str << " 4 " << a[2].str << " 4 = " << fours[0] << endl;
                    if (fours[0] == goal) {
                        cout << "4 " << a[0].str << " 4 " << a[1].str << " 4 " << a[2].str << " 4 = " << fours[0] << endl;
                        // please forgive me for my sins
                        goto broke;
                    }
                }
            }
        }
        cout << "no solution" << endl;
        broke:;
    }
}