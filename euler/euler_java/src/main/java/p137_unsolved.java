import java.math.BigInteger;

public class p137_unsolved {
    private static void run() {
        BigInteger odd_sum = BigInteger.ONE;
        BigInteger odd = new BigInteger("3");
        BigInteger five = new BigInteger("5");
        BigInteger two = new BigInteger("2");
        int cnt = 0;
        for (BigInteger a = new BigInteger("1"); ; a = a.add(BigInteger.ONE)) {
            BigInteger p = a.multiply(a).multiply(five).add(a.multiply(two)).add(BigInteger.ONE);
            while (p.compareTo(odd_sum) > 0) {
                odd_sum = odd_sum.add(odd);
                odd = odd.add(two);
            }
            if (p.equals(odd_sum)) {
                System.out.println(a);
                cnt++;
                if (cnt >= 15) break;
            }
        }
        /*
        2
        15
        104
        714
        4895
        33552
        229970
        1576239
        10803704
        74049690
        507544127
        3478759200
         */
    }

    public static void main(String[] args) {
        run();
    }
}
