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

infin = float("inf")

def solve(n, m, k, r, s, c, table):
    curdist = k + r
    for i in range(1,n+1):
        for j in range(1,m+1):
            maxchanges = s[i-1] / k
            start = max(1, j - maxchanges)
            end = min(m, j + maxchanges)
            for k in range(start, end + 1):
                changes = abs(k-j)
                curve = 0 if i <= 1 else c[i-2][0] + c[i-2][1] * k
                table[i][j] = min(table[i][j], changes * curdist + s[i-1] - changes * k + curve + table[i-1][k])

    print(table)
    return table[n][1]

if __name__ == '__main__':
    n, m = map(int, input().split())
    k, r = map(int, input().split())

    s = [int(input()) for x in range(n)]
    c = [list(map(int, input().split())) for x in range(n-1)]
    
    table = [[infin for x in range(m+1)] for i in range(n+1)]

    table[0][1] = 0


    print(solve(n, m, k, r, s, c, table))


# if __name__ == '__main__':
#     n, m = map(int, input().split())
#     k, r = map(int, input().split())

#     s = [0] * (n + 1)
#     c = [[0, 0]] * (m + 1)


#     for i in range(1, n+1):
#         s[i] = int(input())
    
#     for i in range(1, m+1):
#         c[i] = list(map(int, input().split()))
    

#     table = [[infin for x in range(m+1)] for i in range(n+1)]

#     table[0][1]

#     for i in range(1, n+1):
#         for j in range(1, m+1):
#             mchanges = s[i] / k
#             start = max(1, j - mchanges)
#             end = min(m, j + mchanges)
#             for k in range(start, end+1):
#                 change = abs(k - j)
#                 curve = 0 if i <= 1 else c[i-1][0] + c[i-1][1] * k

#                 table[i][j] = min(table[i][j], change * (k+r) + s[i] - change * k +curve + table[i-1][k])
#     print(table[n][1])