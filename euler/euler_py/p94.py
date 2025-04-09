import math
from decimal import Decimal, getcontext


def judge_area(sides):
    a = sides[0]
    c = sides[1]
    if c % 2 == 1: return False
    t = c // 2
    # res = math.sqrt(a ** 2 - c ** 2 / 4) * (c / 2)
    # Decimal(a * a - t * t).sqrt() * t
    # varify if a*a-t*t is a square number
    return Decimal(a * a - t * t).sqrt() % 1 == 0


class logger:
    def log_print(self, s):
        with open('p94.log', 'a') as log_file:
            log_file.write(s + '\n')


if __name__ == '__main__':
    # the key is how to judge a decimal
    testSize = 1000000000
    sum_of_p = 0
    getcontext().prec = 50
    a, c = 0, 0
    for p in range(5, testSize + 1):
        if p % 3 == 0: continue
        if p % 3 == 1:
            a, c = p // 3, p // 3 + 1  # b==a
        else:
            a, c = p // 3 + 1, p // 3  # b==a
        if c % 2 == 1: continue

        t = c // 2
        # res = math.sqrt(a ** 2 - c ** 2 / 4) * (c / 2)
        # Decimal(a * a - t * t).sqrt() * t
        # varify if a*a-t*t is a square number
        if Decimal(a * a - t * t).sqrt() % 1 == 0:
            print(a, a, c, p)
            sum_of_p += p
    logger().log_print(f'testsize:{testSize}, sum_of_p:{sum_of_p}')

'''
[333233333, 333233333, 333233334] 999700000
[333266667, 333266667, 333266666] 999800000
[333333333, 333333333, 333333334] 1000000000
312532314457237947
'''
