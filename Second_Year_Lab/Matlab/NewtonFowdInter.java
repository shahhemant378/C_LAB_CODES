package C_LAB_CODES.Second_Year_Lab.Matlab;
import java.util.Scanner;
public class NewtonFowdInter {

    public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    System.out.println("Enter the size: ");
        int n=sc.nextInt(); 
    int[] x=new int[n];
    int[] f1=new int[n];

    System.out.println("Enter the x array: ");

    for(int i=0;i<n;i++){
        x[i]=sc.nextInt();
    }
    for(int i=0;i)
    int x[]={0,1,2,3,4};
    int f1[]={1,7,23,55,109};

    int n=x.length;

    int[][] A=new int[n][n];

    for(int j=2;j<n;i++){
        for(int i=1;i<n-j+1;i++){
            A[i][j]=A[i+1][j-1]-A[i][j-1];
        }
    }
    

}
}
