class Solution:
    def find_score(self, player):
        ret = 0
        for i, x in enumerate(player):
            if i == 0:
                ret += x
            if i == 1:
                ret += 2 * x if player[i - 1] == 10 else x
            if i > 1:
                ret += 2 * x if player[i - 1] == 10 or player[i - 2] == 10 else x
        return ret

    def isWinner(self, player1, player2):
        p1 = self.find_score(player1)
        p2 = self.find_score(player2)
        if p1 > p2:
            return 1
        if p1 == p2:
            return 0
        if p1 < p2:
            return 2
