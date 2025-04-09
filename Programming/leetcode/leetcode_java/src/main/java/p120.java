import com.sun.java.swing.plaf.windows.WindowsTextAreaUI;

import java.util.ArrayList;
import java.util.List;

public class p120 {
    public static List<List<Integer>> parseMatrix(String s) {
        List<List<Integer>> result = new ArrayList<>();
        s = s.substring(1, s.length() - 1);
        System.out.println(s);
        // 去掉首尾的方括号，然后按逗号分割为行
        String[] rows = s.substring(1, s.length() - 1).split("],");

        for (String row : rows) {
            List<Integer> rowList = new ArrayList<>();
            // 去掉每行的方括号，然后按逗号分割为元素
            String[] elements = row.substring(1, row.length()).split(",");
            for (String element : elements) {
                rowList.add(Integer.parseInt(element.trim()));
            }
            result.add(rowList);
        }

        return result;
    }

    static class Solution {
        public static int minimumTotal(List<List<Integer>> triangle) {
            int n = triangle.size();
            int[] m1 = new int[n];
            int[] m2 = new int[n];
            for (int i = 0; i < triangle.size(); i++) {
                List<Integer> row = triangle.get(i);
                System.out.println();
                System.out.println("row: " + row);
                System.out.print("m1: ");
                for (int one : m1) System.out.print(one + ", ");
                System.out.println();

                for (int j = 0; j < row.size(); j++) {
                    if (j == 0) m2[j] = m1[j] + row.get(j);
                    else if (j == row.size() - 1) m2[j] = m1[j - 1] + row.get(j);
                    else m2[j] = Math.min(m1[j - 1], m1[j]) + row.get(j);
                }
                System.out.print("m2: ");
                for (int one : m2) System.out.print(one + ", ");
                System.out.println();

                int[] t = m1;
                m1 = m2;
                m2 = t;
            }
            int ans = Integer.MAX_VALUE;
            for (int i = 0; i < m1.length; i++)
                if (m1[i] < ans)
                    ans = m1[i];
            System.out.println(ans);
            return ans;
        }
    }

    public static void main(String[] args) {
        String s = "[[-7],[-2,1],[-5,-5,9],[-4,-5,4,4],[-6,-6,2,-1,-5],[3,7,8,-3,7,-9],[-9,-1,-9,6,9,0,7],[-7,0,-6,-8,7,1,-4,9],[-3,2,-6,-9,-7,-6,-9,4,0],[-8,-6,-3,-9,-2,-6,7,-5,0,7],[-9,-1,-2,4,-2,4,4,-1,2,-5,5],[1,1,-6,1,-2,-4,4,-2,6,-6,0,6],[-3,-3,-6,-2,-6,-2,7,-9,-5,-7,-5,5,1]]";
        List<List<Integer>> p = parseMatrix(s);
        for (List<Integer> one : p) System.out.println(one);
//        Solution.minimumTotal(p);
    }
}
