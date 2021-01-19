import sys
import math
from collections import deque
"""
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

    https://www.geeksforgeeks.org/deque-in-python/
  

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
"""

if __name__ == '__main__':
    
    n = int(sys.stdin.readline())
    front = deque()
    back = deque()
    for i in range(n):
        pair = sys.stdin.readline().split()
        cmd = pair[0]
        val = int(pair[1])

        if cmd == 'push_back':
            back.append(val)
            if len(back) > len(front):
                front.append(back.popleft())
        elif cmd == 'push_front':
            front.appendleft(val)
            if len(front) > len(back):
                back.appendleft(front.pop())
        elif cmd == 'push_middle':
            if len(front) < len(back):
                front.append(back.popleft())
            back.appendleft(val)
        else:
            if val >= len(front):
               print(back[val - len(front)])
            else:
                print(front[val])
