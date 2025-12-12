// 2. Aim of the program: Write a program to print the week day for the given day no.
// of the current month using switch case statement
// Input: Mention the Day no in the program
// Output: Display the week day(either
// Sunday/Monday/Tuesday/Wednesday /Thursday/Friday/Saturday)
import java.util.Scanner;
public class WeekDay {
    public static void main(String[] args) {
        //considering 0 as monday
        Scanner sc=new Scanner(System.in);
        System.out.println("Mention the Day no in the program: ");
        int dayNo=sc.nextInt();
       

        if(dayNo>30){
            System.out.println("please enter below 30 in a month there are 30 days");
            
        }else{
             dayNo=dayNo%7;
        switch (dayNo) {
            case 0:
                System.out.println("Sunday");
                break;
            case 1:
                System.out.println("Monday");
                break;
            case 2:
                System.out.println("Tuesday");
                break;
            case 3:
                System.out.println("Wednesday");
                break;
            case 4:
                System.out.println("Thrusday");
                break;
            case 5:
                System.out.println("Friday");
                break;
            case 6:
                System.out.println("Saturday");
                break;
                
            default:
                break;
        }
    }

    }
    
}
