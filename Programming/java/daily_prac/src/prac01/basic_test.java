package prac01;

import java.time.LocalDate;
import java.util.Date;
import java.util.Scanner;

public class basic_test {

    public static void main(String[] args) {
        testDateTimeAPI();
    }

    public static void ScannerTest() {
        Scanner sc = new Scanner(System.in);
        System.out.println("分别输入机票的原价:double、月份:int 和机舱等级:string");
        double init_price = sc.nextDouble();
        int month = sc.nextInt();
        String level = sc.next();
        double uti_price = compute_price(init_price, month, level);
        System.out.println(uti_price);
    }

    /**
     * 用于根据初试价格等信息计算最终价格
     *
     * @param init_price： 初始价格
     * @param month：月份信息
     * @param level：仓等级
     * @return double
     */
    public static double compute_price(double init_price, int month, String level) {
        if (month >= 5 && month <= 10) {
            //旺季
            if (level.equals("high")) init_price *= 0.6;
            else init_price *= 0.7;
        } else {
            if (level.equals("high")) init_price *= 0.5;
            else init_price *= 0.6;
        }
        return init_price;
    }

    public static void testTime() {
        long startTime=System.currentTimeMillis();
        for (int i=0;i<100000;i++){
            System.out.println("输出" + i);
        }
        long endTime = System.currentTimeMillis();
        System.out.println((endTime-startTime)/1000.0 + "s");
    }

    public static void testDateTimeAPI(){
        LocalDate date = LocalDate.now();
        System.out.println(date);
    }
}
