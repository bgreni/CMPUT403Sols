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


def volume(L, H, W):
    return L * H * W


if __name__ == '__main__':
    inputs = list(map(lambda x: int(x), sys.stdin.readline().split()))
    side_len = inputs[0]
    h_cut = inputs[1]
    v_cut = inputs[2]
    thicc = 4

    # top half will be bigger
    bot_len = side_len - h_cut
    top_len = h_cut
    right_len = side_len - v_cut
    left_len = v_cut

    top_left = volume(top_len, left_len, thicc)
    top_right = volume(top_len, right_len, thicc)
    bot_left = volume(bot_len, left_len, thicc)
    bot_right = volume(bot_len, right_len, thicc)
    lens = [top_left, top_right, bot_left, bot_right]
    print(max(lens))