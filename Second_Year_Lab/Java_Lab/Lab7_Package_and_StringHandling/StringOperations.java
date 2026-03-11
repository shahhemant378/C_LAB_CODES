package C_LAB_CODES.Second_Year_Lab.Java_Lab.Lab7_Package_and_StringHandling;
import java.util.Scanner;
public class StringOperations {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the String: ");
        String s=sc.nextLine();

        //Change the case of the string
        System.out.println("The string after changing the case is "+s.toUpperCase());
        
        //Reverse the string
        StringBuilder sb=new StringBuilder(s);
        sb.reverse();
        System.out.println("The string after reversing is "+sb);
        System.out.println();
        //Compare two strings
        System.out.print("Enter the second string for comparision: ");
        String newString=sc.nextLine();

        if(s.equals(newString)){
            System.out.println("The strings is equal");
        }else{
            System.out.println("The string are not equal");
        }
       System.out.println();
        //Insert one string into another string
        System.out.print("Enter the string to be inserted into  first string: ");
        String newString2=sc.nextLine();
        String result = s.concat(" "+newString2);
        System.out.println("The string after insertion is : "+result);
        System.out.println();
        //Convert the string to upper case and lower case
        System.out.print("Enter the String: ");
        String snew=sc.nextLine();

        System.out.println("UpperCase: "+snew.toUpperCase());
        System.out.println("LowerCase: "+snew.toLowerCase());
        System.out.println();
        //Check whether the character is present in the string and at which position
        System.out.print("Enter the String: ");
        String snew1=sc.nextLine();
        System.out.print("Enter the Character: ");
        char c=sc.next().charAt(0);
        boolean isfound=false;
        for(int i=0;i<snew1.length();i++){
            if(snew1.charAt(i)==c){
                System.out.println("Position of entered charcter : "+(i+1));
                isfound=true;
                break;
            }     
        }
        if(isfound==false)
            System.out.println("Entered character is not present");

        System.out.println();
        //palindrome checker
        sc.nextLine(); 
        boolean isPalindrome=true;
        System.out.print("Enter a String: ");
        String snew2=sc.nextLine();
        int strlength=snew2.length();
        int half=strlength/2;
        for(int i=0;i<half;i++){
            if(snew2.charAt(i)!=snew2.charAt(strlength-i-1)){
                System.out.println("Enterd string is not a palindrome");
                isPalindrome=false;
                break;
            }
        }
        if(isPalindrome==true)
            System.out.println("Entered string is a palindrome");
        System.out.println();
        //words , vowels and consonants

        System.out.print("Enter the String: ");
        String snew3=sc.nextLine();
        String snew3Lower=snew3.toLowerCase();
        int words=1;
        int vowels=0;
        int consonants=0;
        int snewlength=snew3.length();
            
        for(int i=0;i<snewlength;i++){
            char ch = snew3Lower.charAt(i);
             if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                vowels++;
            }else if(ch>='a' && ch<='z'){
                consonants++;
            }

            if(ch==' '){
                words++;
            }
        }

        System.out.println("No of words: "+words);
        System.out.println("No of vowels: "+vowels);
        System.out.println("No of consonants: "+consonants);





    }
}
