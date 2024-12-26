package product;

public class Gpu extends Product{
	private String memory;
	private static int pQuantity;
	
	public Gpu(String pType,  String pBrand, String pModel, double pPrice, String orderDate, String memory,int pQuantity){
		super(pType, pBrand, pModel, pPrice, orderDate);
		this.memory = memory;
		this.pQuantity += pQuantity;
	}
	
	public String getMemory() {
		return this.memory;
	}

	public void showInfo() {
		System.out.println("\n\nOrder Details : ");
		System.out.println("Product Type : " + getType());
		System.out.println("Brand : " + getBrand());
		System.out.println("Model : " + getModel());
		System.out.println("Memory : " + getMemory());
		if(pQuantity>100) {
			System.out.println("Product Quantity : 100");
			System.out.println("Total Price : " + (getPrice()*100));
		} 
		else {
			System.out.println("Product Quantity : "+ pQuantity);
			System.out.println("Total Price : " + (getPrice()*pQuantity));
		}
		
		System.out.println("\n\n");
		
		
	}

}
