#include <iostream>
#include <string>

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

using namespace std;

int main() {
    int num;
    int setNum = 1;
    while (cin >> num) {
        if (num == 0) break;
        string nextStr;
        string arr[num];
        int start_index = 0;
        int end_index = num - 1;

        for (int i = 0; i < num; i++) {
            cin >> nextStr;
            if (i % 2 == 0) {
                arr[start_index] = nextStr;
                ++start_index;
            } else {
                arr[end_index] = nextStr;
                --end_index;
            }
        }
        cout << "SET " << setNum << endl;
        for (int i = 0; i < num; i++) {
            cout << arr[i] << endl;
        }
        ++setNum;
    }
}