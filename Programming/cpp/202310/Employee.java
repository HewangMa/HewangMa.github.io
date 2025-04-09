import java.io.*;
public class Employee {
    String name;
    int age;
    String designation;
    double salary;
    public Employee(String name,int age, String designation, double salary){
        this.name=name;
        this.designation=designation;
        this.age=age;
        this.salary=salary;
    }
    public void print() {
        System.out.println("名字"+name);
    }
}
