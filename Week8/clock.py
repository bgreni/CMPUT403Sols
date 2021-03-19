import sys
from heapq import heappush
"""
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!


  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with 
"""
def diff(a, b):
    return abs(((a-b) + 180000) % (360000 - 180000))

def pi(p, nex):
    nex[0] = -1
    k = -1
    j = 0
    while(j < len(p)-1):
        if k == -1 or p[j] == p[k]:
            k+=1
            j+=1
            if (p[j] != p[k]):
                nex[j] = k
            else:
                nex[j] = k
        else:
            k = nex[k]

def kmp(s, p):
    i = 0
    j = 0
    nex = [0] * 200005
    
    pi(p, nex)

    while (i < len(s) and j < len(p)):
        if j == -1 and s[i] == p[j]:
            i += 1
            j += 1
        else:
            j = nex[j]

    if (j == len(p)):
        return True
    return False



if __name__ == '__main__':
    n = int(input())

    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    a.sort()
    b.sort()

    c = [0] *n
    d = [0] *n

    for i in range(1, n):
        c[i-1] = diff(a[i], a[i-1])
        d[i-1] = diff(b[i], b[i-1])
    c[n-1] = diff(a[0], a[n-1])
    d[n-1] = diff(b[0], b[n-1])

    c += c


    if kmp(c, d):
        print('possible')
    else:
        print('impossible')