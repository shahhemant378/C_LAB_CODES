//3)Write a class file - box with three data members(lenght, width, height) and a method volume(). Also implement the application class Demo where an object of the box class is created with user entered dimensions and volume is printed.
//Input: length,width and height.
//Output: Volume
import java.util.*;
class box{
    int length,width,height;

    public int volume(){
        return this.length * this.width * this.height;
    }

    public box(int a, int b, int c){
        this.length=a;
        this.width=b;
        this.height=c;
    }
}
public class classCreationbox {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        int length =sc.nextInt();
        int breadth=sc.nextInt();
        int height=sc.nextInt();
        
        box volume=new box(length,breadth,height);
        System.out.println(volume.volume());
    }

}
