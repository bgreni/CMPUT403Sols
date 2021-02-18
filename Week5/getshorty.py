"""
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

https://bradfieldcs.com/algos/graphs/dijkstras-algorithm/

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
"""
from heapq import heappush

if __name__ == '__main__':
    n, m  = map(int, input().split())

    while n != 0 and m != 0:
      g = [[]] * n

      for i in range(m):
        s, e, w = map(float, input().split())
        s = int(s)
        e = int(e)
        # w = float(format(w, '.4f'))
        g[s].append((w, e))
        g[e].append((w, s))

      q = []
      v = [False] * n
      d = [0] * n
      q.append((1.0, 0))


      while q:
        item = q.pop()
        w = item[0]
        pos = item[1]

        if v[pos]:
          continue

        v[pos] = True

        if w > d[pos]:
          d[pos] = w
        # print(q)
        # print(d)

        for thing in g[pos]:
          # q.append((thing[0] * w, thing[1]))
          heappush(q, (thing[0] * w, thing[1]))
        # q.sort(key=lambda x: x[0])

      res = 1
      for t in d:
        res *= t
      print(format(d[n-2], '.4f'))
      n, m  = map(int, input().split())



