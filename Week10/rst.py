"""
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

    https://github.com/UAPSPC/Code-Archive/blob/master/graph/lca.cpp

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
"""

import sys
from functools import lru_cache
from math import log2

class lca:
    def __init__(self, n):
        self.P = [[-1] * (self.log2(n)+1)] * (n+1)
        self.D = [-1] * (n+1)
        self.P[0][0] = -2
        self.n = n

    # @lru_cache(maxsize=None)
    def log2(self, n):
        return int(log2(n))

    # @lru_cache(maxsize=None)
    def parent(self, u, i):
        v = self.P[u][i]
        if v != -1: return v
        if i <= 0: return self.P[u][0]
        if self.parent(u, i-1) == -2:
            self.P[u][i] = -2
            return -2
        self.P[u][i] = self.parent(self.parent(u, i-1), i-1)
        return self.P[u][i]

    # @lru_cache(maxsize=None)
    def depth(self, u):
        if self.D[u] != -1: return self.D[u]
        if u > 0:
            self.D[u] = 1+self.depth(self.P[u][0])
            return self.D[u]
        else:
            return 0

    # @lru_cache(maxsize=None)
    def lca(self, u, v):
        if self.depth(v) > self.depth(u): return self.lca(v, u)
        for i in range(self.log2(n), -1, -1):
            if (self.depth(u) - (1 << i)) >= self.depth(v): u = self.parent(u,i)
        if u == v: return u
        for i in range(self.log2(n)-1, -1, -1):
            if self.parent(u,i) != self.parent(v,i):
                u = self.parent(u,i)
                v = self.parent(v,i)

        return self.parent(u,0)

    # @lru_cache(maxsize=None)
    def dist(self, u,v):
        a = self.lca(u,v)
        return self.depth(u) + self.depth(v) - 2*self.depth(a)+1

if __name__ == '__main__':
    sys.setrecursionlimit(1500)
    n, q = map(int, sys.stdin.readline().split())
    l = lca(n)

    for i in range(n-1):
        u, v = map(int, sys.stdin.readline().split())
        l.P[v][0] = u

    for i in range(q):
        u, v = map(int, sys.stdin.readline().split())

        d = l.dist(u,v)
        print((d-1) * max(u,v)+1)