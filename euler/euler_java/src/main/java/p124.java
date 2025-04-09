import java.util.*;

public class p124 {
    private static int rad(int n) {
        int proc = 1;
        int i = 2;
        HashSet<Integer> facs = new HashSet<>();
        while (i <= n) {
            if (n % i == 0) {
                n /= i;
                facs.add(i);
            } else i++;
        }
        for (int fac : facs) {
//            System.out.print(fac + ", ");
            proc *= fac;
        }
//        System.out.println();
        return proc;
    }

    public static void main(String[] args) {
        List<List<Integer>> list = new ArrayList<>();
        for (int i = 1; i <= 100000; i++) {
            List<Integer> pair = new ArrayList<>();
            pair.add(i);
            pair.add(rad(i));
            list.add(pair);
        }
        Collections.sort(list, new comp());
        System.out.println(list.get(10000 - 1).get(0));
//        for (List<Integer> pair : list) System.out.println(pair);
    }
}

class comp implements Comparator<List<Integer>> {
    @Override
    public int compare(List<Integer> list1, List<Integer> list2) {
        int second = list1.get(1).compareTo(list2.get(1));
        if (second == 0) return list1.get(0).compareTo(list2.get(0));
        else return second;
    }
}
