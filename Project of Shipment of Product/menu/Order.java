package menu;

import java.io.File;
import java.util.Scanner;

import product.DesiredProduct;
import product.Gpu;
import product.Motherboard;
import product.Ram;

public class Order {
	private Ram ram[] = new Ram[100];
	private Motherboard[] mobo = new Motherboard[100];
	private Gpu[] gpu = new Gpu[100];
	private DesiredProduct dProduct[] = new DesiredProduct[100];
	private double tBill;
	public Order(){
		
	}
	
	public void addRam(Ram r) {
		
		for(int i = 0; i<ram.length+1;i++) {
			if(ram[99] != null) {
				System.out.println("Maximum amount reached.Couldn't add product.\n");
				break;
			}
			else {
	
				if(ram[i] == null) {
					ram[i] = r;
					break;
				}
			}
			
		}
	}
	
	public void addGpu(Gpu g) {

		for(int i = 0; i<gpu.length;i++) {
			if(gpu[99] != null) {
				System.out.println("Maximum amount reached.Couldn't add product.\n");
				break;
			}
			else {
				if(gpu[i] == null) {
					gpu[i] = g;
					break;
				}
			}
			
		}
	}
	
	
	public void addMobo(Motherboard m) {

		for(int i = 0; i<mobo.length;i++) {
			if(gpu[99] != null) {
				System.out.println("Maximum amount reached.Couldn't add product.\n");
				break;
			}
			else {
		
				if(mobo[i] == null) {
					mobo[i] = m;
					break;
				}
			}
			
		}
	}
	
	
	
	public void addDesiredProduct(DesiredProduct dp) {
	
		for(int i = 0; i<dProduct.length;i++) {
			if(dProduct[99] != null) {
				System.out.println("Maximum amount reached.Couldn't add product.\n");
				break;
			}
			else {
		
				if(dProduct[i] == null) {
					dProduct[i] = dp;
					break;
				}
			}
			
		}
	}
	
	
	
	
	
	
	
	
	
public void removeProduct() {
		
		for(int i = 0; i<ram.length;i++) {
			if(ram[i] != null) {
				ram[i] = null;
			}
			if(gpu[i] != null) {
				gpu[i] = null;
			}
			if(mobo[i] != null) {
				mobo[i] = null;
			}
			if(dProduct[i] != null) {
				dProduct[i] = null;
			}
			
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	public double calculateBill() {
		tBill = 0;
		for(int i = 0; i<dProduct.length;i++) {
			if(dProduct[i] != null) {
				tBill += dProduct[i].getPrice();
			}
			if(mobo[i] != null) {
				tBill += mobo[i].getPrice();
			}
			if(ram[i] != null) {
				tBill += ram[i].getPrice();
			}
			if(gpu[i] != null) {
				tBill += gpu[i].getPrice();
			}
		}
		
		return tBill;
	}
	
	public void billPaid(int a) {
		tBill = a;
	}
	
	
	public void showStock() {
		if(ram[0] != null) {
			System.out.println("Product Type : "+ram[0].getType());
			System.out.println("Product Brand : "+ram[0].getBrand());
			System.out.println("Product Model : "+ram[0].getModel());
			System.out.println("Available in Stock\n");
		}
		else {
			System.out.println("Ram is currently out of stock !\n");
		}
		if(gpu[0] != null) {
			System.out.println("Product Type : "+gpu[0].getType());
			System.out.println("Product Brand : "+gpu[0].getBrand());
			System.out.println("Product Model : "+gpu[0].getModel());
			System.out.println("Available in Stock\n");
		}
		else {
			System.out.println("Gpu is currently out of stock !\n");
		}
		
		
		if(mobo[0] != null) {
			System.out.println("Product Type : "+mobo[0].getType());
			System.out.println("Product Brand : "+mobo[0].getBrand());
			System.out.println("Product Model : "+mobo[0].getModel());
			System.out.println("Available in Stock\n");
		}
		else {
			System.out.println("Motherboard is currently out of stock !\n");
		}
		
		
		if(dProduct[0] != null) {
			System.out.println("Product Type : "+dProduct[0].getType());
			System.out.println("Product Brand : "+dProduct[0].getBrand());
			System.out.println("Product Model : "+dProduct[0].getModel());
			System.out.println("Available in Stock\n");
		}
		else {
			System.out.println("No Extra Product is Available!\n");
		}
		
	}
	
	
	public void showOrder() {
		if(ram[0] != null) {
			ram[0].showInfo();
		}
		
		if(gpu[0] != null) {
			gpu[0].showInfo();
		}
		if(mobo[0] != null){
			mobo[0].showInfo();
		}
		if(dProduct[0] != null) {
			dProduct[0].showInfo();
		}
		else if(ram[0] == null && gpu[0] == null && mobo[0] == null && dProduct[0] == null){
			System.out.println("You haven't ordered anything yet ! \n\n");
		}
	}
	
}
