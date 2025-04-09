import math

target = 50000000
primeRange = int(math.sqrt(target)) + 1


def myPrime(n):
    if n <= 1: return False
    if n == 2: return True
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0: return False
    return True


primelist = []
for i in range(primeRange):
    if myPrime(i): primelist.append(i)
# print(primelist)
# print(len(primelist))
# exit()
valid = dict()
for i in primelist:
    for j in primelist:
        for k in primelist:
            num = i ** 2
            if num > target: continue
            num += j ** 3
            if num > target: continue
            num += k ** 4
            if num > target: continue
            valid[num] = 1
# valid_nums = sorted(valid.keys())
# print(valid_nums)
print(len(valid))
