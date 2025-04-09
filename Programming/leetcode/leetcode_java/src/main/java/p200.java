import java.lang.reflect.Array;
import java.util.Arrays;

public class p200 {
    class Solution {

        public void dfs(char[][] grid, boolean[][] visited, int i, int j) {
            if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length) return;
            if (!visited[i][j] && grid[i][j] == '1') {
                visited[i][j] = true;
                dfs(grid, visited, i + 1, j);
                dfs(grid, visited, i - 1, j);
                dfs(grid, visited, i, j + 1);
                dfs(grid, visited, i, j - 1);
            }
        }

        public int numIslands(char[][] grid) {
            int n = grid.length;
            int m = grid[0].length;
            boolean[][] visited = new boolean[n][m];
            for (boolean[] bs : visited) Arrays.fill(bs, false);
            int num = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '1' && !visited[i][j]) {
                        dfs(grid, visited, i, j);
                        num++;
                    }
                }
            }
            return num;
        }
    }

}
