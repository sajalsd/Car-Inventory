package carInventory;

import java.util.Scanner;
import java.util.Vector;

public class Main {
	
	public final static String ADD = "add";
	public final static String LIST = "list";
	public final static String EXIT = "exit";
	
	public static void displayMenu()
	{
		System.out.println("\n\nChoose from menu");
		System.out.println("Type............");
		System.out.println("add  : To Add a car in list.");
		System.out.println("list : To view the list of car.");
		System.out.println("exit : To close the program.");
		
	}
	
	public static void main(String[] args)
	{
		
		Vector<Car> v = new Vector<Car>();
		Double total[] = new Double[100];
		int j=0;
		LOOP1: for(;;)
		{
			displayMenu();
			Scanner sc = new Scanner(System.in);
			String input = sc.nextLine();
			boolean x = input.equalsIgnoreCase(ADD);
			boolean y = input.equalsIgnoreCase(LIST);
			boolean z = input.equalsIgnoreCase(EXIT);
			if(x)
			{
				
				System.out.println("Enter Make year: ");
				String tempYear = sc.nextLine();
				System.out.println("Enter Model : ");
				String tempModel = sc.nextLine();
				System.out.println("Enter Make By : ");
				String tempMake = sc.nextLine();
				System.out.println("Enter Price($): ");
				Double tempPrice = sc.nextDouble();
				
				total[j] = tempPrice;
				j++;
				
					
				v.addElement(new Car(tempMake,tempYear,tempModel,tempPrice));
				continue LOOP1;
			}
			else if(y)
			{
				boolean b = v.isEmpty();
				if(b)
				{
					System.out.println("The List is Empty!!!");
					continue LOOP1;
				}
				else
				{
					System.out.println("MODEL\tMAKE\tYEAR\t\tPRICE");
					System.out.println("========================================");
					for(int i=0; i<v.size(); i++)
					{
						System.out.println(v.elementAt(i));
					}
					Double sum= 0.0;
					for(int k=0; k<j; k++)
						sum = sum + total[k];
					System.out.println("========================================");
					System.out.println("TOTAL INVENTORY.................$"+sum);
					continue LOOP1;
				}		
			
			}
			else if(z)
			{
				System.out.println("Thank You!!!!");
				break LOOP1;
			}
			else
				continue LOOP1;
		}
		
		
		
		
	}

}
