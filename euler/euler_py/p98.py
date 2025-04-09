import math
from decimal import Decimal
from itertools import permutations


def get_paired_square_numbers(words, per):
    # for every possible substitutions
    # one per means one substitution
    c2n = dict()
    for i in range(10):
        c2n[per[i]] = i
    numbers = []
    for word in words:
        temp = 0
        for c in word:
            if c not in per:
                temp = 2
                break
            temp = temp * 10 + c2n[c]
        if Decimal(temp).sqrt() % 1 == 0:
            numbers.append(temp)
        else:
            numbers.append(2)
    print(words)
    print(numbers)


def is_anagram(w1, w2):
    if len(w1) != len(w2): return False
    letters = [0 for _ in range(26)]
    for c in w1:
        letters[ord(c) - ord('A')] += 1
    for c in w2:
        letters[ord(c) - ord('A')] -= 1
    for cnt in letters:
        if cnt != 0: return False
    return True


def sub_valid(sub):
    num_st = set()
    for c in sub:
        num_st.add(sub[c])
    return len(num_st) == len(sub)


def largest_square_number(word1, word2):
    n = len(word1)
    down = int(math.sqrt(10 ** (n - 1)))
    up = int(math.sqrt(10 ** n)) + 1
    ret = 0
    for p in range(down, up):
        square1 = p * p
        _square1 = square1
        # get the substitution from square and w1 to varify if w2 is also square
        sub = dict()
        for j in range(n - 1, -1, -1):
            num = square1 % 10
            square1 //= 10
            sub[word1[j]] = num
        if sub_valid(sub):
            square2 = 0
            for c in word2:
                square2 = square2 * 10 + sub[c]
            if Decimal(square2).sqrt() % 1 == 0 and len(str(square2)) == len(str(_square1)):
                print(sub)
                print(f' for {word1} and {word2}, we have {_square1} and {square2}')
                ret = max(ret, square2, _square1)
    return ret
    # print(word1, word2, down, up)


if __name__ == '__main__':
    # chars = [chr(65 + i) for i in range(26)]
    # permats = permutations(chars, 10)
    # print(permats)
    # cnt=0
    # for per in permats:
    #     cnt+=1
    #     # print(per)
    # print(cnt)
    # max_length = 0
    with open('0098_words.txt', 'r') as file:
        words = file.read().strip().split(',')
    for i in range(len(words)):
        words[i] = words[i][1:-1]
        # max_length = max(max_length, len(words[i]))
    n = len(words)
    anagrams = []
    for i in range(n):
        temp = [words[i], ]
        for j in range(i + 1, n):
            if is_anagram(words[i], words[j]):
                temp.append(words[j])
        if len(temp) > 1: anagrams.append(temp)
    ans = 0
    for i, pair in enumerate(anagrams):
        one = largest_square_number(pair[0], pair[1])
        ans = max(ans, one)
    print(ans)
