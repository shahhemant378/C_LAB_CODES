//4. Aim of the program : Write a program in Java to take first name and last name
// from user and print both in one line as last name followed by first name

// Input: Enter first name: KIIT
// Enter Second Name: UNIVERSITY
// Output: UNIVERSITY KIIT
import java.util.Scanner;
public class first_Last_Swap {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter first name: ");
        String fName=sc.next();
        System.out.println("Enter Second name: ");
        String SName=sc.next();

        System.out.println(SName + " " + fName);

    }
}
