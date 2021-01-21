import sys
from queue import Queue
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
    ins = sys.stdin.readlines()
    players = ins[1].split()
    waiting = Queue()
    for p in players:
        waiting.put(p)
    wins = ins[2]
    w = []
    b = []
    scores = {}

    for i in range(4):
        if i % 2 == 1:
            b.append(players[i])
        else:
            w.append(players[i])

    for i in range(4):
        waiting.put(waiting.get())
    
    timestep = 0
    for win in wins:
        if win == 'W':
            pair = tuple(sorted(w))
            if pair not in scores:
                scores[pair] = [1, timestep]
            else:
                scores[pair][0] += 1
                scores[pair][1] = timestep
            waiting.put(b.pop())
            b.insert(0, waiting.get())
            w.insert(0, w.pop())
        else:
            pair = tuple(sorted(b))
            if pair not in scores:
                scores[pair] = [1, timestep]
            else:
                scores[pair][0] += 1
                scores[pair][1] = timestep
            waiting.put(w.pop())
            w.insert(0, waiting.get())
            b.insert(0, b.pop())
        timestep += 1

    # print(scores)

    best = -1
    besties = []
    for team, val in scores.items():
        if val[0] > best:
            best = val[0]
            besties = [[team, scores[team]]]
        if val[0] == best:
            besties.append([team, scores[team]])

    besties.sort(key=lambda x: x[1])
    for team in besties:
        print('{} {}'.format(team[0], team[1]))
        

    


