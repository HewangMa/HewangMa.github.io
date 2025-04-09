import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedHashMap;

public class p128 {
    public static void main(String[] args) {
        Solutionp128 s = new Solutionp128();
        System.out.println(s.longestConsecutive(new int[]{9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6}));
    }

    public static void test() {
        HashMap<String, Integer> hashMap = new HashMap<>();
        hashMap.put("Z", 1);
        hashMap.put("A", 2);
        hashMap.put("C", 3);
        hashMap.put("B", 4);
        LinkedHashMap<String, Integer> linkedHashMap = new LinkedHashMap<>(hashMap);
        String[] keysArray = linkedHashMap.keySet().toArray(new String[0]);
        System.out.println("按顺序排列的键数组: " + Arrays.toString(keysArray));
    }
}

class Solutionp128 {
    public int longestConsecutive(int[] nums) {
        if (nums.length <= 1)
            return nums.length;
        HashMap<Integer, Integer> cnt = new HashMap<>();
        int minNum = nums[0];
        int maxNum = nums[0];
        for (int num : nums) {
            if (!cnt.containsKey(num))
                cnt.put(num, 1);
            minNum = Math.min(minNum, num);
            maxNum = Math.max(maxNum, num);
        }
        int i = minNum;
        int maxLength = 1;
        for (int n : nums) {
            if (cnt.containsKey(n - 1)) continue;
            int curLength = 1;
            while (curLength <= nums.length) {
                if (cnt.containsKey(n + curLength))
                    curLength += 1;
                else break;
            }
            maxLength = Math.max(maxLength, curLength);
        }
        return maxLength;
    }
}
