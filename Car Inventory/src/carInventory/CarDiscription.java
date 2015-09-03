package carInventory;

import java.util.Scanner;

public class CarDiscription 
{
	public static String tempModel;
	public static String tempMake;
	public static String tempYear;
	public static Double tempPrice;
	
	public static void discription()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Make year: ");
		tempYear = sc.nextLine();
		System.out.println("Enter Model : ");
		tempModel = sc.nextLine();
		System.out.println("Enter Make By : ");
		tempMake = sc.nextLine();
		System.out.println("Enter Price($): ");
		tempPrice = sc.nextDouble();
		sc.close();
	}
	
	

}
