package product;

public abstract class Product implements productAttributes{
	private String pType;
	private String pBrand;
	private String pModel;
	private double pPrice;
	private String orderDate;
	

	public Product() {}
	
	public Product(String pType,  String pBrand, String pModel, double pPrice,String orderDate) {
		this.pType = pType;
		this.pBrand = pBrand;
		this.pModel = pModel;
		this.pPrice = pPrice;
		this.orderDate = orderDate;
	
	}
	public String getBrand() {
		return this.pBrand;
	}

	public double getPrice() {
		return this.pPrice;
	}
	
	public String getModel() {
		return this.pModel;
	}

	public String getType() {
		return this.pType;
	}

	public String getOrderDate() {
		return this.orderDate;
	}
	

	public abstract void showInfo();
	
	
	
}