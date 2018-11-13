import java.io.Serializable;

public class Invoice implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	private int number;
	private Company provider;
	private Company recipient;
	private String date;
	private Goods goods;
	private int goodsCount;
	
	public Invoice(int number, Company provider, Company recipient, String date,
			Goods goods, int goodsCount) {
		this.number = number;
		this.provider = provider;
		this.recipient = recipient;
		this.date = date;
		this.goods = goods;
		this.goodsCount = goodsCount;
	}
	
	public void print() {
		System.out.println("Invoice number: " + number);
		System.out.println("Provider:" + provider.getName());
		System.out.println("Recipient:" + recipient.getName());
		System.out.println("Date:" + date);
		System.out.println("Goods:" + goods.getName());
		System.out.println("Goods count:" + goodsCount);
		System.out.println("Invoice value:" + getValue());
	}
	
	public double getValue() {
		return goodsCount * goods.getPrice();
	}
	
	public int getNumber() {
		return number;
	}

	public void setNumber(int number) {
		this.number = number;
	}

	public Company getProvider() {
		return provider;
	}

	public void setProvider(Company provider) {
		this.provider = provider;
	}

	public Company getRecipient() {
		return recipient;
	}

	public void setRecipient(Company recipient) {
		this.recipient = recipient;
	}

	public String getDate() {
		return date;
	}

	public void setDate(String date) {
		this.date = date;
	}

	public Goods getGoods() {
		return goods;
	}

	public void setGoods(Goods goods) {
		this.goods = goods;
	}

	public int getGoodsCount() {
		return goodsCount;
	}

	public void setGoodsCount(int goodsCount) {
		this.goodsCount = goodsCount;
	}
	
}
