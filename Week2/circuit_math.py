import sys
"""
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://stackoverflow.com/questions/36792236/how-to-get-character-position-in-alphabet-in-python-3-4

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
"""

class Stack:
    def __init__(self):
        self.data = []
    
    def push(self, item):
        self.data.append(item)
    
    def get_top(self):
        i1 = self.data.pop()
        i2 = self.data.pop()
        return i1, i2


def letter_to_int(letter):
    return ord(letter) - 65

if __name__ == '__main__':
    lines = sys.stdin.readlines()
    truths = [True if x == 'T' else False for x in lines[1].split()]
    expression = lines[2].split()
    stack = Stack()
    for token in expression:
        if token == '*':
            a, b = stack.get_top()
            stack.push(a and b)
        elif token == '+':
            a, b = stack.get_top()
            stack.push(a or b)
        elif token == '-':
            stack.data[-1] = not stack.data[-1]
        else:
            stack.push(truths[letter_to_int(token)])

    print('T' if stack.data[0] else 'F')


