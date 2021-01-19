import sys
"""
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

    https://socratic.org/questions/if-30-of-x-is-50-what-is-60-of-x

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
"""

cals = [9, 4, 4, 4, 7]

def to_int(thing):
    return int(thing[:-1])

def get_remaining(known_percent, known_value, unknown_percent):
    return (known_value * unknown_percent) / known_percent


def cals_for_line(line):
    things = line.split()
    total = 0
    percents = []
    percent = 0
    cal_vals = [0, 0, 0, 0, 0]

    for i in range(len(things)):
        ending = things[i][-1]
        val = to_int(things[i])

        if ending == 'g':
            v = val * cals[i]
            total += v
            cal_vals[i] = v
        elif ending == 'C':
            total += val
            cal_vals[i] = val
        else:
            percent += val
            percents.append(i)
    
    known = 100 - percent
    total = total + get_remaining(known, total, percent)

    for index in percents:
        cal_vals[index] = total * to_int(things[index]) / 100
    return cal_vals[0], sum(cal_vals)




if __name__ == '__main__':
    lines = sys.stdin.readlines()
    total_fat = 0
    total_total = 0
    should_stop = False
    for line in lines:
        if '-' in line:
            if should_stop:
                exit()  
            print('{}%'.format((round((total_fat / total_total) * 100))))
            total_total = 0
            total_fat = 0
            should_stop = True
            continue
        should_stop = False
        fat, total = cals_for_line(line)
        total_fat += fat
        total_total += total
    

            

            