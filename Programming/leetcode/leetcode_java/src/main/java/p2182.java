import java.util.Arrays;

public class p2182 {
    public static void main(String[] args) {
        Solutionp2182 s = new Solutionp2182();
        System.out.println(s.repeatLimitedString("xyutfpopdynbadwtvmxiemmusevduloxwvpkjioizvanetecnuqbqqdtrwrkgt", 1));
    }
}

/*
zyxyxwxwvwvuvuvututstrtrtqpqpqponononmlmkmkjigifiededededcbaba
zyxyxwxwvwvuvuvututstrtrtqpqpqponononmlmkmkjigifiededededcbaba

*/
class Solutionp2182 {
    public String repeatLimitedString(String s, int repeatLimit) {
        int[] charNum = new int[27];
        Arrays.fill(charNum, 0);
        for (int i = 0; i < s.length(); i++) {
            charNum[s.charAt(i) - 'a']++;
        }
        StringBuilder sb = new StringBuilder();
        int maxIndex = 25;
        while (maxIndex >= 0 && charNum[maxIndex] == 0)
            maxIndex--;
        int currentContinuous = 0;
        while (maxIndex >= 0) {
            char maxChar = (char) ('a' + maxIndex);
            while (charNum[maxIndex] > 0) {
                //if (currentContinuous < repeatLimit || maxChar != sb.charAt(sb.length() - 1)) sb.append(maxChar);
                sb.append(maxChar);
                if (sb.length() > 1 && sb.charAt(sb.length() - 2) == sb.charAt(sb.length() - 1))
                    currentContinuous++;
                else
                    currentContinuous = 1;
                while(currentContinuous>repeatLimit){
                    charNum[sb.charAt(sb.length()-1)-'a']++;
                    sb.deleteCharAt(sb.length()-1);
                    currentContinuous--;
                }
//                System.out.println("the sb: " + sb + ", the cc:" + currentContinuous);
                charNum[maxIndex]--;
                if (currentContinuous == repeatLimit) {
                    // find the sub char
                    int subMaxIndex = maxIndex - 1;
                    while (subMaxIndex >= 0 && charNum[subMaxIndex] == 0)
                        subMaxIndex--;
                    // if found then add it, else break
                    if (subMaxIndex >= 0) {
                        char subMaxChar = (char) ('a' + subMaxIndex);
                        sb.append(subMaxChar);
                        charNum[subMaxIndex]--;
                        currentContinuous = 1;
                    } else {
                        break;
                    }
                }
            }
            maxIndex--;
            while (maxIndex >= 0 && charNum[maxIndex] == 0)
                maxIndex--;
        }
        return sb.toString();
    }
}