package product;

public class Motherboard extends Product{
	private String vRam;
	private static int pQuantity;
	
	public Motherboard(String pType,  String pBrand, String pModel, double pPrice, String  orderDate,String vRam,int pQuantity){
		super(pType, pBrand, pModel, pPrice, orderDate);
		this.vRam= vRam;
		this.pQuantity += pQuantity;
	}
	
	public String getVram() {
		return this.vRam;
	}

	public void showInfo() {
		System.out.println("\n\nOrder Details : ");
		System.out.println("Product Type : " + getType());
		System.out.println("Brand : " + getBrand());
		System.out.println("Model : " + getModel());
		System.out.println("Vram : " + getVram());
		if(pQuantity>100) {
			System.out.println("Product Quantity : 100");
			System.out.println("Total Price : " + (getPrice()*100));
		} 
		else {
			System.out.println("Product Quantity : "+ this.pQuantity);
			System.out.println("Total Price : " + (getPrice()*pQuantity));
		};	
		System.out.println("\n\n");
	}

}
