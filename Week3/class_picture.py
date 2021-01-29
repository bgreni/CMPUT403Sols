import sys
import itertools
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

def is_valid(c, pairs):
  for i in range(len(c) - 1):
    for p in pairs:
      if c[i] in p and c[i+1] in p:
        return False
  return True

if __name__ == '__main__':
    lines = sys.stdin.readlines()
    
    lines.reverse()
    while lines:
        c_size = int(lines.pop())
        c = [lines.pop().strip('\n') for i in range(c_size)]
        p_size = int(lines.pop())
        pairs = [lines.pop().split() for i in range(p_size)]

        # print(c)
        # print(pairs, end='\n\n')
        valids = []
        done = False
        c.sort()
        for perm in itertools.permutations(c):
          # perm = list(perm)
          if is_valid(perm, pairs):
            print(' '.join(perm))
            done = True
            break

        
        if not done:
          print('You all need therapy.')
          

