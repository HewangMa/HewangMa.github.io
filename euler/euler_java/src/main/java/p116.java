import java.math.BigInteger;

public class p116 {
    private static int test_size = 50;

//    private static int sum = 0;
//
//    private static void track_back(int[] tiles, int start_idx) {
//        if (sum >test_size)
//    }

    public static void main(String[] args) {
        BigInteger ways = new BigInteger("0");
        BigInteger[] fac = new BigInteger[test_size + 1];
        fac[0] = new BigInteger("1");
        for (int i = 1; i <= test_size; i++) fac[i] = fac[i - 1].multiply(new BigInteger(Integer.toString(i)));
        int red_num = 1;
        while (red_num * 2 <= test_size) {
            int gray = test_size - red_num * 2;
            ways = ways.add(fac[gray + red_num].divide(fac[gray]).divide(fac[red_num]));
            red_num++;
        }
        int green_num = 1;
        while (green_num * 3 <= test_size) {
            int gray = test_size - green_num * 3;
            ways = ways.add(fac[gray + green_num].divide(fac[gray]).divide(fac[green_num]));
            green_num++;
        }
        int blue_num = 1;
        while (blue_num * 4 <= test_size) {
            int gray = test_size - blue_num * 4;
            ways = ways.add(fac[gray + blue_num].divide(fac[gray]).divide(fac[blue_num]));
            blue_num++;
        }
        System.out.println(ways);
    }
}
