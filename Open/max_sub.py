import sys
"""
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

https://stackoverflow.com/questions/9501337/binary-search-algorithm-in-python

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with 
"""

def binary_search(array, target):
    lower = 0
    upper = len(array)
    while lower < upper:   # use < instead of <=
        x = lower + (upper - lower) // 2
        val = array[x]
        if target == val:
            return x
        elif target > val:
            if lower == x:   # these two are the actual lines
                break        # you're looking for
            lower = x
        elif target < val:
            upper = x

if __name__ == '__main__':
    len_seq = int(sys.stdin.readline())
    nums = list(map(int, sys.stdin.readline().split()))
    num_q = int(sys.stdin.readline())

    for i in range(num_q):
        q = list(map(int, sys.stdin.readline().split()))
        index = q[0]
        query = q[2:]
        query.sort()
        count = 0
        for k in range(index-1, len(nums)):
            if not binary_search(query, nums[k]) is None:
                count += 1
            else:
                break
        print(count)