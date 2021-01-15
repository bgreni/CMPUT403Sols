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

if __name__ == '__main__':
    divisor = int(sys.stdin.readline().split()[1])
    l = list(map(lambda x: int(x), sys.stdin.readline().split()))

    results = {}
    total = 0
    for item in l:
        res = item // divisor
        if res in results:
            total += results[res]
            results[res] += 1
        else:
            results[res] = 1
    
    print(total)