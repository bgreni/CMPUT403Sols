import sys
from math import sqrt

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

def d(x):
  return x[0] + x[1]

def distp(x, y):
  return abs(x[0] - y[0]) + abs(x[1] - y[1])


from itertools import combinations

if __name__ == '__main__':
  n = int(input())

  stuff = []
  for i in range(n):
    r, c, name = input().split()
    stuff.append((int(r), int(c), name))

  # stuff = list(filter(lambda x: ))

  pdists = [[0] * n] * n
  for i in range(n):
    for j in range(n):
      pdists[i][j] = distp(stuff[i], stuff[j])

  # s = [[0, 0, ""]]


  dp = [[float("inf")] * (n+1)] * (n+1)
  dp[0][0] = 0

  for i in range(1, n+1):
    for j in range(1, n+1):
      dp[i][j] = min(dp[i][j], dp[i-1][j] + pdists[i][j])  

  print(pdists[n][1])

  
    

 




