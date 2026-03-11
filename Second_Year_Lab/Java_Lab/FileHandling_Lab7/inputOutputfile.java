/*1. Aim of the program - Write a java program which will accept students details
like Student RollNo, Name, Subject, Marks from the keyboard using scanner
class, stored the same in a file. Again open the file, read the content and
display all.
Input: Enter student details - Rollno, name, subject, marks
Enter the name of existing file to which student details will be written.
Output: Display the content of existing file*/

import java.util.Scanner;

import javax.security.auth.Subject;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
public class inputOutputfile {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the Student Rollno");
        int rollNO=sc.nextInt();
        System.out.println("Enter the name: ");
        sc.nextLine();
        String name=sc.nextLine();
        System.out.println("Enter the Student subject: ");
        String subject=sc.nextLine();
        System.out.println("Enter the Student marks:");
        int marks=sc.nextInt();
        
        sc.nextLine();
        System.out.println("Enter the file name where you want to store the details in (.txt): ");
        String fileWriting=sc.nextLine();


        try{
            FileWriter fw=new FileWriter(fileWriting);
            fw.write(rollNO+" "+name+" "+subject+" "+marks);
            fw.close();
        }catch(Exception e){
            System.out.println("Success....");
        }


        System.out.println("The context in the file : "+fileWriting+"are:");

        try{
            FileReader fr=new FileReader(fileWriting);
            int i;
            while((i=fr.read())!=-1){
                System.out.print((char)i);
            }
            fr.close();
        }catch(Exception e){
            System.out.println(e);
        }
    }
}
