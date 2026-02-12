//4) Write a program in java to create a class Rectangle 
//having data members length and breadth and three methods called read,
//calculate and display to read the values of length and breadth, calculae the
//area and perimeter of the rectangle and display the result respectively
import java.util.*;
public class Rectangle {
    public static int length, breadth;
    static void read(){
        System.out.println("Length: " +length);
        System.out.println("Breadth: " +breadth);
    }
    static int calculateArea(){
        return length*breadth;
    }
    static int calculatePerimeter(){
        return 2*(length+breadth);
        
    }
    static void display(){
        System.out.println("The area is: " + calculateArea());
        System.out.println("The perimenter is : "+calculatePerimeter());

    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        
        System.out.println("Enter length and breadth : ");
        length=sc.nextInt();
        breadth=sc.nextInt();

        read();
        calculateArea();
        calculatePerimeter();
        display();

    }
}
