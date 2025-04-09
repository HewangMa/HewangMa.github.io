import java.util.HashMap;

public class p2085 {
}

class Solutionp2085 {
    int hash(String s) {
        int base = 1;
        int ret = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            ret += base * (s.charAt(i) - 'a');
            base *= 26;
        }
        return ret;
    }

    public int countWords(String[] words1, String[] words2) {
        HashMap<String, Integer> mp1 = new HashMap<>(), mp2 = new HashMap<>();
        for (int i = 0; i < words1.length; i++) {
            if (mp1.containsKey(words1[i])) mp1.put(words1[i], mp1.get(words1[i]) + 1);
            else mp1.put(words1[i], 1);
        }
        for (int i = 0; i < words2.length; i++) {
            if (mp2.containsKey(words2[i])) mp2.put(words2[i], mp2.get(words2[i]) + 1);
            else mp2.put(words2[i], 1);
        }
        int ret=0;
        for (String key: mp1.keySet()){
            if(mp1.get(key)==1 && mp2.containsKey(key) && mp2.get(key)==1)ret++;
        }
        return ret;
    }
}
