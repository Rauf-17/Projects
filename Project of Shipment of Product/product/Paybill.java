package product;

import java.util.Scanner;

import menu.Order;

public class Paybill extends Order{
	
	
	public Paybill(){
		
	}
	

	
	public int payBill() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Do you want to pay the bill now? ");
		System.out.println("1.Yes\n2.No");
		System.out.print("Select one option : ");
		int  a = Integer.parseInt(sc.nextLine());
		return a;
		
	}
}
