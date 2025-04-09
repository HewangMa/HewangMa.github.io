public class p447 {
}

class Solutionp447 {
    public int numberOfBoomerangs(int[][] points) {
        int n = points.length;
        double[][] distance = new double[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                distance[i][j] = Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
            }
        }
        int ret=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j != i && k != i && k != j && distance[i][j]==distance[i][k]) ret++;
                }
            }
        }
        return ret;
    }
}