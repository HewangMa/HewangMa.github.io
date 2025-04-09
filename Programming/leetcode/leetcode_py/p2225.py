class Solution:
    def findWinners(self, matches):
        ans = [[], []]
        # 没有输掉任何一场比赛的玩家
        # 恰好输掉一场比赛的玩家
        win = {}
        lose = {}
        for m in matches:
            if m[0] in win:
                win[m[0]] += 1
            else:
                win[m[0]] = 1
            if m[1] in lose:
                lose[m[1]] += 1
            else:
                lose[m[1]] = 1
        for loser, time in lose.items():
            if time == 1:
                ans[1].append(loser)
        for winner, time in win.items():
            if winner not in lose:
                ans[0].append(winner)
        ans[0]=sorted(ans[0])
        ans[1]=sorted(ans[1])
        return ans
