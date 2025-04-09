import java.util.*;

public class p399 {
    static class Solution {
        public static boolean valid(List<List<String>> equations, List<String> q) {
            if (Objects.equals(q.get(0), q.get(1))) return true;
            boolean tag1 = false, tag2 = false;
            for (List<String> e : equations) {
                if (Objects.equals(e.get(0), q.get(0))) tag1 = true;
                if (Objects.equals(e.get(1), q.get(0))) tag1 = true;
                if (Objects.equals(e.get(0), q.get(1))) tag2 = true;
                if (Objects.equals(e.get(1), q.get(1))) tag2 = true;
            }
            return tag1 && tag2;
        }

//        public static void dfs(double[][] matrix, List<String> items, int i, int j) {
//            if (i == j) matrix[i][j] = 1;
//            else {
//
//            }
//        }

        public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
            List<String> items = new ArrayList<>();
            for (List<String> e : equations) {
                if (!items.contains(e.get(0))) items.add(e.get(0));
                if (!items.contains(e.get(1))) items.add(e.get(1));
            }
            Collections.sort(items);
            int n = items.size();
            double[][] matrix = new double[n][n];
            for (double[] vals : matrix) Arrays.fill(vals, -1);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) {
                        matrix[i][j] = 1;
                        continue;
                    }
                    List<String> equation = new ArrayList<>();
                    equation.add(items.get(i));
                    equation.add(items.get(j));
                    int idx = equations.indexOf(equation);
                    if (idx >= 0) {
                        matrix[j][i] = 1.0 / values[idx];
                        matrix[i][j] = values[idx];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j1 = 0; j1 < n; j1++) {
                    if (j1 == i || matrix[i][j1] == -1) continue;
                    for (int j2 = j1 + 1; j2 < n; j2++) {
                        if (j2 == i || matrix[i][j2] == -1) continue;
                        matrix[j1][j2] = matrix[i][j2] / matrix[i][j1];
                        matrix[j2][j1] = matrix[i][j1] / matrix[i][j2];
                    }
                }
            }// 到目前为止 所有能够被计算出来的都算出来了
            double[] ret = new double[queries.size()];
            for (int i = 0; i < queries.size(); i++) {
                List<String> q = queries.get(i);
                int i1 = items.indexOf(q.get(0));
                int i2 = items.indexOf(q.get(1));
                if (i1 < 0 || i2 < 0) ret[i] = -1;
                else ret[i] = matrix[i1][i2];
            }
            return ret;
        }

        public double cal_one(List<List<String>> equations, double[] values, List<String> q) {
            int known_num = equations.size();
            String t1 = q.get(0);
            String t2 = q.get(1);
            if (Objects.equals(t1, t2)) return 1;
            for (int i = 0; i < known_num; i++) {
                String e1 = equations.get(i).get(0);
                String e2 = equations.get(i).get(1);
                if (Objects.equals(e1, t1) && Objects.equals(e2, t2)) return values[i];
                if (Objects.equals(e1, t2) && Objects.equals(e2, t1)) return 1.0 / values[i];
                if (Objects.equals(e1, t1)) {
                    List<String> new_q = new ArrayList<>();
                    new_q.add(e2);
                    new_q.add(t2);
                    return values[i] * cal_one(equations, values, new_q);
                } else if (Objects.equals(e1, t2)) {
                    List<String> new_q = new ArrayList<>();
                    new_q.add(t1);
                    new_q.add(e2);
                    return cal_one(equations, values, new_q) / values[i];
                } else if (Objects.equals(e2, t1)) {
                    List<String> new_q = new ArrayList<>();
                    new_q.add(e1);
                    new_q.add(t1);
                    return cal_one(equations, values, new_q) / values[i];
                } else if (Objects.equals(e2, t2)) {
                    List<String> new_q = new ArrayList<>();
                    new_q.add(t1);
                    new_q.add(e1);
                    return values[i] * cal_one(equations, values, new_q);
                }
            }
            return -1;
        }

        public double[] calcEquation_1(List<List<String>> equations, double[] values, List<List<String>> queries) {
            double[] ret = new double[queries.size()];
            for (int i = 0; i < queries.size(); i++) {
                List<String> q = queries.get(i);
                if (valid(equations, q)) ret[i] = cal_one(equations, values, q);
                else ret[i] = -1;
            }
            return ret;
        }
    }
}
