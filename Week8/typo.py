"""
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://stackoverflow.com/questions/1228299/changing-one-character-in-a-string

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
"""

if __name__ == '__main__':
    n = int(input())
    typos = 0
    d = [''] * n
    sizes = set()
    for i in range(n):
        word = input()
        d[i] = word
        sizes.add(len(word))


    for word in d:
        if len(word) in sizes:
            for i in range(len(word)):
                temp = word[:i] + word[i+1:]
                if temp in d:
                    typos += 1
                    print(word)
                    break
                

    if typos == 0:
        print('NO TYPOS')
