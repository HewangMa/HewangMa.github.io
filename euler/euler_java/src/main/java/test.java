public class test {
    private static void back_tracking_(){
        // ... basic back tracking frame here.
    }
    private static void back_tracking(){
        try {
            back_tracking_();
        } catch (ArithmeticException error) {
            System.out.println("got ans");
            error.printStackTrace();
        }
    }
    public static void main(String[] args) {
        back_tracking();
    }
}
