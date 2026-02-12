//2) Program to find no of objects creation out of a class using 'static modifier'
//Input: No of objects created
//Output: Display the number of objects created (eg no of objects =3)
class Ob{
    static int Obj=0;
    public Ob(){
        Obj++;
    }
}
public class Obcreation {
    public static void main(String[] args) {
        Ob a=new Ob();
        Ob b=new Ob();
        Ob c=new Ob();


        System.out.println(Ob.Obj);
    }
}
