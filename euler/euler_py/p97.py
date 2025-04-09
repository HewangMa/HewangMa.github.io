t = 1
for _ in range(7830457):
    t = (t << 1) % 10000000000
print(28433 * t + 1)
