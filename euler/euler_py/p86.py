import math

ans = 0
target = 1000000
current = 0
M = 0
while True:
    M += 1
    for i in range(1, M + 1):
        for j in range(i, M + 1):
            k = M
            if math.sqrt((i + j) ** 2 + k ** 2).is_integer():
                current += 1
    if M % 100 == 0:
        print(M)
    if current > target:
        print(M)
        break
