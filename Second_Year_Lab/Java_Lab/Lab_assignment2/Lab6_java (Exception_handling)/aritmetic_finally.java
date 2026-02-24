//2. Aim of the program- Write a Java program to handle an
//ArithmeticException using try, catch, and finally block.
//Input: Operand values for division operation mentioned in the program
//Output: ArithmeticException caught by try-catch-finally block
import java.util.*;
public class aritmetic_finally {
    public static void main(String[] args){
        int n=6;
        try{
            int x=n/0;
        }catch(ArithmeticException e){
            System.out.println(e);
        }finally{
            System.out.println("Arithmetic exception caught by try-catch-finally block");
        }
    }
}
