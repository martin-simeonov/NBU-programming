
public class FoodsShop extends Shop {

	public FoodsShop(int maxStock) {
		super(maxStock);
	}

	public void addFood(Food food) {
		super.addStock(food);
	}

}
