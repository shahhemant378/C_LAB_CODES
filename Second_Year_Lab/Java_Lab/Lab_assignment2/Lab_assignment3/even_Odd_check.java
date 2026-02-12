//1) Accept 10 numbers from command line and check how many of them are even and how many are odd.
//input: Enter 10 number from keyboard
//output: Display number of even and odd number
import java.util.*;
public class even_Odd_check {
    public static void main(String[] args) {
        int[] arr =new int[10];
        Scanner sc=new Scanner(System.in);
        for(int i=0;i<10;i++){
            arr[i]=sc.nextInt();
        }
        int even=0;
        int odd=0;
        for(int i=0;i<10;i++){
            if(arr[i]%2==0){
                even++;
            }else{
                odd++;
            }
        }

        System.out.println("even is : "+ even);
        System.out.println("Odd is :"+ odd);
    }
}