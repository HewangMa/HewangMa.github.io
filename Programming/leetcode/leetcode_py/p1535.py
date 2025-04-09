from collections import deque


class Solution:
    def getWinner(self, arr, k):
        if k>=len(arr):
            return max(arr)
        win_time = {}
        que = deque(arr)
        # print(len(que))
        while que:
            p1 = que.popleft()
            p2 = que.popleft()
            winner, loser = (p1, p2 )if p1 > p2 else (p2, p1)
            que.appendleft(winner)
            que.append(loser)
            if winner not in win_time:
                win_time[winner] = 1
            else:
                win_time[winner] += 1
            win_time[loser] = 0
            if win_time[winner] >= k:
                return winner
            # print(len(que))


if __name__ == "__main__":
    arr = [2, 1, 3, 5, 4, 6, 7]
    k = 2
    s = Solution()
    print(s.getWinner(arr, k))
