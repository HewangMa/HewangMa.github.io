import java.util.ArrayList;
import java.util.Arrays;

public class p383 {
}

class Solutionp383 {
    public boolean canConstruct(String ransomNote, String magazine) {
        int i = 0, j = 0;
        int[] available = new int[27];
        Arrays.fill(available, 0);
        while (j < magazine.length())
            available[magazine.charAt(j++) - 'a']++;
        while (i < ransomNote.length()) {
            char c = ransomNote.charAt(i++);
            if (available[c - 'a'] > 0) available[c - 'a']--;
            else return false;
        }
        return true;
    }

    public boolean canConstruct2(String ransomNote, String magazine) {
        int i = 0, j = 0;
        while (i < ransomNote.length() && j < magazine.length()) {
            if (ransomNote.charAt(i) == magazine.charAt(j)) {
                i++;
                j++;
            } else j++;
        }
        return i == ransomNote.length();
    }
}