"""
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://www.geeksforgeeks.org/python-program-for-topological-sorting/

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
"""
def func(e):
    return int(e) - 1

good = True
def util(index, v, s, top):
    global good
    if not good:
        return
    v[index] = 1
    for e in top[index]:
        if v[e] == 0:
            util(e, v, s, top)
        elif v[e] == 1:
            good = False
            return
    s.append(index)
    v[index] = 2

if __name__ == '__main__':
    try:
        n, m = map(int, input().split())
        top = {}
        for i in range(n):
            top[i] = []

        for i in range(m):
            s, e = map(func, input().split())
            top[e].append(s)

        v = [0] * n
        s = []

        for i in range(n):
            if v[i] == 0:
                util(i, v, s, top)
            
        if not good:
            print('IMPOSSIBLE')
        else:
            for e in s:
                print(e+1)
    except Exception:
        if not good:
            print('IMPOSSIBLE')
        else:
            for e in s:
                print(e+1)




