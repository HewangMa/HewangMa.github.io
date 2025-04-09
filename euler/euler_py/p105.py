from itertools import combinations


def valid(list):
    n = len(list)
    # property 1
    subsets = []
    for size in range(1, n):
        combs = combinations(list, size)
        for comb in combs:
            subsets.append(comb)
    for i in range(len(subsets)):
        for j in range(i + 1, len(subsets)):
            if sum(subsets[i]) == sum(subsets[j]):
                # print(subsets[i], subsets[j], 'are equal')
                return False

    # property 2
    for b_size in range(2, (n + 1) // 2 + 1):
        c_size = b_size - 1
        b_perms = combinations(list, b_size)
        for b_perm in b_perms:
            sum_b = sum(b_perm)
            c_perms = combinations(list, c_size)
            c_perms = [perm for perm in c_perms if not any(item in b_perm for item in perm)]
            for c_perm in c_perms:
                sum_c = sum(c_perm)
                # print(b_perm, c_perm)
                if sum_b <= sum_c:
                    # print(b_perm, c_perm)
                    return False
    return True


if __name__ == '__main__':
    ans = 0
    with open('0105_sets.txt', 'r') as file:
        line = file.readline().strip()
        while line:
            nums = list(map(int, line.split(',')))
            if valid(nums):
                ans += sum(nums)
            line = file.readline().strip()
    print(ans)