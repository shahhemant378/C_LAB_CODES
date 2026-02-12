//3. Aim of the program : Write a program in Java having three classes Apple,
// Banana and Cherry. Class Banana and Cherry are inherited from class Apple
// and each class have their own member function show() . Using Dynamic Method
// Dispatch concept display all the show() method of each class.
// Input: Mention show function of each class.
// Output: Display show function of each class accordingly.
class Apple{
void show(){
System.out.println("This is Apple show method");
}
}
class Banana extends Apple{
void show(){
System.out.println("This is banana show method");    
}
}
class Cherry extends Apple{
void show(){
    System.out.println("This is cherry class show method");
}
}
public class showFunction {
    public static void main(String[] args) {
        Apple ref;   //Dynamic Method Dispatch means:

// A parent class reference is used to call child class methods, and
// the method call is decided at runtime, not compile time.
        ref=new Apple();
        ref.show();

        ref=new Banana();
        ref.show();

        ref=new Cherry();
        ref.show();
    }
}
