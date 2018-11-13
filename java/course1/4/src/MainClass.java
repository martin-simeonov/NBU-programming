
public class MainClass {

	public static void main(String args[]) {
		FoodsShop foodShop = new FoodsShop(2);
		foodShop.addFood(new Food("cheese", 1, 20, 4));
		foodShop.addFood(new Food("milk", 1, 20, 6));
		foodShop.addFood(new Food("beer", 2, 10, 10));
		foodShop.print();

		JewelryShop jewelryShop = new JewelryShop(3);
		jewelryShop.addJewel(new Jewel("necklace", 100, 30, false));
		jewelryShop.addJewel(new Jewel("ring", 80, 20, true));
		jewelryShop.print();
	}

}
