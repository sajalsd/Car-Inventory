package tarek;

import java.util.Scanner;
import java.util.Vector;

public class Main {
	public static void display() {
		System.out.println("Enter your choice..");
		System.out.println("Type add to add a car in list.");
		System.out.println("Type list to view the list of car.");
		System.out.println("Type quit to close the program.");

	}

	public static void main(String[] args) {

		Vector<Car> v = new Vector<Car>();
		Double total[] = new Double[999];
		int i = 0;
		for (;;) {
			display();
			Scanner sc = new Scanner(System.in);
			String input = sc.nextLine().toLowerCase();
			switch (input) {
			case "add":
				System.out.println("Enter Make By_ ");
				String makeBy = sc.nextLine();
				System.out.println("Enter Make year_ ");
				String makeYear = sc.nextLine();
				System.out.println("Enter Model_ ");
				String modelName = sc.nextLine();
				System.out.println("Enter Price_ ");
				Double carPrice = sc.nextDouble();
				total[i] = carPrice;
				i++;
				v.addElement(new Car(makeBy, makeYear, modelName, carPrice));
				break;
			case "list":
				boolean b = v.isEmpty();
				if (b) {
					System.out.println("Nothing has added");
				} else {
					System.out.println("MODEL---MAKE---YEAR----PRICE");
					for (int j = 0; j < v.size(); j++) {
						System.out.println(v.elementAt(j));
					}
					Double sum = 0.0;
					for (int k = 0; k < i; k++)
						sum = sum + total[k];
					System.out.println("Total Cost=" + sum);

				}
				break;
			case "quit":
				System.out.println("Thank You!!!!");
				break;
			default:
				System.out
						.println("Please type the right choice from the menu");

			}
		}

	}

}
