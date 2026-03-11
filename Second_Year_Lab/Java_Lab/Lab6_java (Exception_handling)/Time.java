// //4. Aim of the Program: Write a program to create user defined exceptions
// called HrsException, MinException and SecException. Create a class Time
// which contains data members hours, minutes, seconds and a method to take
// a time from user which throws the user defined exceptions if hours (>24
// &<0),minutes(>60 &<0),seconds(>60 &<0).
// Input: Enter hours: 4
// Enter minutes: 54
// Enter seconds: 34
// Output: Correct Time-> 4:54:34
// Input: Enter hours: 30
// Enter minutes: 65
// Enter seconds: 65
// Output: Caught the exception
// Exception occurred: InvalidHourException:hour is not greater
// than 24
// Exception occurred: InvalidMinuteException:hour is not
// greater than 60

// Exception occurred: InvalidSecondException:hour is not
// greater than 60
import java.util.*;
class HrsException extends Exception{
    HrsException(String s){
        super(s);
    }
}
class MinException extends Exception{
    MinException(String s){
        super(s);
    }
}
class SecException extends Exception{
    SecException(String s){
        super(s);
    }
}
public class Time{

    public static void checker(int h,int m,int s){
        boolean hasError=false;

        try{
            if(h>24 || h<0){
            throw new HrsException("Hour is not greater than 24 or less than zero");
             }
        }catch(HrsException e){
            System.out.println("Exception occured: "+e.getMessage());
            hasError=true;
        }

        try{
             if(m>60 || m<0){
            throw new MinException("Minute should not greater than 60 or less than zero ");
            }
        }catch(MinException e){
            System.out.println("Exception occured: "+e.getMessage());
             hasError=true;
        }

            try{
                if(s>60 || s<0){
            throw new SecException("Second should not greater than 60 or less than zero");
              }

            }catch(SecException e){
                System.out.println("Exception occured: "+e.getMessage());
                hasError=true;
            }
            if(!hasError)
            System.out.println("correct Time :"+h+":"+m+":"+s);
            else
                System.out.println("Caught the exception");
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter hours: ");
        int h=sc.nextInt();
         System.out.println("Enter minutes: ");
        int m=sc.nextInt();
         System.out.println("Enter seconds: ");
        int s=sc.nextInt();

        
            checker(h, m, s);
        


    }
}
