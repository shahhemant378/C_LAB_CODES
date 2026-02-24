

import java.util.Scanner;

public class Test {
    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	try{
		int arr[]=new int[3];
		arr[5]=sc.nextInt();

	}catch(ArithmeticException e){
		System.out.println(e);
	}catch(ArrayIndexOutOfBoundsException e){
		System.out.print(e);
	}catch(Exception e){
		System.out.println(e);
	}
}
}
