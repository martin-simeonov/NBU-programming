
public class Meat extends Goods {
	private boolean frozen;

	public Meat(boolean frozen) {
		super("meat", GoodsType.Refrigerated);
		this.frozen = frozen;
	}

	public Meat() {
		this(true);
	}

	public boolean isFrozen() {
		return frozen;
	}
}
