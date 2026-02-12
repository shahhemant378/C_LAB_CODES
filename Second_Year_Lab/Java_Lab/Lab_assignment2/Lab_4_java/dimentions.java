//1) A plastic manufacturer sells plastic in different shapes
//like 2D sheet and 3D box.The cost of sheet is Rs 40/ per square ft. and the
// cost of box is Rs 60/ per cubic ft. Implement it in java to calculate the cost of plastic as per 
//the dimensions given by the user where 3D inherits from 
import java.util.Scanner;
class TwoD{
    final int costSqrFt=40;
    
    int length;
    int breadth;

    // TwoD(){
    //     System.out.println("hi, i am in super class");
    // }

    int calculateCost(){
        return length*breadth * costSqrFt;
    }
    TwoD(int l,int b){
        this.length=l;
        this.breadth=b;
    }
}
class ThreeD extends TwoD{
    final int costCubicFt=60;
    int height;

    public ThreeD(int l,int b, int h){
        super(l,b);
        this.height=h;
    }

    int calculateCost(){
        return  length*breadth*height *costCubicFt;
    }
}
public class dimentions {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the length and breadth");
        int length=sc.nextInt();
        int breadth=sc.nextInt();
        int height=sc.nextInt();

        TwoD sqr=new TwoD(length, breadth);
        System.out.println("The Cost is : " +sqr.calculateCost());

        ThreeD cub=new ThreeD(length, breadth, height);
        System.out.println("The Cost is : "+cub.calculateCost());

        
        


    }    
}
