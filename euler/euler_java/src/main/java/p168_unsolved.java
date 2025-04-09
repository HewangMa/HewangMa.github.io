public class p168_unsolved {
    private static boolean rotatable(long n) {
        StringBuilder sb = new StringBuilder(String.valueOf(n));
        sb.insert(0, sb.charAt(sb.length() - 1));
        sb.deleteCharAt(sb.length() - 1);
        long rotate = Long.parseLong(sb.toString());
        return rotate != n && rotate >= n && rotate % n == 0;
    }

    public static void main(String[] args) {
        int[] base = new int[]{102564, 128205, 142857, 153846, 179487, 205128, 230769};
        // 这些数字和任意数量的自身连接起来都符合要求的性质（这是先用rotatable函数求得的）；
//        for (long i = 100000000000l; i < 1000000000000l; i++)
//            if (rotatable(i))
//                System.out.println(i);
        int ans = 0;
        for (int digit = 1; digit <= 9; digit++) {
            StringBuilder sb = new StringBuilder();
            sb.append(digit);
            for (int i = 0; i < 4; i++) {
                sb.append(digit);
                System.out.print(sb + ", ");
                ans = (ans + Integer.parseInt(sb.toString())) % 100000;
            }
//            System.out.println(Integer.parseInt(sb.toString()));
            ans = (ans + Integer.parseInt(sb.toString()) * 95) % 100000;
        }
        for (int i = 0; i < base.length; i++) ans = (ans + base[i] * 16) % 100000;
        System.out.println(ans);
    }
}
