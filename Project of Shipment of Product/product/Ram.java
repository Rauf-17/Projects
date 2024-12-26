package product;

public class Ram extends Product{
	private String bus;
	private static int pQuantity;
	
	public Ram(String pType,  String pBrand, String pModel, double pPrice, String orderDate, String bus,int pQuantity){
		super(pType, pBrand, pModel, pPrice, orderDate);
		this.bus = bus;
		this.pQuantity += pQuantity;
	}
	
	public String getBus() {
		return this.bus;
	}
	
	public void showInfo() {
		System.out.println("\n\nOrder Details : ");
		System.out.println("Product Type : " + getType());
		System.out.println("Brand : " + getBrand());
		System.out.println("Model : " + getModel());
		System.out.println("Bus Speed : " + getBus());
		if(pQuantity>100) {
			System.out.println("Product Quantity : 100");
			System.out.println("Total Price : " + (getPrice()*100));
		} 
		else {
			System.out.println("Product Quantity : "+ pQuantity);
			System.out.println("Total Price : " + (getPrice()*pQuantity));
		}
		System.out.println("Order Date : "+getOrderDate());
		System.out.println("\n\n");
		
	}

	
}
