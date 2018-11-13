
public class Fuel extends Goods {
	private boolean liquid;

	public Fuel(boolean liquid) {
		super("fuel", GoodsType.Dangerous);
		this.liquid = liquid;
	}

	public Fuel() {
		this(true);
	}

	public boolean isLiquid() {
		return liquid;
	}
}
