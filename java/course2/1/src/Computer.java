
public class Computer extends Goods {
	private boolean portable;

	public Computer(boolean portable) {
		super("computer", GoodsType.Standard);
		this.portable = portable;
	}

	public Computer() {
		this(false);
	}

	public boolean isPortable() {
		return portable;
	}
}
