public class p221 {
    class Solution {
        public int maximalSquare(char[][] matrix) {
            int m = matrix.length;
            int n = matrix[0].length;
            int[][] dp = new int[m][n];
            // dp[i][j] 表示以 i，j为右下角的最大正方形的边长
            // 初始化: dp[i][j] = matrix[i][j]

            // 推理：dp[i][j] 仅由左上角一条线上的元素及其邻居推理
            int max_length = 0;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++) {
                    dp[i][j] = matrix[i][j] - '0';
                    if (dp[i][j] == 1) max_length = 1;
                }
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (matrix[i][j] == '0') continue;

                    int sub_length = dp[i - 1][j - 1];

                    int vi = 0;
                    for (; vi <= sub_length; vi++)
                        if (matrix[i - vi][j] != '1') break;

                    int vj = 0;
                    for (; vj <= sub_length; vj++)
                        if (matrix[i][j - vj] != '1') break;

                    dp[i][j] = Math.min(vi, vj);
                    max_length = Math.max(max_length, dp[i][j]);
                }
            }
            return max_length * max_length;
        }
    }

    public static void main(String[] args) {

    }
}
