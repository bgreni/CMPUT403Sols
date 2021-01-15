#include <iostream>

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
    int people;
    cin >> people;
    int arr[people];
    arr[0] = 1;
    int index;
    for (int i = 2; i < people + 1; ++i) {
        cin >> index;
        arr[index + 1] = i;
    }

    for (int i = 0; i < people; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}