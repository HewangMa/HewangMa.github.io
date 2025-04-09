import com.sun.javaws.IconUtil;

public class p120 {
    // 二项式展开即可
    public static void main(String[] args) {
        int sum = 0;
        for (int a = 3; a <= 1000; a++) {
            int n = 0;
            if (a % 2 == 0) n = (a - 2) / 2;
            else n = (a - 1) / 2;
            sum += 2 * n * a;
        }
        System.out.println(sum);
    }
}
