from itertools import permutations


# assume that we have got all 4 out of 10 digits permutation in permutations
# its length is math.comb(10,4)*24 which is 10*9*8*7/4/3/2 = 210

def consecutive_numbers(pNumbers):
    for i in range(len(pNumbers)):
        if pNumbers[i] != i + 1:
            return i
    return len(pNumbers)


def possible_numbers_from_four(nums):
    all_permutations = permutations(nums)
    possible_numbers = set()
    for per in all_permutations:
        possible_numbers = possible_numbers.union(possible_numbers_from_one_per(per))
    return sorted(possible_numbers)


def possible_numbers_from_one_per(per):
    # we have 6 orders to calculate the possible number
    # and 4**3 = 64 ways to put the operators
    # so the loop has 6*64 times
    possible_number = set()
    for op1 in ['+', '-', '*', '/']:
        for op2 in ['+', '-', '*', '/']:
            for op3 in ['+', '-', '*', '/']:
                try:
                    # 123
                    cal_string = f'(({per[0]} {op1} {per[1]}) {op2} {per[2]}) {op3} {per[3]}'
                    temp = eval(cal_string)
                    if type(temp) is int and temp > 0:
                        possible_number.add(temp)
                except ZeroDivisionError:
                    pass

                try:
                    # 132
                    cal_string = f'({per[0]} {op1} {per[1]}) {op2} ({per[2]} {op3} {per[3]})'
                    temp = eval(cal_string)
                    if type(temp) is int and temp > 0:
                        possible_number.add(temp)
                except ZeroDivisionError:
                    pass

                try:
                    # 213
                    cal_string = f'({per[0]} {op1} ({per[1]} {op2} {per[2]})) {op3} {per[3]}'
                    temp = eval(cal_string)
                    if type(temp) is int and temp > 0:
                        possible_number.add(temp)
                except ZeroDivisionError:
                    pass

                try:
                    # 231
                    cal_string = f'{per[0]} {op1} (({per[1]} {op2} {per[2]}) {op3} {per[3]})'
                    temp = eval(cal_string)
                    if type(temp) is int and temp > 0:
                        possible_number.add(temp)
                except ZeroDivisionError:
                    pass

                # 312 (same with 132)

                try:
                    # 321
                    cal_string = f'{per[0]} {op1} ({per[1]} {op2} ({per[2]} {op3} {per[3]}))'
                    temp = eval(cal_string)
                    if type(temp) is int and temp > 0:
                        possible_number.add(temp)
                except ZeroDivisionError:
                    pass

    return possible_number


if __name__ == '__main__':
    current_longest = 0
    ans = '0000'
    for i in range(10):
        for j in range(i + 1, 10):
            for k in range(j + 1, 10):
                for l in range(k + 1, 10):
                    nums = [i, j, k, l]
                    pNumbers = possible_numbers_from_four(nums)
                    consecutive_n = consecutive_numbers(pNumbers)

                    print()
                    print(pNumbers)
                    print(f'{nums} to form consecutive {consecutive_n}')

                    if consecutive_n > current_longest:
                        current_longest = consecutive_n
                        ans = str(i) + str(j) + str(k) + str(l)
    # length_from_permutate([1, 2, 3, 4])
    # exit()
    # for per in permutations:
    #     # get the longest consecutive obtainable chain
    #     length = length_from_permutate(per)
