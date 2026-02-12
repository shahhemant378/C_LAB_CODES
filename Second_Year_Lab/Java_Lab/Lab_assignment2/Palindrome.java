// 3. Aim of the program : Program to check a user entered number is palindrome or
// not

// Input: Mention the number in the program
// Output: display the number is Palindrome or not.
import java.util.Scanner;
public class Palindrome {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Mention the number in the Program: ");
        int num=sc.nextInt();
        int temp=num;
        int sum=0;
        while(temp>0){
            int rem=temp%10;
            sum=sum*10+rem;
            temp=temp/10;
        }

        if(sum==num){
            System.out.println("Palindrome");
        }else{
            System.out.println("Not a palindrome");
        }
    }
}
