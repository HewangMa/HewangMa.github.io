import java.util.Arrays;

public class p130 {
    class Solution {

        public void dfs(char[][] grid, boolean[][] visited, int i, int j) {
            if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length) return;
            if (!visited[i][j] && grid[i][j] == 'O') {
                visited[i][j] = true;
                grid[i][j] = 'P';
                dfs(grid, visited, i + 1, j);
                dfs(grid, visited, i - 1, j);
                dfs(grid, visited, i, j + 1);
                dfs(grid, visited, i, j - 1);
            }
        }

        public void solve(char[][] grid) {
            int n = grid.length;
            int m = grid[0].length;
            boolean[][] visited = new boolean[n][m];
            for (boolean[] bs : visited) Arrays.fill(bs, false);
            for (int i = 0; i < n; i++) {
                int j = 0;
                if (grid[i][j] == 'O' && !visited[i][j])
                    dfs(grid, visited, i, j);
                j = m - 1;
                if (grid[i][j] == 'O' && !visited[i][j])
                    dfs(grid, visited, i, j);
            }
            for (int j = 0; j < m; j++) {
                int i = 0;
                if (grid[i][j] == 'O' && !visited[i][j]) dfs(grid, visited, i, j);
                i = n - 1;
                if (grid[i][j] == 'O' && !visited[i][j]) dfs(grid, visited, i, j);
            }
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (grid[i][j] == 'O') grid[i][j] = 'X';
                    else if (grid[i][j] == 'P') grid[i][j] = 'O';
        }
    }

}
