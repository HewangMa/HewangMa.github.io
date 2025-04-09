import java.util.ArrayList;
import java.util.List;

public class p121 {
    private static final int test_size = 15;
    private static int wins = 0;
    private static int loss = 0;
    private static int take_blue = 0;

    private static void track_back_with_ints(int turns, List<Integer> bag) {
        if (turns >= test_size) {
            int red = turns - take_blue;
            if (take_blue > red) wins++;
            else loss++;
            return;
        }
        for (int i = 0; i < bag.size(); i++) {
            if (bag.get(i) == 1) take_blue++;
            turns++;
            bag.add(0);
            track_back_with_ints(turns, bag);
            bag.remove(bag.size() - 1);
            turns--;
            if (bag.get(i) == 1) take_blue--;
        }
    }

    private static void track_back_with_sleep(List<Integer> takes, List<Integer> bag)
            throws InterruptedException {
        if (takes.size() >= test_size) {
            int blue = 0;
            for (int take : takes) blue += take;
            int red = takes.size() - blue;
            if (blue > red) {
                wins++;
                System.out.println("wins at " + takes);
                Thread.sleep(2000);
            } else loss++;
            return;
        }
        for (int i = 0; i < 2; i++) {
            int take = bag.get(i);
            // 进来一个红的，再随机丢一个，就相当于三种情况（由于包里一直只有两个disc）
            // 将bag[0]改为0
            // 将bag[1]改为0
            // 什么都不改
            for (int change_idx = 0; change_idx <= 2; change_idx++) {
                if (change_idx == 2) {
                    //这是不变的情况，注意回溯的固定格式
                    System.out.println("nothing changes");
                    Thread.sleep(2000);
                    takes.add(take);
                    System.out.println("take " + take);
                    Thread.sleep(2000);
                    track_back_with_sleep(takes, bag);
                    takes.remove(takes.size() - 1);
                } else {
                    int init_disc = bag.get(change_idx);
                    bag.set(change_idx, 0);
                    System.out.println("disc " + change_idx + ": " + init_disc + " is changed to 0");
                    Thread.sleep(2000);
                    takes.add(take);
                    System.out.println("take " + take);
                    Thread.sleep(2000);
                    track_back_with_sleep(takes, bag);
                    takes.remove(takes.size() - 1);

                    //再改回来
                    bag.set(change_idx, init_disc);
                }
            }
        }
    }

    private static void track_back_with_list(List<Integer> takes, List<Integer> bag) {
        if (takes.size() == test_size - 1) {
            // 只剩下一个需要处理了 那就不考虑第二三步
            for (int i = 0; i < 2; i++) {
                takes.add(bag.get(i));
                int blue = 0;
                for (int take : takes) blue += take;
                int red = takes.size() - blue;
                if (blue > red) wins++;
                else loss++;
                takes.remove(takes.size() - 1);
            }
            return;
        }
        for (int i = 0; i < 2; i++) {
            int take = bag.get(i);
            // 进来一个红的，再随机丢一个，就相当于三种情况（由于包里一直只有两个disc）
            // 将bag[0]改为0
            // 将bag[1]改为0
            // 什么都不改
            if (takes.isEmpty())
                System.out.println("for the first take i got " + take);
            if (takes.size() == 1)
                System.out.println("for the second take i got " + take + " and this line should appear six times");
            if (takes.size() == 2)
                System.out.println("for the third take i got " + take + " and this line should also appear six times");
            //遵循回溯的结构 push 递归 and pop
            takes.add(take);
            for (int change_idx = 0; change_idx <= 2; change_idx++) {
                // change_idx == 2 即为不对bag做任何修改的情况
                if (change_idx == 2) track_back_with_list(takes, bag);
                else {
                    int init_disc = bag.get(change_idx);
                    bag.set(change_idx, 0);
                    track_back_with_list(takes, bag);
                    bag.set(change_idx, init_disc);
                }
            }
            takes.remove(takes.size() - 1);
        }
    }

    private static void track_back_basic(List<Integer> takes, List<Integer> bag) {
        //此函数尝试不进行任何第二步和第三步调整，以检验回溯算法的正确性
        if (takes.size() >= test_size) {
            int blue = 0;
            for (int take : takes) blue += take;
            int red = takes.size() - blue;
            if (blue > red) wins++;
            else loss++;
            return;
        }
        for (int i = 0; i < 2; i++) {
            int take = bag.get(i);
            takes.add(take);
            track_back_basic(takes, bag);
            takes.remove(takes.size() - 1);
        }
    }

    private static void track_back_not_throw(List<Integer> takes, List<Integer> bag) {
        if (takes.size() >= test_size) {
            int blue = 0;
            for (int take : takes) blue += take;
            int red = takes.size() - blue;
            if (blue > red) wins++;
            else loss++;
            return;
        }
        for (int i = 0; i < bag.size(); i++) {
            int take = bag.get(i);
            bag.add(0);
            takes.add(take);
            track_back_not_throw(takes, bag);
            bag.remove(bag.size() - 1);
            takes.remove(takes.size() - 1);
        }
    }

    private static void track_back_fake(List<Integer> takes, List<Integer> bag) {
        //假的回溯
        if (takes.isEmpty()) {
            System.out.println();
            for (int i = 0; i < 2; i++) {
                int take = bag.get(i);
                for (int change_idx = 0; change_idx <= 2; change_idx++) {
                    if (change_idx == 2) {
                        takes.add(take);
                        track_back_fake(takes, bag);
                        takes.remove(takes.size() - 1);
                    } else {
                        int init = bag.get(change_idx);
                        bag.set(change_idx, 0);
                        takes.add(take);
                        track_back_fake(takes, bag);
                        takes.remove(takes.size() - 1);
                        bag.set(change_idx, init);
                    }
                }
            }
        } else if (takes.size() == 1) {

        } else if (takes.size() == 2) {

        } else if (takes.size() == 3) {

        } else {

        }
    }

    public static void solve_with_track_back() {
        List<Integer> bag = new ArrayList<>();
        bag.add(1);//blue disc
        bag.add(0);//red disc
        // 以下调用是主要的solution
        track_back_with_ints(0, bag);
        //运行完成之后已经得到了wins and loss
        System.out.println(wins + ", " + loss);
        // 需要找到
//        System.out.println("wins: " + wins + " loss: " + loss + " the rate: " + 1.0 * wins / (loss + wins) + " the proper rate is 11/120 for test_size==4");
    }


    private static List<List<Integer>> take_array;

    private static void generate_take_array(List<Integer> takes) {
        if (takes.size() == test_size) {
            take_array.add(new ArrayList<>(takes));
            return;
        }
        for (int i = 0; i < 2; i++) {
            takes.add(i);
//            if (i == 1) take_blue++;
            generate_take_array(takes);
            takes.remove(takes.size() - 1);
//            if (i == 1) take_blue--;
        }
    }

    private static void cal_list(String list) {
        // 第k（从0开始）次抽时，袋子里有1蓝 k+1红 蓝色的概率是1/（k+1）；
        int blue = 0;
        for (int i = 0; i < list.length(); i++) if (list.charAt(i) == '1') blue++;
        if (blue > test_size / 2) {
            for (int i = 0; i < list.length(); i++)
                if (list.charAt(i) == '1') wins += 1;
                else wins += (i + 1);
        } else {
            for (int i = 0; i < list.length(); i++)
                if (list.charAt(i) == '1') loss += 1;
                else loss += (i + 1);
        }
        System.out.print(list + ": ");
        System.out.println(blue + ", " + wins + ", " + loss);
    }

    public static void solve_with_binarys() {
//        take_array = new ArrayList<>();
//        generate_take_array(new ArrayList<>());
//        for (List<Integer> list : take_array) cal_list(list);
//        int total_num = 0;
        int binary_numbers = (int) Math.pow(2, test_size);
//        System.out.println(multiply);
//        for (int i = 0; i < test_size; i++) total_num += (i + 2);
//        total_num *= multiply;
//        System.out.println(total_num);
//        System.out.println(take_array.size());
        for (int i = 0; i < binary_numbers; i++) {
            StringBuilder list = new StringBuilder(Integer.toBinaryString(i));
            while (list.length() < test_size) list.insert(0, "0");
            cal_list(list.toString());
        }
        System.out.println(wins + ", " + loss);
    }


    private static void solve_dp() {
        long[][] dp = new long[test_size + 1][test_size + 1];
        // dp[i][j] 表示抽完第j（从1开始）次后积满i个blue的方式数
        // 我们要求的概率是
        // sum(dp[0..test_size][test_size]) / sum(dp[ceil(test_size/2)..test_size][test_size])
        // 在抽第j（从1开始）次前，袋子里有1蓝j红
        // dp[i][j] = dp[i-1][j-1]+dp[i][j-1]*j
        dp[0][0] = 0;
        dp[0][1] = 1;
        long win_ways = 0;
        long total_ways = 0;
        for (int j = 2; j <= test_size; j++) dp[0][j] = dp[0][j - 1] * j;
        for (int i = 1; i <= test_size; i++) dp[i][i] = 1;
        for (int i = 1; i <= test_size; i++)
            for (int j = i + 1; j <= test_size; j++)
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] * j;
        for (int i = 0; i <= test_size; i++) {
            if (i > test_size / 2) win_ways += dp[i][test_size];
            total_ways += dp[i][test_size];
        }
        double d = 1.0 * total_ways / win_ways;
//        x * win_ways > total_ways
        System.out.println(win_ways + ", " + total_ways);
        System.out.println(d);
    }

    public static void main(String[] args) {
        solve_dp();
    }
}
