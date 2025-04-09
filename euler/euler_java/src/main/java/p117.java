import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class p117 {
    private static int test_size = 50;
    private static int sum = 0;
    private static List<List<Integer>> tile_list;

    private static void track_back(List<Integer> tiles, int start_idx) {
        if (sum > test_size) return;
        tile_list.add(new ArrayList<>(tiles));
        for (int tile = start_idx; tile <= 4; tile++) {
            tiles.add(tile);
            sum += tile;
            track_back(tiles, tile);
            tiles.remove(tiles.size() - 1);
            sum -= tile;
        }
    }

    public static void main(String[] args) {
        BigInteger ans = new BigInteger("0");

        BigInteger[] fac = new BigInteger[test_size + 1];
        fac[0] = new BigInteger("1");
        for (int i = 1; i <= test_size; i++) fac[i] = fac[i - 1].multiply(new BigInteger(Integer.toString(i)));

        tile_list = new ArrayList<>();
        track_back(new ArrayList<>(), 2);
        for (List<Integer> list : tile_list) {
            int gray = test_size;
            for (int tile : list) gray -= tile;
            BigInteger way = fac[gray + list.size()].divide(fac[gray]);
            int repeat = 1;
            int i = 1;
            while (i < list.size()) {
                if (Objects.equals(list.get(i), list.get(i - 1))) repeat++;
                else {
                    way = way.divide(fac[repeat]);
                    repeat = 1;
                }
                i++;
            }
            way = way.divide(fac[repeat]);
            ans = ans.add(way);
        }
        System.out.println(ans);
    }
}
