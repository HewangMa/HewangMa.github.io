import java.util.*;

public class p380 {
    static class RandomizedSet {

        private int idx;
        private List<Integer> vals;
        private HashMap<Integer, Boolean> exist;

        public RandomizedSet() {
            idx = 0;
            vals = new ArrayList<>();
            exist = new HashMap<>();
        }

        public boolean insert(int val) {
            if (exist.containsKey(val)) return false;
            else {
                vals.add(val);
                exist.put(val, true);
                return true;
            }
        }

        public boolean remove(int val) {
            if (!exist.containsKey(val)) return false;
            else {
                exist.remove(val);
                return true;
            }
        }

        public int getRandom() {
            Random r = new Random();
            Object[] vals = exist.keySet().toArray();
            int rand_idx = r.nextInt(vals.length);
            return (int) vals[rand_idx];
        }
    }

    public static void main(String[] args) {
        RandomizedSet test = new RandomizedSet();
        test.insert(2);
        test.insert(2);
        test.insert(3);
        test.insert(4);
        test.insert(2);
        test.remove(1);
        System.out.println(test.getRandom());
    }
}
