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
from heapq import heappop, heappush


if __name__ == '__main__':
    researchers, inactive_mins = sys.stdin.readline().split()
    inactive_mins = int(inactive_mins)
    arrivals = []
    finished = []
    count = 0
    
    for i in range(int(researchers)):
        arrived, stayed = sys.stdin.readline().split()
        heappush(arrivals, int(arrived))
        heappush(finished, int(arrived) + int(stayed))
    
    while arrivals:
        arrival = heappop(arrivals)
        while arrival - finished[0] > inactive_mins:
            heappop(finished)
        if finished[0] <= arrival:
            heappop(finished)
            count += 1
    print(count)