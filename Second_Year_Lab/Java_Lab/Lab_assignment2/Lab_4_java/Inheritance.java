import java.util.Scanner;
class plate{
    int length,width;
    plate(int l,int w){
        this.length=l;
        this.width=w;
       System.out.println("Plate Dimensions:");
        System.out.println("Length = " + length);
        System.out.println("Width = " + width);
    }
}
class Box extends plate{
int height;
Box(int l,int w,int h){
    super(l,w);
    this.height=h;
   System.out.println("Box Height = " + height);
}
}
class woodBox extends Box{
    int thick;
    woodBox(int l,int w,int h,int t){
        super(l, w, h);
        this.thick=t;
          System.out.println("WoodBox Thickness = " + thick);
    }
}
public class Inheritance {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        int length=sc.nextInt();
        int breadth=sc.nextInt();
        int height=sc.nextInt();
        int thick=sc.nextInt();

        plate p=new woodBox(length, breadth, height, thick);

    }
}
