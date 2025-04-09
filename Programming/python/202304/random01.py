# random.py
# 本代码使用投点方法计算pi
from time import perf_counter
from random import random

start = perf_counter()
Total = 100 * 100
count = 0
for i in range(Total + 1):
    x, y = random(), random()
    dis = pow(x ** 2 + y ** 2, 0.5)
    if dis <= 1.0:
        count += 1
print("园内的比例：{:.6f} 历时：{:.6f}".format(count / Total * 4, perf_counter() - start))
