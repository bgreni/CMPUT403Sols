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

    N/A

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with 
"""

if __name__ == '__main__':
    cases = int(sys.stdin.readline())
    k = 0
    for i in range(cases):
        longest = 0
        case_len = int(sys.stdin.readline())
        seen = []
        for j in range(case_len):
            while k < case_len:
                curr = sys.stdin.readline()
                if curr not in seen:
                    seen.append(curr)
                else:
                    
                    longest = max(longest, len(seen))
                    seen.pop(0)
                    seen.append(curr)
                    break
                k += 1

        print(longest)
