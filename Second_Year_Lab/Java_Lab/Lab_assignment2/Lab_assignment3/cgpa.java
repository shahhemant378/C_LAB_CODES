//5) WAP to input and display the details of n number of students having
//roll,name and cgpa as data members.
//Also display the name of the student having lowest cgpa.
//Input: Enter Roll No,Name and cgpa of 'n' number of students.
//Output: Display the details of 'n' number of students.Also display the name of student with lowest cgpa

import java.util.ArrayList;
import java.util.Scanner;

class Student{
    int rollNO;
    String name;
    double cgpa;

    Student(int r, String n,double cgpa){
        this.rollNO=r;
        this.name=n;
        this.cgpa=cgpa;
    }
}
public class cgpa {
   public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);

    System.out.println("enter the n :");
    int n=sc.nextInt();

    Student[] arr=new Student[n];

    System.out.println("Enter the details rollNo , name and cgpa");
    
    for(int i=0;i<n;i++){
        int rollNO =sc.nextInt();
        String name=sc.next();
        double cgpa=sc.nextDouble();
        arr[i]=new Student(rollNO, name, cgpa);
    }
System.out.println("The student are : ");
for(int i=0;i<n;i++){
    Student s=arr[i];
    System.out.println("The Rollno: "+arr[i].rollNO);
    System.out.println("The name: "+arr[i].name);
    System.out.println("The cgpa: "+arr[i].cgpa);
    System.out.println();
   
}


double minCgpa=arr[0].cgpa;
String lowName=arr[0].name;

for(int i=1;i<n;i++){
    if(arr[i].cgpa<minCgpa){
        minCgpa=arr[i].cgpa;
        lowName=arr[i].name;
    }
}
    System.out.println("Student with lowest CGPA: "+lowName);

   } 
}
