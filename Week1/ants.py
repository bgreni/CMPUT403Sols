import sys

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

def max_from_closet_edge(distances, pole):
    m = 0
    for d in distances:
        var = min(pole - d, d)
        m = max(var, m)
    return m

if __name__ == '__main__':
    cases = int(sys.stdin.readline())

    for i in range(cases):
        pole, ants = list(map(lambda x: int(x), sys.stdin.readline().split()))

        distances = []
        while len(distances) != ants:
            distances.extend(list(map(lambda x: int(x), sys.stdin.readline().split())))
        distances.sort()
        
        things = [max(pole - distances[0], distances[-1]), max_from_closet_edge(distances, pole)]


        print(min(things), max(things))