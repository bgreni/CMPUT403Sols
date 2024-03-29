"""
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
"""

import sys

class Stack:
    def __init__(self):
        self.data = []

    def push(self, item):
        self.data.append(item)

    def pop(self):
        self.data.pop()

    def top(self):
        return self.data[-1]

    def length(self):
        return len(self.data)

if __name__ == '__main__':
    length = int(sys.stdin.readline())
    numbers = list(map(lambda x: int(x), sys.stdin.readline().split()))
    total = length
    stack = Stack()

    for n in numbers:
        if stack.length() != 0 and (n + stack.top()) % 2 == 0:
            stack.pop()
        else:
            stack.push(n)


    print(stack.length())

