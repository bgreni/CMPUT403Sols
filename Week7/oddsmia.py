"""
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://docs.python.org/3/library/fractions.html

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
"""
import sys
from fractions import Fraction


class Roll:
    def __init__(self, x):
        self.x = int(''.join(sorted(x, reverse=True)))
        self.is_double = x[0] == x[1]

    def __gt__(self, other):
        if self.x == 21:
            return other.x != 21
        if other.x == 21:
            return False

        if self.is_double:
            if other.is_double:
                return self.x > other.x
            return True

        if other.is_double:
            return False

        return self.x > other.x

    def __eq__(self, other):
        return self.x == other.x


best = Roll(['1', '2'])

if __name__ == '__main__':
    lines = sys.stdin.readlines()

    for line in lines:
        if '0' in line:
            break
        
        if all(x == '*' for x in line.split()):
            print('205/432')
            continue

        x, y = line[0:3].split(), line[3:].split()
        x[0] = [int(x[0])] if x[0] != '*' else range(1, 7)
        x[1] = [int(x[1])] if x[1] != '*' else range(1, 7)
        y[0] = [int(y[0])] if y[0] != '*' else range(1, 7)
        y[1] = [int(y[1])] if y[1] != '*' else range(1, 7)

        wins = 0
        played = 0
        for x1 in x[0]:
            for x2 in x[1]:
                for y1 in y[0]:
                    for y2 in y[1]:
                        xr = Roll([str(x1), str(x2)])
                        yr = Roll([str(y1), str(y2)])
                        if xr > yr:
                            wins += 1
                        played += 1
        print(Fraction(wins, played))