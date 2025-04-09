class Solution:
    def cal_covered(self, matrix, bin):
        n = len(matrix[0])
        ret = 0
        for row in matrix:
            covered = True
            for j in range(n):
                if row[j] == 1 and bin[j] != "1":
                    covered = False
                    break
            if covered:
                print(f"covered {row}")
                ret += 1
        return ret

    def maximumRows(self, matrix, numSelect):
        n = len(matrix[0])
        if numSelect >= n:
            return len(matrix)
        ret = 0
        for i in range(2**n):
            b = bin(i)[2:]
            b = "0" * (n - len(b)) + b
            if b.count("1") != numSelect:
                continue
            print(b)
            cover_cnt = self.cal_covered(matrix, b)
            ret = max(ret, cover_cnt)
        return ret

        """
        事实 是矩阵大小不需要动态规划方法 暴力即可
        dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
        # dp[i][j] 表示在前m[:,0:i]列中选择j列所能覆盖的最大行数
        # i >= j
        dp[0][0] = 0
        for i in range(n + 1):
            dp[i][0] = 0
        """


if __name__ == "__main__":
    s = Solution()
    matrix = [[0], [1]]
    numSelect = 1
    print(s.maximumRows(matrix, numSelect))
