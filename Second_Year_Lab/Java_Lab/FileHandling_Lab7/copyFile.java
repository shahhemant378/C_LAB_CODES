/*2. Aim of the program - Write a program in Java to copy the content of a given
file to another user entered file using character stream (using File Reader
and FileWriter Classes) and byte Stream (using FileInputStream and
FileOutputStream Class).
Input: Enter the source file name - sourcefile.txt (Assume Input file
exists in the system)
Enter the destination file name - destinationfile.txt
Output: File Copied*/
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

import java.io.FileInputStream;
public class copyFile {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String givenFile="details.txt";

        System.out.println("Enter the file name where you want to copy: ");
        String destFile=sc.nextLine();

        try{
            FileReader fr=new FileReader(givenFile);
            FileWriter fw=new FileWriter(destFile);
            int i;
            while((i=fr.read())!=-1){
                fw.write((char)i);
            }
            fw.close();
            fr.close();
        }catch(Exception e){
            System.out.println(e);
        }finally{
            System.out.println("File copide to "+destFile);
        }


        //byte Stream (using FileInputStream and FileOutputStream Class)

         System.out.println("Enter the file name where you want to copy: ");
        destFile=sc.nextLine();

        

    }
}
