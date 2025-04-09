package prac01;
import java.util.Random;

public class random_test {
    public static void main(String[] args) {
        for (int i=0;i<10;i++){
            Random r=new Random();
            int data=r.nextInt(10);
            System.out.println(data);
        }
    }
}
