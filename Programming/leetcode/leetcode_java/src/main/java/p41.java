import java.util.Arrays;

public class p41 {
    public static void main(String[] args) {
        System.out.println(new Solutionp41().firstMissingPositive(new int[]{3, 4, -1, 1}));
    }
}

class Solutionp41 {
    public int firstMissingPositive(int[] nums) {
        Boolean[] positiveNums = new Boolean[500001];
        Arrays.fill(positiveNums, false);
        for (int num : nums)
            if (1 <= num && num <= 500000) positiveNums[num] = true;
        for (int i = 1; i <= 500000; i++)
            if (!positiveNums[i]) return i;
        return 500001;
    }
}