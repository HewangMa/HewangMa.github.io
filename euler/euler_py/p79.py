if __name__ == '__main__':
    with open('0079_keylog.txt', 'r') as key_files:
        line = key_files.readline().strip()
        ask = []
        while line:
            num = int(line)
            ask.append(num)
            line = key_files.readline()
    left_of = [set() for _ in range(10)]
    right_of = [set() for _ in range(10)]
    for num in ask:
        a = num // 100
        b = num // 10 % 10
        c = num % 10
        left_of[c].add(a)
        left_of[c].add(b)
        left_of[b].add(a)
        right_of[a].add(b)
        right_of[a].add(c)
        right_of[b].add(c)
    for i in range(10):
        print(left_of[i], '  ', i, '  ', right_of[i])
