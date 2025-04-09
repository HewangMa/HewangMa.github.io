public class test {
    int x;
    public test(){
        x=10;
    }
    public void func() {
        System.out.println(x);
    }
    public static void main(String[] args){
        test Mytest=new test();
        Mytest.func();
    }
}