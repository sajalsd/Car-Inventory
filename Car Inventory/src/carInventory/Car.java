package carInventory;

public class Car {
	private String make;
	private String year;
	private String model;
	private Double price;
	
	public Car(String make, String year, String model, Double price) 
	{
		this.make = make;
		this.year = year;
		this.model = model;
		this.price = price;
	}

	public Car() {
		
	}

	public String getMake()
	{
		return make;
	}

	public void setMake(String make)
	{
		this.make = make;
	}

	public String getYear()
	{
		return year;
	}

	public void setYear(String year)
	{
		this.year = year;
	}


	public String getModel()
	{
		return model;
	}

	public void setModel(String model) 
	{
		this.model = model;
	}

	public Double getPrice()
	{
		return price;
	}

	public void setPrice(Double price) 
	{
		this.price = price;
	}

	
	public String toString() {
		return  model+"\t"+ make+"\t"+year+"\t\t" + price ;
	}

	
	
	
	

}
