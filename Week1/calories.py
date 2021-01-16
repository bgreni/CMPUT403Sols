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

def to_int(thing):
    return int(thing[:-1])

def get_remaining(known_percent, known_value, unknown_percent):
    return (known_value * unknown_percent) / known_percent

class Calculator:
    def __init__(self):
        self.fcal = 9
        self.alcal = 7
        self.othercal = 4

        self.meal_cals = 0
        self.total_cals = 0
        self.total_fat_cals = 0
        self.unknown = 0
        self.fat_val = ''
        self.should_stop = False

    def handle_entry(self, cals, entry):
        ending = entry[-1]
        val = to_int(entry)

        if ending == 'g':
            self.meal_cals += val * cals
        elif ending == 'C':
            self.meal_cals += val
        else:
            self.unknown += val

    def handle_fat(self, entry):
        self.fat_val = entry
        self.handle_entry(self.fcal, entry)

    def handle_alc(self, entry):
        self.handle_entry(self.alcal, entry)

    def handle_other(self, entry):
        self.handle_entry(self.othercal, entry)

    def fat_for_meal(self):
        known = 100 - self.unknown
        total = self.meal_cals + get_remaining(known, self.meal_cals, self.unknown)
        # total = self.meal_cals / (1 - self.unknown / 100)

        fat_ending = self.fat_val[-1]
        fv = to_int(self.fat_val)

        if fat_ending == 'g':
            fat_cal = fv * self.fcal
        elif fat_ending == 'C':
            fat_cal = fv
        else:
            fat_cal = total * (fv / 100)
            
        self.total_fat_cals += fat_cal
        self.total_cals += total
        self.meal_cals = 0
        self.unknown = 0

    def print_output(self):
        # print(self.total_fat_cals, self.total_cals)
        print('{}%'.format(round((self.total_fat_cals / self.total_cals) * 100)))

        
    def reset(self):
        self.total_cals = 0
        self.total_fat_cals = 0
        self.unknown = 0
        self.fat_val = ''
        self.meal_cals = 0
               

if __name__ == '__main__':
    lines = sys.stdin.readlines()
    c = Calculator()
    for line in lines:
        if '-' in line:
            if c.should_stop:
                exit()
            c.print_output()
            c.reset()
            c.should_stop = True
            continue
        things = line.split()
        c.should_stop = False
        for i in range(len(things)):
            thing = things[i]
            if i == 0:
                c.handle_fat(thing)
            elif i == 3:
                c.handle_alc(thing)
            else:
                c.handle_other(thing)
        c.fat_for_meal()

            

            