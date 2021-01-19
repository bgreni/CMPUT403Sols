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

if __name__ == '__main__':
    places = {}
    n = int(input())
    for i in range(n):
        place, year = input().split()
        if place not in places:
            places[place] = []
        places[place].append(int(year))

    for key in places:
        places[key].sort()
    n = int(input())
    for i in range(n):
        place, index = input().split()
        year = places[place][int(index) - 1]
        print(year)


