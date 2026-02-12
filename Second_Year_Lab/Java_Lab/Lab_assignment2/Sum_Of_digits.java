// 5. Aim of the program : Take a number from the user and calculate the sum of its
// digits using a while loop.

// Input: Enter the number: 192
// Output: 12

import java.util.Scanner;

public class Sum_Of_digits {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number: ");
        int num=sc.nextInt();
        int sum=0;
        while(num>0){
            int rem=num%10;
            sum=sum+rem;
            num=num/10;
        }
        System.out.println("The sum of digit is : "+sum);
    }
}
