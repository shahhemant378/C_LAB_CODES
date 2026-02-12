class Acc{
    int acc_no,balance;

    void input(int a,int b){
        this.acc_no=a;
        this.balance=b;
    }
    void display(){
        System.out.println("The account number is "+acc_no);
        System.out.println("The balance is: "+balance);
    }

   
    Acc(){

    }
}

class Person extends Acc{
    String name;
    int adharNO;

    Person(String name,int adharno,int acc,int bal){
        super.input(acc,bal);
        this.name=name;
        this.adharNO=adharno;
    }
    @Override
    void display(){
        System.out.println("The account number is "+acc_no);
        System.out.println("The balance is: "+balance);
         System.out.println("The name is: "+name);
          System.out.println("The adhar is: "+adharNO);
          System.out.println();
    }
}
public class Account {
    public static void main(String[] args) {
        Person p=new Person("Hemant", 9, 034343, 12323230);
        Person q=new Person("Hardik", 9830 ,034, 12323233);
        Person r=new Person("Rosish", 98303, 034346, 12323330);
        p.display();
        q.display();
        r.display();
    }
}
