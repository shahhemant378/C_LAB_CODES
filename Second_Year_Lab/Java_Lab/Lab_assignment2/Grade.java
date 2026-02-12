
// 1. Aim of the program: Write a program to print the corresponding grade for the
// given mark using if..else statement in Java
// Input: Mention the grade in the program
// Output: Display the Grade either O/E/A/B/C

import java.util.Scanner;
class Grade{
    public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    System.out.println("Mention the grade in the program");
    int grade=sc.nextInt();

    if(grade>=90){
        System.out.println("O");
    }else if(grade >=80 && grade<90){
        System.out.println("E");
    }else if(grade >=70 && grade<80){
        System.out.println("A");
    }else if(grade >=60 && grade <69){
        System.out.println("B");
    }else{
        System.out.println("C");
    }
    }
}
