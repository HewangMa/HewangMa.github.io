import math
from decimal import Decimal, getcontext

getcontext().prec = 30

t = 10 ** 12


def get_squares(start, end):
    return
    # squares = set()
    # current_square = 1
    # adder = 3
    # square_range = 10 ** 3
    # while current_square < square_range:
    #     current_square += adder
    #     squares.add(current_square)
    #     adder += 2
    # print(f'finished generating squares within {square_range}')


def iterating_b():
    b = (1 + math.sqrt(1 - 2 * t + 2 * t ** 2)) / 2
    b = int(b) - 1
    print(f'b starts from {b}')
    while True:
        root = Decimal(8 * b * b - 8 * b + 1).sqrt()
        if root % 1 == 0:
            r = (1 - 2 * b + root) / 2
            print(f'blue: {b}, red: {r}')
            # break
        if b % 1000001 == 0:
            print(f'trying on b = {b}')
        b += 2


def recursion():
    bs = [15, 85]
    while True:
        b = 6 * (bs[-1]) - bs[-2] - 2
        bs.append(b)
        root = Decimal(8 * b * b - 8 * b + 1).sqrt()
        r = (1 - 2 * b + root) / 2
        print(f'b = {b}, r = {r}')
        if b + r > t:
            break


def iterating_root():
    return
    # trying iterating square root
    total_discs = 10 ** 12
    delta_up_limit = 4 * total_discs ** 2 - 4 * total_discs + 1
    b_start = (1 + math.sqrt(1 - 2 * total_discs + 2 * total_discs ** 2)) / 2
    delta = 8 * b_start * b_start - 8 * b_start + 1
    root = 2 * total_discs - 1
    print(f'start of sqrt_delta: {root}')
    while True:
        b = (2 + Decimal(2 * (root ** 2) + 2).sqrt()) / 4
        r = Decimal((1 + root) / 2) - b
        if b % 1 == 0 and r % 1 == 0:
            print(f'sqrt_delta = {root}, b = {b},r = {r}')
            break
        root += 2
        if root % 1000001 == 0:
            print(f'curently tring sqrt_delta: {root}, b = {b}, r = {r}')
            print(f'   and b + r = {b + r}')


if __name__ == '__main__':
    recursion()
