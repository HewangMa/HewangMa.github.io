import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Enumeration;

public class p78 {
    private final static int target_testSize = 1000000;
    private final static int testSize = 99999;

    public static void main(String[] args) {
        p78.solve2();
    }

    public static void solve1() {
        Poly p = new Poly(1);
        for (int num = 2; num <= testSize; num++) {
            Poly pn = new Poly(num);
            p.multiply(pn);
            if (p.get(num).remainder(new BigInteger("100")).equals(BigInteger.ZERO))
                System.out.println(num + ": " + p.get(num));
        }
    }

    public static void solve2() {
        BigInteger[] p = new BigInteger[testSize];
        Arrays.fill(p, BigInteger.ZERO);
        p[0] = BigInteger.ONE;
        for (int i = 1; i < testSize; i++)
            for (int j = i; j < testSize; j++)
                p[j] = p[j].add(p[j - i]);
        for (int i = 0; i < testSize; i++)
            if (p[i].remainder(new BigInteger("10000")).equals(BigInteger.ZERO))
                System.out.println(i + ": " + p[i]);
        //the ans:
        //55374: 36325300925435785930832331577396761646715836173633893227071086460709268608053489541731404543537668438991170680745272159154493740615385823202158167635276250554555342115855424598920159035413044811245082197335097953570911884252410730174907784762924663654000000
    }
}


class Poly {
    private final static int poly_size = 10000;
    BigInteger[] co = new BigInteger[poly_size + 1];

    Poly(int mul) {
        for (int i = 0; i <= poly_size; i++)
            if (i % mul == 0)
                co[i] = BigInteger.ONE;
            else
                co[i] = BigInteger.ZERO;
    }

    void multiply(Poly p) {
        BigInteger[] ret = new BigInteger[poly_size + 1];
        for (int i = 0; i <= poly_size; i++)
            ret[i] = BigInteger.ZERO;
        for (int i = 0; i <= poly_size; i++)
            for (int j = 0; j <= poly_size && i + j <= poly_size; j++)
                ret[i + j] = ret[i + j].add(this.co[i].multiply(p.co[j]));
        System.arraycopy(ret, 0, co, 0, poly_size + 1);
    }

    void print() {
        for (int i = 0; i <= poly_size; i++)
            System.out.print(co[i] + " ");
        System.out.println();
    }

    BigInteger get(int index) {
        return co[index];
    }
};