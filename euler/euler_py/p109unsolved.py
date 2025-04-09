SOS = ['S' + str(i) for i in range(21)]
SOD = ['D' + str(i) for i in range(21)]
SOT = ['T' + str(i) for i in range(21)]
SOB = ['B25', 'B50']

NOS = [i for i in range(21)]
NOD = [2 * i for i in range(21)]
NOT = [3 * i for i in range(21)]
NOB = [25, 50]

NTS = [[] for i in range(20 * 3 + 1)]


# forget to handle there are only three darts
class Ways:
    def __init__(self):
        self.dp = [[] for _ in range(101)]
        self.dp[1].append([SOS[1]])
        for target in range(2, 10):
            print(f'calculating {target}')
            self.waysOfNoEnd(target)

    def waysOfNoEnd(self, checkout):
        for base in range(checkout):
            # print(f'for base {base}: ')
            for s in NTS[checkout - base]:
                if len(self.dp[base]) == 0:
                    # print(s)
                    self.dp[checkout].append([s])
                for seq in self.dp[base]:
                    t = seq.copy()
                    t.append(s)
                    self.dp[checkout].append(t)
        for i in range(len(self.dp[checkout]) - 1, -1, -1):
            # forget to handle there are only three darts
            if len(self.dp[checkout][i]) > 2:
                self.dp[checkout].pop(i)
                continue
            for j in range(i):
                l1 = len(self.dp[checkout][i])
                l2 = len(self.dp[checkout][j])
                if l1 < 2 or l2 < 2 or l1 != l2:
                    continue
                S1, S2 = self.dp[checkout][i][-2], self.dp[checkout][i][-1]
                C1, C2 = self.dp[checkout][j][-2], self.dp[checkout][j][-1]
                if S1[-1] == S2[-1] == C1[-1] == C2[-1] and S1[-2] == C2[-2] and S2[-2] == C1[-2]:
                    # print(f' we have {self.dp[checkout][j]}, so delete {self.dp[checkout][i]} ~')
                    self.dp[checkout].pop(i)
                    break

    def waysOfEnd(self, checkout):
        ways = 0
        print(f'NOD:{NOD}')
        print(f'SOD:{SOD}')
        for d in range(1, 21):  # the last dart
            if NOD[d] > checkout: continue
            print(f'NOD[d]:{NOD[d]}')
            print(f'self.dp[{checkout - NOD[d]}]:{self.dp[checkout - NOD[d]]}')
            ways += len(self.dp[checkout - NOD[d]])
        return ways


if __name__ == '__main__':
    for i in range(1, 21):
        NTS[i].append(SOS[i])
        NTS[2 * i].append(SOD[i])
        NTS[3 * i].append(SOT[i])
    NTS[25].append(SOS[0])
    NTS[50].append(SOS[1])
    # print(NTS)
    w = Ways()
    # print(w.waysOfEnd(4))
    # for s in range(4):
    #     print(s, ':', w.dp[s])
    print(w.waysOfEnd(6))
    exit()
    for checkout in range(2, 101):
        ans += w.waysOfEnd(checkout)
