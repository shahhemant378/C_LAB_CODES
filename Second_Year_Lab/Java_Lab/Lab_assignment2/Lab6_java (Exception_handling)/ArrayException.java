//1. Aim of the program - Write a Java program to generate an
//ArrayIndexOutofBoundsException and handle it using catch statement.
//Input: Enter the numbers -Example: 1 2 3 4 5 ( Suppose array size is 4
//)
//Output: Exception in thread “main”
//java.lang.ArrayIndexOutOfBoundsException:4
import java.util.*;
public class ArrayException {
   public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    int[] arr=new int[4];
    System.out.println("Enter the index you want to store: ");
    int x=sc.nextInt();
    try{
        arr[x]=sc.nextInt();
    }catch(ArrayIndexOutOfBoundsException e){
        System.out.println(e);
    }

   } 
}
