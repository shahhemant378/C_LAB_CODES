// 6. Aim of the program: Program to sort the user entered list of numbers of any
// size
// Input: List of Numbers
// Output: Display the numbers in Ascending order
import java.util.*;
public class Sorting {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.print("Enter the size: ");
        int size=sc.nextInt();
        int[] arr=new int[size];
        for(int i=0;i<size;i++){
            arr[i]=sc.nextInt();
        }

        Arrays.sort(arr);
        System.out.println("Sorted List are: ");
        for(int i=0;i<size;i++){
            System.out.print(" " + arr[i]);
        }

    }
}
