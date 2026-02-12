// package C_LAB_CODES.Second_Year_Lab.javaPackageTrail;
// import C_LAB_CODES.Second_Year_Lab.java_Practice.practice;

// public class hell {
//    public static void main(String[] args) {
//     practice obj=new practice();
//     obj.show();
//    } 
// }


//Instance inner class
// class Outer{
//     int x=10;

//     class Inner{
//         void display(){
//             System.out.println("Value of X: "+x);
//         }
//     }
// }

// public class hell{
// public static void main(String[] args) {
//     Outer o=new Outer();
//     Outer.Inner i=o.new Inner();
//     i.display();
// }
// }

// class Outer{
//     static int x=20;

//     static class inner{
//         void show(){
//             System.out.println("Value of X: "+x);
//         }
//     }
// }

// public class hell{
//     public static void main(String[] args) {
//         Outer.inner obj=new Outer.inner();
//         obj.show();
//     }
// }


// class Outer{
//     void message(){
//         int y=30;

//         class Inner{
//             void show(){
//                 System.out.println(y);
//             }
//         }
//         Inner i=new Inner();
//         i.show();
//     }
// }

// public class hell{
//     public static void main(String[] args) {
//         Outer o=new Outer();
//         o.message();
//     }
// }

//Anonymous Inner Class

// abstract class A{
//     abstract void show();
// }

// public class hell{
//     public static void main(String[] args) {
//         A obj=new A(){
//             void show(){
//             System.out.println("Anonymous Inner class");
//         }
//     };
//         obj.show();
//     }
// }

