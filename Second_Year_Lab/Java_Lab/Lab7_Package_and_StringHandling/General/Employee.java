package C_LAB_CODES.Second_Year_Lab.Java_Lab.Lab7_Package_and_StringHandling.General;

public class Employee {
   protected int empid;
   private  String ename;
   public static int basicSalary;
   public static int earnings(){
    
    
    
    int totalEarning=basicSalary+(80/100)*basicSalary+(15/100)*basicSalary;
    return totalEarning;

   }  

   public Employee(int empid,String ename,int basicSalary){
    this.empid=empid;
    this.ename=ename;
    this.basicSalary=basicSalary;
   }
}
