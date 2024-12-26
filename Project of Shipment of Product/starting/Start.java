package starting;

import menu.Menu;
import menu.Order;
import product.DesiredProduct;
import product.Gpu;
import product.Motherboard;
import product.Paybill;
import product.Ram;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

import employee.login.Login;

public class Start {
	public static void main(String[] args) {
		
		Order order = new Order();
		int k = 0;
		Scanner sc = new Scanner(System.in);
		
		
		System.out.println("---------------------------------------------------------------------------------------------------------------------------------------");
		System.out.println("                                              WELCOME TO THE PRODUCT HANDLING SYSTEM                                                   ");
		
		
		//Loop for login attempts 
		for(int i = 0; i<1;) {
			System.out.println("---------------------------------------------------------------------------------------------------------------------------------------\n");
			
			System.out.println("                                                 Enter ID and Password to Login !                                                       ");
			
			System.out.print("                                                 ID : ");
			int id;
			try {
				id = Integer.parseInt(sc.nextLine());
			}catch(NumberFormatException ex) {
				System.out.println("Please use only digits in ID. Start Again!");
				continue;
			}
			
			
			
			System.out.print("                                                 Password : ");
			String pass = sc.nextLine();
			
			
			Login login = new Login(id,pass);
			
			if(login.checkIdPass() == 2) {
				System.out.println("                                                 Welcome to the System !\n");
				i = 1;
			}
			
			else if(login.checkIdPass() == 0) {
				System.out.println("                                                 Wrong ID. Please try again !\n");
		
			}
			
			else {
				System.out.println("                                                 Wrong Password. Please try again !\n");
				
			}
			
		}

		
		
		
		
		
	
		
		Menu menu = new Menu();
		int quantity = 0;
		String type = "";
		String brand = "";
		String model = "";
		double price = 0.0;
		DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		LocalDateTime now = LocalDateTime.now();  
		String date = dtf.format(now);

		while (k != 1) {
			menu.options();
			System.out.print("Please select one : ");
			int select ;
			try {
				select = Integer.parseInt(sc.nextLine());
			}catch(NumberFormatException ex) {
				System.out.println("Please use only the number given in front of the Options. Start Again.");
				continue;
			}
			
			
			if(select == 1) {
				System.out.println("\n1. Ram\n2. Gpu\n3. Motherboard\n4. Desired Product");
				System.out.print("Select one : ");
				int t;
				try{
					t = Integer.parseInt(sc.nextLine());
				}catch(NumberFormatException ex) {
					System.out.println("Please use only the number given in front of the Options. Start Again.");
					continue;
				}
				
				String ramSpeed = "";
				String gpuClockSpeed = "";
				String vRam = "";
				if(t == 1) {
					type = "Ram";
					System.out.println("\n1.Thermaltake\n2.Corsair");
					System.out.print("Select one : ");
					int b ;
					try{
						b = Integer.parseInt(sc.nextLine());
					}catch(NumberFormatException ex) {
						System.out.println("Please use only the number given in front of the Options. Start Again.");
						continue;
					}
					
					
					if(b == 1) {
						brand = "Thermaltake";
						model = "Toughram RGB";
						System.out.println("\n1.Bus : 2400mhz\n2.Bus : 3200mhz");
						System.out.print("Select one :");
						int s;
						try{
							s = Integer.parseInt(sc.nextLine());
						}catch(NumberFormatException ex) {
							System.out.println("Please use only the number given in front of the Options. Start Again.");
							continue;
						}
						
						if(s == 1) {
							ramSpeed = "2400mhz";
							price = 3500.0;
							System.out.print("Enter the quantity of the product : ");
							try{
								quantity = Integer.parseInt(sc.nextLine());
							}catch(NumberFormatException ex) {
								System.out.println("Please use only the number given in front of the Options. Start Again.");
								continue;
							}
							
							Ram ram = new Ram(type,brand,model,price,date,ramSpeed,quantity);
							for(int i = 0; i < quantity; i++) {
								order.addRam(ram);
							}
						
						}
						else {
							ramSpeed = "3200mhz";
							price = 4000.0;
							System.out.print("Enter the quantity of the product : ");
							try{
								quantity = Integer.parseInt(sc.nextLine());
							}catch(NumberFormatException ex) {
								System.out.println("Please use only the number given in front of the Options. Start Again.");
								continue;
							}
							
							Ram ram = new Ram(type,brand,model,price,date,ramSpeed,quantity);
							for(int i = 0; i < quantity; i++) {
								order.addRam(ram);
							}
						
						}
					}
					
					else {
						brand = "Corsair";
						model = "Vengeance Lpx";
						System.out.println("\n1.Bus : 2400mhz\n2.Bus : 3200mhz");
						System.out.print("Select one :");
						int s ;
						try{
							s = Integer.parseInt(sc.nextLine());
						}catch(NumberFormatException ex) {
							System.out.println("Please use only the number given in front of the Options. Start Again.");
							continue;
						}
						
						if(s == 1) {
							ramSpeed = "2400mhz";
							price = 3200.0;
							System.out.print("Enter the quantity of the product : ");
							try{
								quantity = Integer.parseInt(sc.nextLine());
							}catch(NumberFormatException ex) {
								System.out.println("Please use only the number given in front of the Options. Start Again.");
								continue;
							}
							
							Ram ram = new Ram(type,brand,model,price,date,ramSpeed,quantity);
							for(int i = 0; i < quantity; i++) {
								order.addRam(ram);
							}
						
						}
						else {
							ramSpeed = "3200mhz";
							price = 3800.0;
							System.out.print("Enter the quantity of the product : ");
							try{
								quantity = Integer.parseInt(sc.nextLine());
							}catch(NumberFormatException ex) {
								System.out.println("Please use only the number given in front of the Options. Start Again.");
								continue;
							}
							
							Ram ram = new Ram(type,brand,model,price,date,ramSpeed,quantity);
							for(int i = 0; i < quantity; i++) {
								order.addRam(ram);
							}
						
						}
					}
					
					
				}
				

				
				else if(t == 2) {
					type = "Gpu";
					System.out.println("\n1.MSI\n2.Gigabyte");
					System.out.print("Select one : ");
					int b;
					try{
						b = Integer.parseInt(sc.nextLine());
					}catch(NumberFormatException ex) {
						System.out.println("Please use only the number given in front of the Options. Start Again.");
					continue;
					}
					
					if(b == 1) {
						brand = "MSI";
						model = "Nvidia";
						System.out.println("\n1.1660\n2.3080");
						System.out.print("Select one :");
						int s;
						try{
							s = Integer.parseInt(sc.nextLine());
						}catch(NumberFormatException ex) {
							System.out.println("Please use only the number given in front of the Options. Start Again.");
							continue;
						}
						
						if(s == 1) {
							gpuClockSpeed = "1500mhz";
							price = 30000.0;
							System.out.print("Enter the quantity of the product : ");
							try{
								quantity = Integer.parseInt(sc.nextLine());
							}catch(NumberFormatException ex) {
								System.out.println("Please use only the number given in front of the Options. Start Again.");
								continue;
							}
							
							Gpu gpu = new Gpu(type,brand,model,price,date,gpuClockSpeed,quantity);
							for(int i = 0; i < quantity; i++) {
								order.addGpu(gpu);
							}
						
						}
						else {
							gpuClockSpeed = "2800mhz";
							price = 120000.0;
							System.out.print("Enter the quantity of the product : ");
							try{
								quantity = Integer.parseInt(sc.nextLine());
							}catch(NumberFormatException ex) {
								System.out.println("Please use only the number given in front of the Options. Start Again.");
								continue;
							}
							
							Gpu gpu = new Gpu(type,brand,model,price,date,gpuClockSpeed,quantity);
							for(int i = 0; i < quantity; i++) {
								order.addGpu(gpu);
							}
					
						}
					}
					
					else {
						brand = "Gigabyte";
						model = "Nvidia";
						System.out.println("\n1.1650 Super\n2.1080ti");
						System.out.print("Select one :");
						int s;
						try{
							s = Integer.parseInt(sc.nextLine());
						}catch(NumberFormatException ex) {
							System.out.println("Please use only the number given in front of the Options. Start Again.");
							continue;
						}
						
						if(s == 1) {
							gpuClockSpeed = "1500mhz";
							price = 25000.0;
							System.out.print("Enter the quantity of the product : ");
							try{
								quantity = Integer.parseInt(sc.nextLine());
							}catch(NumberFormatException ex) {
								System.out.println("Please use only the number given in front of the Options. Start Again.");
								continue;
							}
							
							Gpu gpu = new Gpu(type,brand,model,price,date,gpuClockSpeed,quantity);
							for(int i = 0; i < quantity; i++) {
								order.addGpu(gpu);
							}
						
						}
						else {
							gpuClockSpeed = "2200mhz";
							price = 60000.0;
							System.out.print("Enter the quantity of the product : ");
							try{
								quantity = Integer.parseInt(sc.nextLine());
							}catch(NumberFormatException ex) {
								System.out.println("Please use only the number given in front of the Options. Start Again.");
								continue;
							}
							
							Gpu gpu = new Gpu(type,brand,model,price,date,gpuClockSpeed,quantity);
							for(int i = 0; i < quantity; i++) {
								order.addGpu(gpu);
							}
						
						}
					}
					

				}
				else if(t == 3){
					type = "Motherboard";
					System.out.println("\n1.MSI\n2.Asus");
					System.out.print("Select one : ");
					int b;
					try{
						b = Integer.parseInt(sc.nextLine());
					}catch(NumberFormatException ex) {
						System.out.println("Please use only the number given in front of the Options. Start Again.");
						continue;
					}
					
					
					if(b == 1) {
						brand = "MSI";
						model = "Tomahawk Max";
						System.out.println("\n1.Vram : 2000mhz\n2.Vram : 1200mhz");
						System.out.print("Select one :");
						int s;
						try{
							s = Integer.parseInt(sc.nextLine());
						}
						catch(NumberFormatException ex) {
							System.out.println("Please use only the number given in front of the Options. Start Again.");
							continue;
						}
						
						if(s == 1) {
							vRam = "2000mhz";
							price = 12000.0;
							System.out.print("Enter the quantity of the product : ");
							try{
								quantity = Integer.parseInt(sc.nextLine());
							}catch(NumberFormatException ex) {
								System.out.println("Please use only the number given in front of the Options. Start Again.");
								continue;
							}
							
							Motherboard mobo = new Motherboard(type,brand,model,price,date,gpuClockSpeed,quantity);
							for(int i = 0; i < quantity; i++) {
								order.addMobo(mobo);
							}
						
						}
						else {
							vRam = "1200mhz";
							price = 18000.0;
							
							System.out.println("Enter the amount the quantity you want to order : ");
							try {
								quantity = Integer.parseInt(sc.nextLine());
							}catch(NumberFormatException ex) {
								System.out.println("Please use only the number given in front of the Options. Start Again.");
								continue;
							}
							
							Motherboard mobo = new Motherboard(type,brand,model,price,date, gpuClockSpeed,quantity);
							for(int i = 0; i < quantity; i++) {
								order.addMobo(mobo);
							}
						
						}
					}
					
					else {
						brand = "Gigabyte";
						model = "Gaming Plus";
						System.out.println("\n1.Vram : 3000mhz\n2.Vram : 15000mhz");
						System.out.print("Select one :");
						int s; 
						try{
							s = Integer.parseInt(sc.nextLine());
						}catch(NumberFormatException ex) {
							System.out.println("Please use only the number given in front of the Options. Start Again.");
							continue;
						}
						
						if(s == 1) {
							gpuClockSpeed = "3000mhz";
							price = 19000.0;
							System.out.print("Enter the quantity of the product : ");
							try{
								quantity = Integer.parseInt(sc.nextLine());
							}catch(NumberFormatException ex) {
								System.out.println("Please use only the number given in front of the Options. Start Again.");
								continue;
							}
							
							Motherboard mobo = new Motherboard(type,brand,model,price,date,gpuClockSpeed,quantity);
							for(int i = 0; i < quantity; i++) {
								order.addMobo(mobo);
							}
						
						}
						else {
							gpuClockSpeed = "1500mhz";
							price = 13000.0;
							System.out.print("Enter the quantity of the product : ");
							try{
								quantity = Integer.parseInt(sc.nextLine());
							}catch(NumberFormatException ex) {
								System.out.println("Please use only the number given in front of the Options. Start Again.");
								continue;
							}
							
							Motherboard mobo = new Motherboard(type,brand,model,price,date,gpuClockSpeed,quantity);
							for(int i = 0; i < quantity; i++) {
								order.addMobo(mobo);
							}
						
						}
					}
					
					System.out.println("\n\n");

				}
				
				
			
				else if(t == 4) {
					
					String nAttribute = "";
					String value = "";
					System.out.print("Enter the type of the product : ");
					type = sc.nextLine();
					System.out.print("Enter the Brand of the product : ");
					brand = sc.nextLine();
					System.out.print("Enter the model of the product : ");
					model = sc.nextLine();
					System.out.print("Enter the price of the product : ");
					price = Integer.parseInt(sc.nextLine());
					System.out.print("Enter a necessary attribute of the product : ");
					nAttribute = sc.nextLine();
					System.out.print("Enter the value of the attribute : ");
					value = sc.nextLine();
					System.out.print("Enter the quantity you want to order : ");
					quantity = Integer.parseInt(sc.nextLine());
					DesiredProduct dproduct = new DesiredProduct(type,brand,model,price,date,nAttribute,value,quantity);
					for(int i = 0; i < quantity; i++) {
						order.addDesiredProduct(dproduct);
					}
				}

				else {
					System.out.println("Wrong Input ! Try Again\n");
					continue;
				}
				
			}
			
			
			else if(select == 2) {
				order.showOrder();
			
			}
			
			else if(select == 3) {
				Paybill pb = new Paybill();
				System.out.println("The total bill is : "+ order.calculateBill());
				if(pb.payBill()==1) {
					System.out.println("Bill has been paid");
					order.billPaid(0);
				}
			}
			
			else if(select == 4) {
				System.out.println("Do you want to distribute the current stock ? ");
				System.out.println("1.Yes\n2.No");
				System.out.print("Select one option : ");
				int e;
				try{
					e = Integer.parseInt(sc.nextLine());
				}catch(NumberFormatException ex) {
					System.out.println("Please use only the number given in front of the Options. Start Again.");
					continue;
				}
				
				
				if(e == 1) {
					order.removeProduct();
					System.out.println("All products in stock has been distributed ! ");
				}
			}
			
			else if(select == 5) {
				order.showStock();			}
			
			else if(select == 6){
				System.out.println("Logging you out !");
				k = 1;
			}
			
			else {
				System.out.println("Wrong input ! ");
			}
			
		}
		
	}
	
}
