package product;

public class DesiredProduct extends Product{

	private String additionalAttribute;
	private String attributeValue;
	private int pQuantity;
	
	public DesiredProduct(String pType, String pBrand, String pModel, double pPrice, String orderDate, String additionalAttribute, String attributeValue,int pQuantity) {
		super(pType, pBrand, pModel, pPrice, orderDate);
		
		this.additionalAttribute = additionalAttribute; 
		this.attributeValue = attributeValue;
		this.pQuantity = pQuantity;
		
	}

	public String getAttribute() {
		return this.additionalAttribute;
	}
	
	public String getValue() {
		return this.attributeValue;
	}
	public void showInfo() {
		System.out.println("\n\nOrder Details : ");
		System.out.println("Product Type : " + getType());
		System.out.println("Brand : " + getBrand());
		System.out.println("Model : " + getModel());
		System.out.println(getAttribute()+" : "+getValue());
		if(pQuantity>100) {
			System.out.println("Product Quantity : 100");
		} 
		else {
			System.out.println("Product Quantity : "+pQuantity);
		}
		System.out.println("Total Price : " + (getPrice()*pQuantity));
		System.out.println("Order Date : "+getOrderDate());
		System.out.println("\n\n");
		
	}
	
}
