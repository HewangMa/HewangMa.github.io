c2n = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000
}
n2c = dict()


def fromNumber2Rome(n):
    ret = ''
    while n > 1000:
        ret += 'M'
        n -= 1000

    if 900 <= n:
        ret += 'CM'
        n -= 900
    elif 500 <= n:
        ret += 'D'
        n -= 500
    elif 400 <= n:
        ret += "CD"
        n -= 400

    while n >= 100:
        ret += "C"
        n -= 100

    if 90 <= n:
        ret += "XC"
        n -= 90
    elif 50 <= n:
        ret += 'L'
        n -= 50
    elif 40 <= n:
        ret += 'XL'
        n -= 40

    while 10 <= n:
        ret += "X"
        n -= 10

    if 9 <= n:
        ret += 'IX'
        n -= 9
    elif 5 <= n:
        ret += 'V'
        n -= 5
    elif 4 <= n:
        ret += 'IV'
        n -= 4

    while 1 <= n:
        ret += 'I'
        n -= 1

    return ret


def fromRome2Number(R):
    ret = 0
    for i, c in enumerate(R):

        if c == 'I' and i + 1 < len(R) and (R[i + 1] == 'V' or R[i + 1] == 'X'):
            ret -= c2n[c]
            continue
        if c == 'X' and i + 1 < len(R) and (R[i + 1] == 'L' or R[i + 1] == 'C'):
            ret -= c2n[c]
            continue
        if c == 'C' and i + 1 < len(R) and (R[i + 1] == "D" or R[i + 1] == 'M'):
            ret -= c2n[c]
            continue
        ret += c2n[c]

    return ret


if __name__ == '__main__':
    for c in c2n.keys():
        n2c[c2n[c]] = c
    ret = 0
    with open('0089_roman.txt', 'r') as file:
        R = file.readline()
        while R:
            R = R.split()[0]
            num = fromRome2Number(R)
            minR = fromNumber2Rome(num)
            ret += (len(R) - len(minR))
            R = file.readline()

    print(ret)
