
public class JewelryShop extends Shop {

	public JewelryShop(int maxStock) {
		super(maxStock);
	}

	public void addJewel(Jewel jewel) {
		super.addStock(jewel);
	}

}
