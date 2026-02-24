package Marketing;
import General.Employee;
import java.util.Scanner;
public class Sales extends Employee{
    public static int tallowance(){
        int totalEarning=earnings();
        int travellingAllowance=(5/100)*totalEarning;
        return travellingAllowance;
    }

    public Sales(int empId,String empName,int basicSalary){
        super(empId,empName,basicSalary);
    }


    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the employee id and empolyee name: ");
        int empId=sc.nextInt();
        String empName=sc.nextLine();

        System.out.println("Enter teh basic Salary: ");
        int basicSalary=sc.nextInt();

        Sales s=new Sales(empId,empName,basicSalary);

        System.out.println("The Empid of the employee is : "+s.empid);
        System.out.println("The total earning is: "+s.earnings()+s.tallowance());


    }
}
