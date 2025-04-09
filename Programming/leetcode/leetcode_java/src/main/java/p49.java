import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class p49 {
    public static void main(String[] args) {
        Solutionp49 s = new Solutionp49();
        s.groupAnagrams(new String[]{"eat", "tea", "tan", "ate", "nat", "bat"});
    }
}

class Solutionp49 {
    public int str2num(String s) {
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        int ret = 0;
        for (char c : chars)
            ret = ret * 27 + (int) c - 96;
        return ret;
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        int n = strs.length;
        HashMap<Integer, List<String>> mp = new HashMap<>();
        for (String str : strs) {
            int t = str2num(str);
            if (!mp.containsKey(t))
                mp.put(t, new ArrayList<>());
            mp.get(t).add(str);
        }
        List<List<String>> ret = new ArrayList<>();
        for (int k : mp.keySet()) ret.add(mp.get(k));
        return ret;
    }
}