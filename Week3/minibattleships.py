import sys
from pprint import pprint
from copy import deepcopy, copy
import itertools
from heapq import heappush, heapify
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
bad = ''
pieces = []

def row_ways(row, piece, board, inds):
    end = 0
    start = 0
    b = []
    bd = bad.replace(indss[inds[0]], '')
    while end < len(board[row]):
        if board[row][end] not in bd:
            if end - start != piece-1:
                end += 1
            else:
                if not any([True for x in board[row][start : end+1] if x in bd]):
                    temp = deepcopy(board)
                    for i in range(start, end+1):
                        temp[row][i] = indss[inds[0]]
                    start += 1
                    end += 1
                    # print(temp)
                    b.append(temp)
                else:
                    start += 1
                    end += 1
        else:
            start += 1
            end += 1

    return b

def col_ways(col, piece, board, inds):
    end = 0
    start = 0
    b = []
    bd = bad.replace(indss[inds[0]], '')
    while end < len(board[col]):
        if board[end][col] not in bd:
            if end - start != piece-1:
                end += 1
            else:
                if not any([True for x in range(start, end+1) if board[x][col] in bd]):
                    temp = deepcopy(board)
                    for i in range(start, end+1):
                        temp[i][col] = indss[inds[0]]
                    start += 1
                    end += 1
                    b.append(temp)
                else:
                    start += 1
                    end += 1
        else:
            start += 1
            end += 1
    return b


def valid(board, tot):
    t = 0
    for row in range(len(board)):
        for col in range(len(board[row])):
            if board[row][col] in good:
                t += 1
    # print(t, tot)
    # pprint(board)
    # print()
    return t == tot

def isv(board, tot):
    t = 0
    for row in range(len(board)):
        for col in range(len(board[row])):
            if board[row][col] in gd:
                t += 1
    # print(t, tot)
    # pprint(board)
    # print()
    return t == tot

def ways_to_place(boards, inds, num_pieces):
    # print(num_pieces)
    if not inds:
        # boards.sort()
        # boards = list(x for x, _ in itertools.groupby(boards))
        total = 0
        v = []
        while boards:
            board = boards.pop()
            if valid(board, num_pieces):
                total += 1
                v.append(board)
        # for b in boards:
        #     pprint(b)
        #     print()
        return total
    num_pieces += pieces[inds[0]]

    piece = pieces[inds[0]]
    bs = []
    for board in boards:
        for row in range(len(board)):
            bs += row_ways(row, piece, board, inds)
            bs += col_ways(row, piece, board, inds)
    bs.sort()
    bs = list(x for x, _ in itertools.groupby(bs))

    return ways_to_place(bs, inds[1:], num_pieces)


# def X_in_board(board):
#     for row in board:
#         if 'X' in row:
#             return True
#     return False

indss = []
if __name__ == '__main__':
    n, k = map(int, sys.stdin.readline().split())
    board = [list(sys.stdin.readline().strip('\n')) for i in range(n)]
    pieces = [int(sys.stdin.readline()) for i in range(k)]
    inds = [i for i in range(len(pieces))]
    indss = [str(s) for s in inds]
    bad = 'X{}'.format(''.join(indss))
    good = 'O' + bad.replace('X', '')
    gd = bad.replace('X', '')


    print(ways_to_place([board], inds, 0))
