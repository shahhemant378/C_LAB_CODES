// //3. Aim of the program- Write a Java class which has a method called
// ProcessInput(). This method checks the number entered by the user. If the
// entered number is negative then throw an user defined exception called
// NegativeNumberException, otherwise it displays the double value of the
// entered number.
// Input: Enter a number 4
// Output: Double value: 8
// Input: Enter a number -4
// Output: Caught the exception
// Exception occurred: NegativeNumberException: number

// should be
import java.util.*;
class NegativeNumberException extends Exception{
    NegativeNumberException(String s){
        super(s);
    }
}
class checker{ 
    int n;

    checker(int n){
        this.n=n;
    }

    public boolean isNeg(int n){
        if(n<0)
            return true;
        return false;
    }

}
public class user_definedException {
    public static void main(String[] args)throws NegativeNumberException {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        checker c=new checker(n);
        boolean ans=c.isNeg(n);

        if(ans){
            throw new NegativeNumberException("negative number");
        }else{
            System.out.println("Double value: "+
            (n+n));
        }
    }
}
